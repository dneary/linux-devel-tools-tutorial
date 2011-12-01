#include <stdlib.h>
#include <stdio.h>

int testfun(void)
{
  /* Useless comment */
  return 0;
}

int main(void)
{
    char buf[80];
    testfun();
    printf("Please enter some text.\n");

    fgets(buf, 80, stdin);
    buf[79]= '\0';
    printf("%s\n", buf);

    return 0;
}
