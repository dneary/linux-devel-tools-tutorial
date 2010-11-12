/*
 * simple C program to be used with gdb as an debugging example.
 *
 * Just compile like:
 *
 * $ gcc gdb_example.c -o gdb_example -g
 *
 * This maemo code example is licensed under a MIT-style license,
 * that can be found in the file called "License" in the same
 * directory as this file.
 * Copyright (c) 2007-2008 Nokia Corporation. All rights reserved.
 *
 */

#include <stdio.h>

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
  example_2("parameter here");
  return z;
}


int main(int argc,  char** argv)
{
  printf("Now in main().\n");
  example_1(argc);
  return 0;
}
