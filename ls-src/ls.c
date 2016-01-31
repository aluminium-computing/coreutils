/* Licensed under APL; read APL in the LICENSE file */

/* get printf */

#include <stdio.h>
#include <dirent.h>
#include <strings.h>
int ls(char *directory);



int main(int argc, char **argv, char **env) {
  if (argc != 1){
    if (strncmp(argv[1], "-v", 2) == 0) {
      printf("Wildebeest™ 'ls' v0.2\n");
      printf("Copyright © 2013, 2016 Aluminium Computing, Inc\n");
      return 0;
    }
  }
  char *directory;
  directory = ".";

  int i=1;
  while (argv[i]) {
    if (argv[i] != NULL && argv[i][0] != '-' || argv[i][0] != '_') directory = argv[i];
    i++;
  }
///  printf("DEBUG: directory = %s\n", directory);
  return ls(directory);

}

int ls(char *directory) {
  DIR *dirp;
  struct dirent *dirconts;
  if ( (dirp=opendir(directory)) == NULL) {
    printf("ls: Error 05 encountered: no such directory.\n");
    return -5;}
  dirconts = readdir(dirp);
  printf(".\n");
  while (dirconts=readdir(dirp)) {
    printf("%s\n", dirconts->d_name);

  }
}
