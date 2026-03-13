#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

char flag[60];
int key;

void gadget() {
  asm volatile (
    "pop %rdi\n"
    "ret"
  );
}

void encrypt() {
  int len = strlen(flag);
  for (int i = 0; i < len; i++) {
    flag[i] = flag[i] ^ key;
    key++;
  }
}

int main() {
  srand(time(NULL));
  
  char buf[24];
  key = (rand() % 0x28) + 1;

  fgets(flag, 60, fopen("flag.txt", "r"));
  encrypt();

  puts("Leaking Secrets\n------------------\nBinary: https://ctf.ret-to.win/files/169d5f4816c77cdfb737e3fabe58c295/leaking_secrets\n--------------------------------------------------------------------------------------------\n");
  puts("Little Bunny Foo Foo has been feeling down lately. She feels that Big Rabbit Bar Bar has been hiding something from her.");
  puts("While he's out of the den, Little Bunny Foo Foo wants to access his vault.");
  puts("See if you can help find the password for her.");
  printf(">>> ");
  fgets(buf, 0x100, stdin);
  return 0;
}