#ifndef CAFFEINE_LEXER_H
#define CAFFEINE_LEXER_H

/* Read Caffeine [.cf] files into the lexer for parsing */
char next_char(void);
void next(void);
void lexer_init(char *filename, int maxlen);

#endif