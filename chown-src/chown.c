/* Licensed under APL; read APL in LICENSE file 
   Copyright (c) 2013, 2016 Aim Inc.
*/

#undef _GNU_SOURCE
#define _AL_SOURCE

#include <unistd.h>
#include <sys/types.h>
#include <pwd.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char **argv, char **env) {
  if (argv[1] == NULL) {
    fprintf(stderr, "chown: Error 01 encountered. Not enough arguments.\n");
    return -1;

  }
  if (strncmp(argv[1], "-v", 2) == 0) {
        printf("Wildebeest™ 'chown' v0.2\n");
        printf("Copyright © 2013, 2016 Aluminium Computing, Inc\n");
        return 0;
    }
  //printf("%d\n", argc);
  if (argc != 3) {
    fprintf(stderr, "chown: Error 01 encountered. Not enough arguments.\n");
    return -1;
  }
  struct passwd *pwd;
    if ((pwd = getpwnam(argv[1])) == NULL) {
      fprintf(stderr, "chown: Error 02 encountered. No such user as %s.\n", argv[1]);
      return -1;
    }

    if (chown(argv[2], pwd->pw_uid, pwd->pw_gid) == -1)
    fprintf(stderr, "chown: Error 03 encountered. Insufficient permissions.\n");
}
