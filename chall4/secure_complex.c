#include <stdio.h>
#include <unistd.h>
#include <string.h>

char* aGF2ZXlvdXRyaWVkcHV0cz8= "SWhlYXJkdGhlR09UaXNjb29s";

void gadget() {
  asm volatile(
    "pop %rdi\n"
    "ret"
  );
}

int main() {
  char plan[0x30];

  puts("Secure Complex\n-----------------\nBinary: https://ctf.ret-to.win/files/59901af77a18c9f5f93064bf2236b9b9/secure_complex\nLIBC Version: https://ctf.ret-to.win/files/59901af77a18c9f5f93064bf2236b9b9/libc.so.6\n--------------------------------------------------------------------------------------------\n");
  puts("Little bunny Foo Foo has one last grand mission to execute. She must raid Avi HN and recover the Cadbury chocolate bunny!");
  puts("However, the facility is heavily secure. Think you can find a way in?");
  printf("Little bunny Foo Foo brought a tool, 0x%llx. Maybe it can be useful?\n", &aGF2ZXlvdXRyaWVkcHV0cz8);
  printf(">>> ");
  fgets(plan, 0x80, stdin);
  return 0;
}
