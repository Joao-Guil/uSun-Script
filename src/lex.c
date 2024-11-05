#include "../includes/lex.h"
#include <ctype.h>
#include <string.h>

Lexer init_lexer(char *src) {
  Lexer l;
  l.src = src;
  l.ip = 0;
  l.srclen = strlen(l.src);
  l.current = src[l.ip];

  return l;
}

void lex_advance(Lexer *l) {
  l->ip += 1;
  l->current = l->src[l->ip];
}

static void skip_whitespace(Lexer *l) {
  while (isspace(l->current))
  {
    lex_advance(l);
  }
}

/* pular pro próximo caractere que não seja ' ' */
Token lex_get_next(Lexer *l) {
  skip_whitespace(l);

  if (isalpha(l->current)) {
    char ident[256] = "";
    int count = 0;

    while (isalpha(l->current)) {
      ident[count] = l->current;
      count += 1;
      lex_advance(l);
    }

    return (Token){.type = TK_identifier, .value = (String){.count = count, .data = strdup(ident)}};
  }
  if (isdigit(l->current)) {
    char digit[256] = "";
    int count = 0;

    while (isdigit(l->current)) {
      digit[count] = l->current;
      count += 1;
      lex_advance(l);
    }
    
    return (Token){.type = TK_Number, .value = (String){.count = count, .data = strdup(digit)}};
  }

  return (Token){.type = TK_EOF, .value = (String){.count = 2, .data = strdup("0")}};
}

/* Tokentype -> char * */
char *tktypestr(Token t) {
  switch (t.type) {
  case TK_identifier:
    return "identifier";
  case TK_Number:
    return "number";
  case TK_Operator:
    return "Operator";
  case TK_EOF:
    return "EOF";
  default:
    return "Not recognized as tokentype";
  }
}
