#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int attempts = 0;
char actual[50];

void login() {
  fgets(actual, 50, fopen("flag.txt", "r"));
  actual[strcspn(actual, "\n")] = 0;

  while (attempts < 3) {
    char password[30];
    printf(">>> ");
    fgets(password, 0x80, stdin);
    password[strcspn(password, "\n")] = 0;
    
    int pwdlength = strlen(password);
    if (pwdlength != strlen(actual)) {
      puts("Incorrect password.");
      attempts++;
      continue;
    }
  
    for (int i = 0; i < pwdlength; i++) {
      if (password[i] != actual[i]) {
        puts("Incorrect password.");
        attempts++;
        continue;
      }
    }
    system("/bin/sh");
    break;
  }
}

int main() {
  puts("Login Attempt\n----------------\nBinary: https://ctf.ret-to.win/files/5b8c4811ac2ba927b05288afc640122c/login_attempt\n------------------------------------------------------------------------------------------\n");
  puts("Little bunny Foo Foo found a computer belonging to an aviator. She thinks it contains the location of a super duper treasure.");
  puts("Help her get in to the computer!");
  login();
  return 0;
}