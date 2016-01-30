/* Licensed under APL; read APL in LICENSE file 
   Copyright (c) 2013 Aim Inc.
*/

#define LICENSE AIM_PUBLIC
#undef _GNU_SOURCE
#define _AIM_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char **argv, char **env) {
    if (strncmp(argv[1], "-v", 2) == 0) {
        printf("Wildebeest™ 'chroot' v0.2\n");
        printf("Copyright © 2013, 2016 Aluminium Computing, Inc\n");
        return 0;
    }

  if (argc != 2) {
    fprintf(stderr, "chroot: error 01 encountered: not enough arguments\n");
    return -1;
  }
  /*
  char *shell;
  shell = getenv("SHELL");
  */
  int i;
  i = chroot(argv[1]);
  if (i == -1) {
    fprintf(stderr, "chroot: Error 03 encountered: insufficient permissions.\n");
    return i;
  }
  strncpy(argv[0], "/bin/bash", 10);
  strncpy(argv[1], "-i", 3);
  argv[2] = NULL;
  chdir("/");
  execvp("/bin/bash", argv );
}
