#include <stdio.h>
#include "lex.c"
#include "token.c"

int main()
{
  Lexer l = init_lexer("ola 2133 teste");
  Token t;
  TokenList tklist = init_token_list(10);

  do {
    t = lex_get_next(&l);
    append_to_list(&tklist, t);
  } while (t.type != TK_EOF);

  print_token_list(tklist);

  free_token_list(tklist);
  tklist.tokens = NULL;
  return 0;
}