#ifndef P03D20_0_SRC_STACK_H_
#define P03D20_0_SRC_STACK_H_

#include <stdio.h>
#include <stdlib.h>
#include "token.h"

struct node {
    struct token *value;
    struct node* next;
};

struct stack {
    int len;
    struct node* top;
};

struct node_count {
    double num;
    struct node_count* next;
};

struct st_for_count {
    int len;
    struct node_count* top;
};

struct st_for_count* init_count();

void push_count(struct st_for_count* s, double n);

void pop_count(struct st_for_count* s);

void destroy_count(struct st_for_count* s);

void destroy_list_count(struct node_count* root);


struct stack* init();

void push(struct stack* s, struct token *token);

struct node *pop(struct stack* s);

void destroy(struct stack* s);

void destroy_list(struct node* root);

#endif  //  P03D20_0_SRC_STACK_H_

