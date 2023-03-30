#ifndef P03D20_0_SRC_TOKEN_H_
#define P03D20_0_SRC_TOKEN_H_


#include <stdlib.h>

struct token *init_Token(char token);


struct token {
    char value;
    int priority;
};



#endif  //  P03D20_0_SRC_TOKEN_H_
