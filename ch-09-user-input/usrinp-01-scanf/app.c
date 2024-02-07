#include <stdio.h>

void main(void)
{
  char input[256];
  int age;

  printf("What is your name?\n");
  scanf("%s", input);

  printf("Hello, %s. How old are you?\n", input);
  scanf("%d", &age);

  printf("Well, %s, you look young for %d...\n", input, age);
}

