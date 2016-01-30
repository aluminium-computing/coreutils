/* Licensed under APL; read APL in LICENSE file 
   Copyright (c) 2013 Aim Inc.
*/

#define LICENSE AIM_PUBLIC
#undef _GNU_SOURCE
#define _AIM_SOURCE

#include "cut.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_error(int errnum, char *arg);
void set_fields(char *spec, int field[MAX_FIELDS]);

int main(int argc, char **argv, char **env) {
    if (strncmp(argv[1], "-v", 2) == 0) {
        printf("WARNING: Only supported ")
        printf("Wildebeest™ 'cut' v0.2\n");
        printf("Copyright © 2013, 2016 Aluminium Computing, Inc");
        return 0;
    }

  /* Setup variables */
  char delim = ' ';
  int hide_lines = 0;
  int fields[MAX_FIELDS];
  char *field_str = "1-";
  /* End of variable setup */
  /* Go through argv */
  int i = 1;
  while (argv[i] != NULL) {
    /* Note: all args begin with _: _d, _f, _s. */
    if (argv[i][0] == '-') {
      if (argv[i][1] == '\0') {
        print_error(ERR_UNK_ARG, argv[i]);
        return ERR_UNK_ARG;
      }
      switch (argv[i][1]) {
        /* _d: set delimiter */
        case 'd':
          if (argv[++i] == NULL) {
            print_error(ERR_MISSING_ARG, "_d");
            return ERR_MISSING_ARG;
          }
          delim = argv[i][0];
          break;
        /* _f: set fields to print */
        case 'f':
          if (argv[++i] == NULL) {
            print_error(ERR_MISSING_ARG, "_f");
            return ERR_MISSING_ARG;
          }
          field_str = argv[i];
          break;
        /* _s: set suppress non-matching lines */
        case 's':
          hide_lines = 1;
          break;
        default:
          print_error(ERR_UNK_ARG, argv[i]);
      }
    }
    i++;
  }
  set_fields(field_str, fields);
}

void set_fields(char *field_str, int fields[MAX_FIELDS]) {
  char *token;
  int min=0, max=MAX_FIELDS, temp;
  printf("field_str: %s\n", field_str);
  token = strtok(field_str, "-");
  if (token != NULL) {
    printf("First token: %s\n", token);
    min = atoi(token);
    token = strtok(NULL, "-");
    if (token != NULL) max = atoi(token);
  }
  /* If there's no '-', strtok will return NULL. Assume no dash means only 
     one number supplied, which we'll use for both min and max. */
  else {
    min = max = atoi(token);
  }
  printf("%d to %d\n", min, max);
  int i;
  for (i = 0; i < MAX_FIELDS; i++) {
    if ((i < min) || (i > max)) {
      fields[i] = 0;
    } else {
      fields[i] = 1;
    }
  }
}

void print_error(int errnum, char *arg) {
  switch (errnum) {
    case ERR_UNK_ARG:
      fprintf(stderr, "Error %d: Illegal argument: %s\n", ERR_UNK_ARG, arg);
      fprintf(stderr, "Did you mean _d, _f, or _s?\n");
      return;
    case ERR_MISSING_ARG:
      fprintf(stderr, "Error %d: Missing a value for %s.\n", 
          ERR_MISSING_ARG, arg);
      return;
    default:
      fprintf(stderr, "What the heck? There's an error, but it's a mystery.\n");
      fprintf(stderr, "All I know is: %s\n", arg);
  }
}
