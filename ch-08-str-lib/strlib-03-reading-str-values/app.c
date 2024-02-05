#include <stdio.h>

void read_str_val(void)
{
  int val;
  char string[10] = "250";

  sscanf(string, "%d", &val);
  printf("The value in the string is %d.\n", val);
}

void multiple_format_specifier(void)
{
  int val;
  char result[10];
  char string[25] = "the first number is 1.";

  if (sscanf(string, "The %s string is %d", result, &val) == 2)
  {
    printf("String: %s Value: %d\n", result, val);
  }
  else
  {
    printf("I couldn't find two values in that string.\n");
  }
}

void main(void)
{
  read_str_val();
  multiple_format_specifier();
}

