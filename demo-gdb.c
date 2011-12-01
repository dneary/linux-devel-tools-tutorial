#include <stdlib.h>
#include <stdio.h>

int main(void)
{
    char buf[80];
    printf("Please enter some text.\n");

    fgets(buf, 80, stdin);
    buf[79]= '\0';
    printf("%s\n", buf);

    return 0;
}
