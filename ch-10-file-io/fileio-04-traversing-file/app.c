#include <stdio.h>

void main(void)
{
  FILE *fp;
  int value;

  fp = fopen("/home/anuj/local_repos/docs/data/info.txt", "rb");

  if (fp)
  {
    fseek(fp, 10, SEEK_CUR);

    while (1)
    {
      value = fgetc(fp);

      if (value == EOF) break;
      else printf("%c\n", value);
    }

    fclose(fp);
  }
}

