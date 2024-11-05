#ifndef SUNLEX
#define SUNLEX
#include <stdlib.h>
#include "token.h"

typedef struct {
	char current;
	char *src;
	size_t srclen;
  unsigned int ip;
}Lexer;

Lexer init_lexer(char *src);
void lex_advance(Lexer *l);
Token lex_get_next(Lexer *l);
#endif