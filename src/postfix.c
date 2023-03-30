#include "postfix.h"
#include "stack.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

double function(double x, char **str, int n) {
    double res = 0;
    struct st_for_count *st_for_count = init_count();
    for (int i = 0; i < n; i++) {
        if (isNumber(str[i]))
            push_count(st_for_count, atof(str[i]));
        if (strcmp(str[i], "x") == 0)
            push_count(st_for_count, x);
        if (strcmp(str[i], "*") == 0 || strcmp(str[i], "+") == 0 ||
                strcmp(str[i], "-") == 0 || strcmp(str[i], "/") == 0 ||
                strcmp(str[i], "^") == 0) {
            double a = st_for_count->top->num;
            double b = st_for_count->top->next->num;
            pop_count(st_for_count);
            if (strcmp(str[i], "*") == 0)
                st_for_count->top->num = b * a;
            if (strcmp(str[i], "+") == 0)
                st_for_count->top->num = b + a;
            if (strcmp(str[i], "-") == 0)
                st_for_count->top->num = b - a;
            if (strcmp(str[i], "/") == 0)
                st_for_count->top->num = b / a;
            if (strcmp(str[i], "^") == 0)
                st_for_count->top->num = pow(b, a);
        }
        if (strcmp(str[i], "s") == 0)
            st_for_count->top->num = sin(st_for_count->top->num);
        if (strcmp(str[i], "c") == 0)
            st_for_count->top->num = cos(st_for_count->top->num);
        if (strcmp(str[i], "g") == 0)
            st_for_count->top->num = 1. / tan(st_for_count->top->num);
        if (strcmp(str[i], "q") == 0)
            st_for_count->top->num = sqrt(st_for_count->top->num);
        if (strcmp(str[i], "l") == 0)
            st_for_count->top->num = log(st_for_count->top->num);
        if (strcmp(str[i], "t") == 0)
            st_for_count->top->num = tan(st_for_count->top->num);
        if (strcmp(str[i], "~") == 0)
            st_for_count->top->num = -st_for_count->top->num;
    }
    res = st_for_count->top->num;
    destroy_count(st_for_count);
    return res;
}

int isNumber(const char *a) {
    int res = 1;
    int flag = 0;
    for (int i = 0; a[i] && res; i++)
        if (a[i] < '0' || a[i] > '9') {
            if (a[i] == '.') {
                if (flag == 0)
                    flag = 1;
                else
                    res = 0;
            } else {
                res = 0;
            }
        }
    return res;
}
