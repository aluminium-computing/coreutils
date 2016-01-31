/* Licensed under APL; read APL in LICENSE file 
   Copyright (c) 2013 Aim Inc.
*/

#define LICENSE AIM_PUBLIC
#undef _GNU_SOURCE
#define _AIM_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <string.h>

mode_t perm_parse(int);

int main(int argc, char **argv, char **env) {
  if (argv[1] == NULL) {
    printf("chpr: Error 01 encountered: not enough arguments\n");
    return -1;
  }
  
  if (strncmp(argv[1], "-v", 2) == 0) {
        printf("Wildebeest™ 'chpr' v0.2\n");
        printf("Copyright © 2013, 2016 Aluminium Computing, Inc\n");
        return 0;
    }

  if (argc != 3) {
    fprintf(stderr, "chpr: Error 04 encountered: no such file.\n");
    return -1;
  }
  int perms = atoi(argv[1]);
  mode_t mode_p;
  mode_p = perm_parse(perms);
  if (chmod(argv[2], mode_p) == -1){ fprintf(stderr, "chpr: Error 03 encountered: insufficient permissions.\n", argv[2]); return -3; }
}

mode_t perm_parse(int int_perms) {
  mode_t mode_perms;
  
  int u, g, o;
  o = int_perms % 10;
  g = (int_perms / 10) % 10;
  u = (int_perms / 100) % 10;
  mode_perms = (u << 6) | (g << 3) | o;
  return mode_perms; 
 
}
