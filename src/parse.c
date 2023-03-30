#include "parse.h"
#include "stack.h"
#include "token.h"
#include <stdio.h>
#include <stdlib.h>
#define NMAX 1000
#define NUM 10
int isDigit(char ch);
void addDigit(char *cur, char **result, const char *line, const int *position, int *j);
char **parseline(char *line, int n, int *amount);
void copy(char *list1, const char *list2, int n);
void output(char *out, int n);
void fromstacktores(struct stack **mystack, char **result, int *position);
void freestack(struct stack **mystack, char **result, int *position);

int isDigit(char ch) { return (ch - '0' >= 0 && ch - '9' <= 9) ? 1 : 0; }

char **parseline(char *line, int n, int *amount) {
    struct stack *mystack = init();
    char **result = (char **)calloc(n, sizeof(char *));
    int position = 0;
    for (int i = 0; i < n; i++) {
        if (!result[position])
            result[position] = (char *)calloc(11, sizeof(char));
        char cur = line[i];
        if (isDigit(cur) || cur == 'x' || cur == 'y') {
            i++;
            addDigit(&cur, result, line, &position, &i);
            position++;
        } else if (cur == '(') {
            push(mystack, init_Token(cur));
        }  else if (cur == ')') {
            while (mystack->len > 0 && mystack->top->value->priority > -2) {
                fromstacktores(&mystack, result, &position);
            }
            struct node *brace = pop(mystack);
            free(brace->value);
            free(brace);
        } else {
            struct token *curtoken = init_Token(cur);
            if (mystack->len == 0) {
                push(mystack, curtoken);
            } else {
                while (mystack->len > 0 &&
                             mystack->top->value->priority <= curtoken->priority &&
                             mystack->top->value->priority != -2) {
                    fromstacktores(&mystack, result, &position);
                }
                push(mystack, curtoken);
            }
        }
    }
    freestack(&mystack, result, &position);
    *amount = position;
    return result;
}

void freestack(struct stack **mystack, char **result, int *position) {
    while ((*mystack)->len > 0) {
        struct node *curnode = pop(*mystack);
        if (!result[*position])
            result[*position] = (char *)calloc(11, sizeof(char));
        result[*position][0] = curnode->value->value;
        result[*position][1] = '\0';
        free(curnode->value);
        free(curnode);
        (*position)++;
    }
    free(*mystack);
}
void fromstacktores(struct stack **mystack, char **result, int *position) {
    struct node *curnode = pop(*mystack);
    result[*position][0] = curnode->value->value;
    *position += 1;
    if (!result[*position]) {
        result[*position] = (char *)calloc(11, sizeof(char));
    }
    free(curnode->value);
    free(curnode);
}
void addDigit(char *cur, char **result, const char *line, const int *position, int *j) {
    int i = 0;
    result[*position][i] = *cur;
    *cur = line[*j];
    i++;
    while (isDigit(*cur) || *cur == '.') {
        result[*position][i] = *cur;
        *j += 1;
        *cur = line[*j];
        i++;
    }
    *j -= 1;
    result[*position][i] = '\0';
}
char *input(int *len) {
    int n = 10;
    char *line = (char *)calloc(n, sizeof(char));
    int pos = 0;
    char cur = getchar();
    while (cur != '\n') {
        if (cur == ' ') {
            cur = getchar();
        } else {
            line[pos] = cur;
            pos++;
            if (pos == n) {
                char *tem = line;
                line = (char *)calloc(n * 2, sizeof(char));
                copy(line, tem, n);
                n *= 2;
                free(tem);
            }
            cur = getchar();
        }
    }
    *len = pos;
    line[pos] = '\0';
    return line;
}
void copy(char *list1, const char *list2, int n) {
    for (int i = 0; i < n; i++) {
        list1[i] = list2[i];
    }
}
