#include <stdlib.h>
#include <stdio.h>

int main(void)
{
    char *buf;

    fgets(buf, 80, stdin);
    printf("%s\n", buf);

    return 0;
}
