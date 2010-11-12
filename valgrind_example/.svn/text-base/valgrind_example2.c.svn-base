/*
 * valgrind_example2.c
 *
 * A small example application to demonstrate memory leaks with malloc
 * during an infinite loop.
 *
 * Just compile like:
 *
 * $ gcc valgrind_example2.c -o valgrind_example2 -g
 *
 * This maemo code example is licensed under a MIT-style license,
 * that can be found in the file called "License" in the same
 * directory as this file.
 * Copyright (c) 2007-2008 Nokia Corporation. All rights reserved.
 */

#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

/*
 * main
 */
int main()
{
  FILE* fp;
  char *pm;
  char *loop_pm;
  int   i;

  // Allocation #1 of 10 bytes
  if (( pm = (char *) malloc(10)) == NULL)
    {
      perror("malloc failed for 10 bytes.");
      exit(-1);
    }

  fp=fopen("/tmp/sometestfile.tmp","a");
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

  // now we enter into a loop where we leak memory all the time 
  // because we are careless and do not free the allocated memory.

  for ( i = 0 ; i < 20 ; i++ )
    {
      // loop malloc #i of 10 bytes
      if (( loop_pm = (char *) malloc( 10 ))==NULL)
	{
	  perror("malloc failed for 10 bytes.");
	  exit(-1); // okay, give up then...
	}

      //
      // in real life apps we should now use the loop_pm.
      // 

      strcpy(loop_pm,"test");
      
	printf("malloced (%s) and now sleeping for 2 seconds...\n",loop_pm);
      sleep(2);

      // we do not free the allocated memory so we leak memory with
      // every iteration..

    }
  free(loop_pm); // oops, this should really be inside the loop, not outside..

  // so we only freed the last iteration of the loop.


  return 0;
}
