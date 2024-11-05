#ifndef SUNTOKEN
#define SUNTOKEN
#include <stdlib.h>

typedef struct {
  char *data;
  size_t count;
} String;

typedef struct {
  enum {
    TK_identifier, // todo: type pra palavras-chave
    TK_Operator,
    TK_Number,
    TK_EOF,
    TK_Equals
  } type;

  String value;
}Token;

typedef struct {
  Token *tokens;
  size_t size;
  size_t capacity;
}TokenList;

TokenList init_token_list(size_t initial_cap);
void append_to_list(TokenList *t, Token tk);
void pop_from_list(TokenList *t);
void print_token_list(TokenList t);
void free_token_list(TokenList t);
#endif