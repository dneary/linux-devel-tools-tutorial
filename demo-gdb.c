#include <stdlib.h>
#include <stdio.h>

int main(void)
{
    char *buf;
    printf("Please enter some test.\n");


    fgets(buf, 80, stdin);
    printf("%s\n", buf);

    return 0;
}
