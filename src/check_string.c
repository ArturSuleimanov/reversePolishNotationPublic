#include "check_string.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int check_str(char *a, int *len) {
    int res = 0;
    delete_spaces(a);
    while (delete_skob(a)) {
    }
    res = check(a);
    if (res) {
        delete_nazv(a);
    }
    *len = strlen(a);
    return res;
}

void delete_nazv(char *a) {
    char *p;
    int i;
    while ((p = strstr(a, "sin"))) {
        for (i = 1; p[i + 2]; i++)
            p[i] = p[i + 2];
        p[i] = 0;
    }
    while ((p = strstr(a, "cos"))) {
        for (i = 1; p[i + 2]; i++)
            p[i] = p[i + 2];
        p[i] = 0;
    }
    while ((p = strstr(a, "tan"))) {
        for (i = 1; p[i + 2]; i++)
            p[i] = p[i + 2];
        p[i] = 0;
    }
    while ((p = strstr(a, "ctg"))) {
        p[0] = 'g';
        for (i = 1; p[i + 2]; i++)
            p[i] = p[i + 2];
        p[i] = 0;
    }
    while ((p = strstr(a, "sqrt"))) {
        p[0] = 'q';
        for (i = 1; p[i + 3]; i++)
            p[i] = p[i + 3];
        p[i] = 0;
    }
    while ((p = strstr(a, "ln"))) {
        for (i = 1; p[i + 1]; i++)
            p[i] = p[i + 1];
        p[i] = 0;
    }
}

void delete_spaces(char *a) {
    int i, j;
    for (i = 0, j = 0; a[i]; i++) {
        if (a[i] != ' ') {
            a[j] = a[i];
            j++;
        }
    }
    a[j] = '\0';
}

int delete_skob(char *a) {
    int i, j;
    int res = 0;
    int kol = 0;
    for (i = 0, j = 0; a[i]; i++) {
        if (a[i] == '(') {
            kol++;
            if (a[i + 1] == ')') {
                res = 1;
                kol--;
                i++;
            } else {
                a[j] = '(';
                j++;
            }
        } else {
            if (a[i] == ')')
                kol--;
            a[j] = a[i];
            j++;
        }
    }
    a[j] = 0;
    if (kol != 0)
        res = 0;
    return res;
}

int is_sin(char *a) {
    return (a && a + 1 && a + 2 && a + 3 && a[0] == 's' && a[1] == 'i' &&
                    a[2] == 'n' && a[3] == '(');
}

int is_ctg(char *a) {
    return (a && a + 1 && a + 2 && a + 3 && a[0] == 'c' && a[1] == 't' &&
                    a[2] == 'g' && a[3] == '(');
}

int is_cos(char *a) {
    return (a && a + 1 && a + 2 && a + 3 && a[0] == 'c' && a[1] == 'o' &&
                    a[2] == 's' && a[3] == '(');
}

int is_tan(char *a) {
    return (a && a + 1 && a + 2 && a + 3 && a[0] == 't' && a[1] == 'a' &&
                    a[2] == 'n' && a[3] == '(');
}
int is_sqrt(char *a) {
    return (a && a + 1 && a + 2 && a + 3 && a + 4 && a[0] == 's' && a[1] == 'q' &&
                    a[2] == 'r' && a[3] == 't' && a[4] == '(');
}
int is_ln(char *a) {
    return (a && a + 1 && a + 2 && a[0] == 'l' && a[1] == 'n' && a[2] == '(');
}

int skipNumber(const char *a) {
    int i = 0;
    int point = 0;
    while (a[i] >= '0' && a[i] <= '9')
        i++;
    if (a[i] == '.') {
        i++;
        point = 1;
    }
    while (point == 1 && a[i] >= '0' && a[i] <= '9')
        i++;
    return i;
}

int check(char *a) {
    int oper = 1, res = 1;
    double temp;
    for (int i = 0; a[i] && res; i++) {
        if (oper) {
            if (a[i] == 'x') {
                oper = 0;
            } else if (a[i] != '-' && a[i] != '+' && sscanf(a + i, "%lf", &temp)) {
                i += skipNumber(a + i) - 1;
                oper = 0;
            } else if (is_cos(a + i) || is_sin(a + i) || is_tan(a + i) ||
                                 is_ctg(a + i)) {
                i += 3;
            } else if (is_sqrt(a + i)) {
                i += 4;
            } else if (is_ln(a + i)) {
                i += 2;
            } else if (a[i] == '-' && a[i + 1] &&
                                 ((i > 0 && a[i - 1] != '~') || i == 0)) {
                a[i] = '~';
            } else if (a[i] != '(') {
                res = 0;
            }
        } else {
            if (a[i] == '-' || a[i] == '+' || a[i] == '*' || a[i] == '/' ||
                    a[i] == '^') {
                oper = 1;
            } else if (a[i] == ')') {
                while (a[i] == ')')
                    i++;
                if (!a[i])
                    i--;
                oper = 1;
            } else {
                res = 0;
            }
        }
    }
    return res;
}
