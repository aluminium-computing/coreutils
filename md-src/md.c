// Wildebeest™ coreutils
// md — creates directory
// % md [-a] path
// -a will create intermediate directories
// Version 0.1
// Copyright © 2016 Aluminium Computing, Inc.

#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>

#define TRUE 1
#define FALSE 0

int md(char *arg);

int main(int argc, char **argv, char **env) {
  if (argv[1] == NULL) {
    printf("md: Error 01 encountered: not enough arguments.\n");
    return -1;
  }
  if (strncmp(argv[1], "-v", 2) == 0) {
    printf("Wildebeest(TM) `md' v0.1\nCopyright © 2016 Aluminium Computing, Inc.\n");
    return 0;
  }
  int a = TRUE;
  int i = 1;
  if (a == TRUE) {
    //xprintf("hall");
    char *tokens[10];
    int numberToken = 0;
    tokens[0] = strtok(argv[1], "/");
    numberToken++;
    while ( (tokens[numberToken] = strtok(NULL, "/")) != NULL) {
      numberToken++;
      //printf("token: %d\n", numberToken);
    }
    char path[1024];
    strncpy(path, tokens[0], 1024);
    int w = 0;
    while (w < numberToken) {
      if (w > 0) {
        strncat(path, "/", 1);
        strncat(path, tokens[w], 100);
      }
      //printf("%s\n", path);
      md(path);
      w++;
     // printf("%s\n", path);
    }
  }
//#return md(argv[i]);
}

int md(char *arg) {
  if (0 != mkdir(arg, 0777)) {
    switch (errno) {
      case EACCES:
        printf("md: Error 03 encountered: insufficient permissions.\n");
        return 1;
      case EEXIST:
        printf("md: notice: %s already exists.\n", arg);
        
      case ENOSPC:
        printf("md: Error 06 encountered: no space remains\n");
        return 1;
      case ENOTDIR:
        printf("md: Error 05 encountered: no such directory\n");
        return 1;
      case EROFS:
        printf("md: Error 07 encountered: read-only filesystem\n");
        return -1;
        
      default:
        printf("md: Error 08 encountered: unknown error.\n");
        return 2;
    }
  }
  return 0;
}