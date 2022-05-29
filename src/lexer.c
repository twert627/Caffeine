#include "lexer.h"
#include "utils.h"

#include <stdlib.h>
#include <stdio.h>

/* Credit to mini-c for a lot of lexer code/comprehension */
char *inputname;
FILE *input;

int curln;
char curch;

char *buffer;
int buflength;
int token;

int token_other = 0;
int token_ident = 1;
int token_int   = 2;
int token_char  = 3;
int token_str   = 4;

char next_char() {
    if (curch == '\n') {
        curln++;
    }
    return curch = fgetc(input);
}

void next() {
    /* Skip whitespace */
    while (curch == ' ' || curch == '\r' || curch == '\n' || curch == '\t') {
        next_char();
    }

    /* Comments */
    if (curch == '#') {{
        while (curch != '\n' && !feof(input)) {
            next_char();
        }
        next(); /* Restart function to skip whitespace */
        return;
    }}

    buffer = 0;
    token = token_other;

    /* Idenitfier, keyword, or interger literal */
    if (isalpha(curch) || isdigit(curch)) {
        token = isalpha(curch) ? token_other : token_int;
    }
}

void lexer_init(char *filename, int maxlen) {
    inputname = filename;
    input = fopen(filename, "r");
    /* debug_printf(("[DEBUG] File opened: %s\n", inputname)); */

    /* Prepare lexer for parsing */
    curln = 1; /* Current line */
    buffer = malloc(maxlen);
    next_char();
    next();
}