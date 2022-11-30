#ifndef CLI_H
#define CLI_H

#include "common.h"

#define USAGE 1
#define COMPILE 2
#define VERSION 3
#define BAD_OPTION -1

typedef struct {
  char *key;
  int value;
} t_symstruct;

#define NKEYS (sizeof(lookup_table) / sizeof(t_symstruct))

int handle_args(char **argv);
void print_help(void);
void print_version(void);
int key_from_string(char *key);
#endif /* CLI_H */
