#include <stdio.h>

int sum_and_diff(int a, int b, int *res)
{
  int sum;

  sum = a + b;
  *res = a - b; // difference

  return sum;
}
void main(void)
{
  int b = 2;
  int diff;

  printf("the sum of 5 and %d is %d.\n", b, sum_and_diff(5, b, &diff));
  printf("the difference of 5 and %d is %d.\n", b, diff);
}

