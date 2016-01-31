/* Licensed under APL; read APL in the LICENSE file */
// ©2013, 2016
/* get printf */

#include <stdio.h>
#include <strings.h>

int MAX_ECHOABLE_THROUGH_FGETS = 200;

int main(int argc, char **argv, char **env) {
  char buf_for_fgets[MAX_ECHOABLE_THROUGH_FGETS];
  //printf("%s\n", argv[1]);
  if (argv[1] == NULL) {
  //  printf("got in loop\n");
    fgets(buf_for_fgets, MAX_ECHOABLE_THROUGH_FGETS, stdin);
    //printf("got past\n");
    printf("%s\n", buf_for_fgets);
    return 0;
    
  }
  if (strncmp(argv[1], "-v", 2) == 0) {
    printf("Wildebeest™ 'echo' v0.2\n");
    printf("Copyright © 2013, 2016 Aluminium Computing, Inc\n");
    return 0;
  }
  //printf("hadwe\n");
  
  if (argv[1] != NULL) {
    //printf("ha\n");
    int i = 1;
    while (argv[i] != NULL) {
      printf("%s\n", argv[i]);
      i++;
    } 
  } 
}
