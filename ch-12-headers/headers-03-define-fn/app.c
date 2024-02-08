#include <stdio.h>

#define ADD(a, b) (a + b)

void main(void)
{
  printf("The sum of %d and %d is %d.\n", 5, 2, ADD(5, 2));
  printf("The sum of %d and %d is %d.\n", 3, 7, ADD(3, 7));
}

