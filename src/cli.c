#include <stdio.h>
#include <string.h>
#include "cli.h"
#include "version.h"

static const char *usage =
  "------------------------------------------\n"
  "| caffeine <command> [options]           |\n"
  "|                                        |\n"
  "| Options:                               |\n"
  "|                                        |\n"
  "|   -h, --help     Output this message   |\n"
  "|   -v, --version  Output version number |\n"
  "|                                        |\n"
  "| Commands:                              |\n"
  "|                                        |\n"
  "|   c, compile [file...]                 |\n"
  "------------------------------------------";

t_symstruct lookup_table[] = {
  { "h",         USAGE },
  { "-h",        USAGE },
  { "help",      USAGE },
  { "--help",    USAGE },
  { "v",         VERSION },
  { "-v",        VERSION },
  { "version",   VERSION },
  { "--version", VERSION },
  { "c",         COMPILE },
  { "compile",   COMPILE },
  { NULL, -1 }
};

void print_help(void) {
  printf("%s", usage);
}

void print_version(void) {
  printf("%s", version);
}

int key_from_string(char *key) {
  long unsigned int i;
  for (i = 0; i < NKEYS; i++) {
    t_symstruct *sym = &lookup_table[i];
    if (strcmp(sym->key, key) == 0)
      return sym->value;
  }
  return BAD_OPTION;
}

/* TODO: Fix SIGSEGV on incorrect args (*should goto default) */
int handle_args(char **argv) {
  if (argv[1]) {
    switch (key_from_string(argv[1])) {
    case USAGE:
      print_help();
      return 0;
    case VERSION:
      print_version();
      return 0;
    default: 
      printf("Invalid arguments! Showing usage.\n");
      print_help();
      return 1;  
    }
  } else {
    print_help();
    return 0;
  }
}