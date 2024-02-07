#include <stdio.h>

void main(void) {
  FILE *fp;
  int value;

  fp = fopen("D:\\anuj\\learning\\docs\\clang\\cs_demos_2024\\ch-10-file-"
             "io\\fileio-01-read-file",
             "fb");

  if (fp) {
    while (1) {
      value = fgetc(fp);

      if (value == EOF)
        break;
      else
        printf("%c", value);
    }

    fclose(fp);
  }
}
