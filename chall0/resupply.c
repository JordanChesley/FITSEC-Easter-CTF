#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* brian = "w3_h4";
char* lois = "t3_r0";
char* stewart = "d3nt5";

void gadget1() {
  asm volatile (
    "mov %rax, %rdi\n"
    "ret"
  );
}

void gadget2() {
  asm volatile (
    "pop %rdx\n"
    "pop %rdi\n"
    "pop %rsi\n"
    "ret"
  );
}

char* code(char* piece1, char* piece2, char* piece3) {
  int combinedLen = strlen(piece1) + strlen(piece2) + strlen(piece3) + 1;
  char* combined = (char*)malloc(combinedLen * sizeof(char));
  if (combined == NULL) return '\0';

  strcpy(combined, piece1);
  strcat(combined, piece2);
  strcat(combined, piece3);
  return combined;
}

void win(char* code) {
  // TODO: Adjust for actual partial flag size.
  char flag[50];
  fgets(flag, 50, fopen("flag.txt", "r"));

  int sum = 0;
  while (*code != '\0') {
    sum += (int)(*code);
    code++;
  }

  if (sum != 1275) {
    puts("Oh no! Little bunny Foo Foo entered the wrong code! The aviators were alerted and ate her!");
    return;
  }
  puts("Little bunny Foo Foo is in! Great work!");
  puts(flag);
  exit(1);
}

int main() {
  char help[0x20];

  puts("Resupply\n-----------\nBinary: https://ctf.ret-to.win/files/90d305c90e856888769ff9f201687da8/resupply\n-------------------------------------------------------------------------------------\n");
  puts("Little bunny Foo Foo is getting ready for an awesome Easter, however she is out of eggs!");
  puts("She needs your help to raid the local aviary to get enough eggs to make Easter awesome!");
  printf(">>> ");
  fgets(help, 0x80, stdin);
  return 0;
}