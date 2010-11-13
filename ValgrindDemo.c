/* Matthew and Stones, Beginning Linux Programming, p. 455 
valgrind ./ValgrindDemo --leak-check=full ./ValgrindDemo
*/

#include <stdio.h>
#include <stdlib.h>

#define SIZE 1024

int main(){
    char *ptr = (char *) malloc(SIZE);
    char ch;

    /* unitialized read */
    ch = ptr[SIZE];

    /* write beyond the block */
    ptr[SIZE] = 0;

    /* orphan the block */
    ptr = 0;

    /* successful exit! */
    exit(0);
    
}
