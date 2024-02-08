#include <stdio.h>

void main(void)
{
  FILE *fp;
  int value;

  fp = fopen("/home/anuj/local_repos/docs/data/info.txt", "wb");

  if (fp)
  {
    for (value = 48; value < 58; value++)
    {
      fputc(value, fp);
    }

    fclose(fp);
  }
}

