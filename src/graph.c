#include "check_string.h"
#include "draw.h"
#include "parse.h"
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    char *str;
    int len_str;
    str = input(&len_str);
    if (check_str(str, &len_str)) {
        if (len_str) {
            char **str_parse;
            int amount;
            str_parse = parseline(str, len_str, &amount);
            draw(str_parse, amount);

            for (int i = 0; i < amount; i++)
                free(str_parse[i]);
            free(str_parse);
        }
    } else {
        printf("Incorrect input :c\n");
    }

    free(str);
    return 0;
}
