#include <stdio.h>
#include <unistd.h>
#include <string.h>

void eliminateDrone() {
  char flag[41];
  fgets(flag, 41, fopen("flag.txt", "r"));
  puts("Using PETA-aligned methods, the pest was dealt with. Now Little bunny Foo Foo can hide her eggs in peace!");
  puts(flag);
}

void menu() {
  while (1) {
    int selection;
    puts("1. Search for aviator");
    puts("2. Deal with aviator");
    printf("Select option >>> ");
    scanf("%d", &selection);
    getchar();
    char query[10];
    switch (selection) {
      case 1:
        printf("\nEnter query >>> ");
        fgets(query, 10, stdin);
        printf(query);
        puts("");
        break;
      case 2:
        printf("\n>>> ");
        fgets(query, 0x30, stdin);
        return;
    }
  }
}

int main() {
  puts("Suveillance Drone\n--------------------\nBinary: https://ctf.ret-to.win/files/92543dedc04149a9c971a4c006d95fe5/surveillance_drone\n-----------------------------------------------------------------------------------------------\n");
  puts("Little bunny Foo Foo is trying to hide eggs around town for Easter, however an invisible aviator is pestering her!");
  puts("Find the spy and take it down!");
  menu();
  return 0;
}