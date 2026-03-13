#include <stdio.h>
#include <unistd.h>
#include <string.h>

char pieces[10];
int pieceIndex = 0;

void gadget() {
  asm volatile (
    "pop %rdi\n"
    "ret"
  );
}

void rebuild() {
  puts("Let's hope this works...");
  execve(pieces, 0, 0);
}

void addPiece(char* piece) {
  if (pieceIndex > 9) {
    puts("Cannot carry any more pieces.");
    return;
  }

  pieces[pieceIndex] = piece[0];
  if (pieceIndex < 10) {
    pieceIndex++;
  }
}

int main() {
  char buf[0x20];

  puts("Broken Shell\n---------------\nBinary: https://ctf.ret-to.win/files/0632dbfe5c53112d02b58ea6712d9904/broken_shell\n-----------------------------------------------------------------------------------------\n");
  puts("Oh the misery! Little bunny Foo Foo has accidentally dropped an egg!");
  puts("She needs your help recovering the pieces of shell to put the egg back together!");
  printf(">>> ");
  fgets(buf, 0x100, stdin);
  return 0;
}