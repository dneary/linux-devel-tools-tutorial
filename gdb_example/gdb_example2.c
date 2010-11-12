/*
 * simple C program to be used with gdb as an debugging example.
 *
 * Just compile like:
 *
 * $ gcc gdb_example2.c -o gdb_example2 -g
 *
 * This maemo code example is licensed under a MIT-style license,
 * that can be found in the file called "License" in the same
 * directory as this file.
 * Copyright (c) 2007-2008 Nokia Corporation. All rights reserved.
 *
 */

#include <stdio.h>
#include <unistd.h>

/*
 *
 */
int example_3()
{
  printf("Now in example_3()\n");
  return 0;
}

/*
 *
 */
int example_2(char* a)
{
  printf("Now in example_2(%s) function.\n",a);
  sleep(10);
  example_3();
  return 0;
}

/*
 *
 */
int example_1(int x)
{
  int z;
  printf("Now in example_1(%d) function.\n",x);
  z=x;
  sleep(10);
  example_2("parameter here");
  return z;
}


int main(int argc,  char** argv)
{
  printf("gdb_example2.\n");
  printf("Now in main().\n");
  example_1(argc);
  return 0;
}

