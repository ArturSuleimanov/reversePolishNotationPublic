#include "stack.h"
#include "token.h"
#include <stdio.h>
#include <stdlib.h>

struct stack *init() {
  struct stack *root = malloc(sizeof(struct stack));
  if (root) {
    root->len = 0;
    root->top = NULL;
  }
  return root;
}

void push(struct stack *s, struct token *token) {
  if (s) {
    struct node *elem = malloc(sizeof(struct node));
    if (elem) {
      elem->next = s->top;
      elem->value = token;
      s->top = elem;
      s->len = s->len + 1;
    }
  }
}

struct node *pop(struct stack *s) {
  if (s) {
    struct node *p = s->top;
    if (p) {
      s->top = p->next;
      s->len = s->len - 1;
    }
    return p;
  }
  return NULL;
}



struct st_for_count *init_count() {
  struct st_for_count *root = malloc(sizeof(struct st_for_count));
  if (root) {
    root->len = 0;
    root->top = NULL;
  }
  return root;
}

void push_count(struct st_for_count *s, double n) {
  if (s) {
    struct node_count *elem = malloc(sizeof(struct node_count));
    if (elem) {
      elem->next = s->top;
      elem->num = n;
      s->top = elem;
      s->len = s->len + 1;
    }
  }
}

void pop_count(struct st_for_count *s) {
  if (s) {
    struct node_count *p = s->top;
    if (p) {
      s->top = p->next;
      s->len = s->len - 1;
      free(p);
    }
  }
}

void destroy_list_count(struct node_count *root) {
  struct node_count *root_new = root;
  while (root_new) {
    struct node_count *p = root_new;
    root_new = root_new->next;
    free(p);
  }
}

void destroy_count(struct st_for_count *s) {
  if (s) {
    destroy_list_count(s->top);
    free(s);
  }
}
