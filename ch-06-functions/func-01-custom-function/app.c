#include <stdio.h>

int sum(int a, int b)
{
  int result;

  result = a + b;

  return result;
}

void main(void)
{
  int x = 5;
  int y = 2;
  int z = sum(x, y);

  printf("The sum of %d and %d is %d.\n", x, y, z);
}

