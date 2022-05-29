#include "cli.h"
#include "lexer.h"
#include "utils.h"

#include <stdio.h>

FILE *output;

static const char *usage = 
    "\n"
    "Caffeine Programming Language!"
    "\n"
    "[OPTIONS]:"
    "-h | --help [Display usage screen]"
    "-c | --compile <file1 file2 etc.> [Compile files in parameter]"
    "\n"
    "";

int cli_args(char **argv) {
    /* Help/usage display */
    if (NULL == argv[1] || 0 == strncmp(argv[1], "-h", 2) || 0 == strncmp(argv[1], "--help", 6)) {
        printf("%s", usage);
        return 0;
    }

    /* Go to lexer to get compiled, YAY! */
    if (0 == strncmp(argv[1], "-c", 2) || 0 == strncmp(argv[1], "--compile", 9)) {
        /* [TODO: implement for loop that grabs argc and auto fills argv[i]] */
        output = fopen("test.c", "w");
        /* debug_printf(("Output file created: %s\n", output)); */
        lexer_init(argv[2], 256);
    }

    /* Error handler */
    /* if (0 == strncmp(argv[1], "-", 1)) {
      fprintf(stderr, "Unknown option: \"%s\"\n", argv[1]);
      return 1;
     }*/

    /* How'd you get here lmao? */
    printf("[DEBUG] How'd you get here lmao\n");
    return 0;
}