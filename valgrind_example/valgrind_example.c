/*
 * valgrind_example.c
 *
 * A small example application to demonstrate memory leaks with malloc.
 *
 * Just compile like:
 *
 * $ gcc valgrind_example.c -o valgrind_example -g
 *
 * This maemo code example is licensed under a MIT-style license,
 * that can be found in the file called "License" in the same
 * directory as this file.
 * Copyright (c) 2007-2008 Nokia Corporation. All rights reserved.
 */

#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

/*
 * main
 */
int main()
{
  char *pm;

  // Allocation #1 of 10 bytes
  if (( pm = (char *) malloc(10)) == NULL)
    {
      perror("malloc failed for 10 bytes.");
      exit(-1);
    }

  // Note that we just allocated 10 bytes and set the pm pointer to the allocated memory
  // but we do not free that 10 bytes before doing a new malloc.

  // Because we will reuse the pm pointer (below) we can not free the 19 bytes
  // allocated above.
	    
  // Allocation #2 of 20 bytes
  if ((pm = (char *) malloc(20)) == NULL)
    {
      perror("malloc failed for 20 bytes.");
      exit(-1);
    }

  free(pm); // here we free the 20 bytes allocated above.
	   
  // Allocation #3 of 30 bytes
  if ((pm = (char *) malloc(30))==NULL)
    {
      perror("malloc failed for 30 bytes.");
      exit(-1);
    }

  // Note, that we do not free the last 30 bytes that we allocated.
  // Valgrind should report that "definitely lost" bytes would be 40
  // (30+10) for this example application.

  return 0;
}
