/* Licensed under APL; read APL in the LICENSE file */

/* get printf */

#include <stdio.h>
#include <strings.h>

int MAX_ECHOABLE_THROUGH_FGETS = 200;

int main(int argc, char **argv, char **env) {
  char buf_for_fgets[MAX_ECHOABLE_THROUGH_FGETS];
    if (strncmp(argv[1], "-v", 2) == 0) {
        printf("Wildebeest™ 'echo' v0.2\n");
        printf("Copyright © 2013, 2016 Aluminium Computing, Inc\n");
        return 0;
    }
  if (argv[1] == NULL) {
    fgets(buf_for_fgets, MAX_ECHOABLE_THROUGH_FGETS, stdin);
    printf("%s\n", buf_for_fgets);
  }
  if (argv[1] != NULL) {
    int i = 1;
    while (argv[i] != NULL) {
      printf("%s\n", argv[i]);
      i++;
    } 
  } 
}
