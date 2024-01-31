#include <stdio.h>

void main(void)
{
  unsigned int a = 0;

  switch (a)
  {
    case 0:
      printf("a is equal to 0.\n");
      break;
    case 1:
      printf("a is equal to 1.\n");
      break;
    default:
      printf("a is greater than 1.\n");
  }

  // leaving loop early
  while (1)
  {
    printf("a is equal to %d.\n", a);
    a++;
    if (a == 5) break;
  }

  printf("a is equal to %d and I am done.\n", a);
}

