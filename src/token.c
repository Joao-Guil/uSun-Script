#include <stdio.h>
#include "../includes/token.h"

TokenList init_token_list(size_t initial_cap) {
  TokenList t = {0};
  t.tokens = malloc(sizeof(Token) * initial_cap);
  if (t.tokens == NULL) {
    printf("Cannot initialize token list.");
    exit(1);
  }
  t.capacity = initial_cap;
  t.size = 0;

  return t;
}

void append_to_list(TokenList *t, Token tk) {
  if (t->size > t->capacity && t->size < 1000) {
    t->capacity *= 2;
    Token *newtklist = realloc(t->tokens, t->capacity);
    t->tokens = newtklist;
  }
  t->tokens[t->size] = tk;
  t->size += 1;
}

void pop_from_list(TokenList *t) {
  t->size -= 1; // é isso
}

void print_token_list(TokenList t) {
  for (size_t i = 0; i < t.size; i++) {
    printf("value: %s type: %d\n", t.tokens[i].value.data, t.tokens[i].type);
  }
}

void free_token_list(TokenList t) {
  for (size_t i = 0; i < t.size; i++) {
    free(t.tokens[i].value.data);
  }
  free(t.tokens);
}