#include "token.h"
#include <stdlib.h>

struct token *init_Token(char token) {
  struct token *ret = malloc(sizeof(struct token));
  ret->value = token;
  if (token == '+' || token == '-') {
    ret->priority = 5;
  } else if (token == '/' || token == '*') {
    ret->priority = 4;
  } else if (token == '^') {
    ret->priority = 2;
  } else if (token == '(') {
    ret->priority = -2;
  } else if (token == ')') {
    ret->priority = -1;
  } else if (token == 's' || token == 'q' || token == 'c' || token == 't' ||
             token == 'l' || token == '~' ||
             token == 'g') { // s - sin; q - sqrt; c - cos; t - tg; l - ln; '~'
                             // - -; g - ctg;
    ret->priority = 1;
  } else {
    free(ret);
    ret = NULL;
  }
  return ret;
}
