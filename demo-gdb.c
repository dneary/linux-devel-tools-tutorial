#include <stdlib.h>
#include <stdio.h>

int main(void)
{
    char buf[81];

    fgets(buf, 80, stdin);
   buf[80]= '\0'; 
   printf("%s\n", buf);

    return 0;
}
