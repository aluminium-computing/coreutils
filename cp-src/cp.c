/* Licensed under APL; read APL in LICENSE file 
   Copyright (c) 2013,2016 Aim Inc.
*/

#define LICENSE AIM_PUBLIC
#undef _GNU_SOURCE
#define _AIM_SOURCE

#include <stdio.h>

int main(int argc, char **argv, char **env) {
    if (strncmp(argv[1], "-v", 2) == 0) {
        printf("Wildebeest™ 'cp' v0.2\n");
        printf("Copyright © 2013, 2016 Aluminium Computing, Inc\n");
        return 0;
    }

    if (argc != 3) { printf("cp: Error 01 encountered: not enough arguments."); return -1; }
  FILE *fd;
  FILE *fd2;
  char buf[4096];
  size_t stuff_read;
  fd = fopen(argv[1], "r");
  fd2 = fopen(argv[2], "w+");
  while (!feof(fd)) {
    stuff_read = fread(buf, sizeof(char), 4096, fd);
    if (stuff_read) {
      fwrite(buf, sizeof(char), stuff_read, fd2);
    } 
  }
}