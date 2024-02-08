#include <stdio.h>

void main(void)
{
  FILE *fp;
  fp = fopen("/home/anuj/local_repos/docs/data/info.txt", "wb");

  if (fp)
  {
    fprintf(fp, "This is some text\n");
    fclose(fp);
  }
}

