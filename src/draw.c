#include "postfix.h"
#include <math.h>
#include <stdio.h>

void draw(char **str_parse, int amount) {
    char app[25][80];
    for (int i = 0; i < 25; ++i) {
        for (int j = 0; j < 80; ++j)
            app[i][j] = '.';
    }

    for (int j = 0; j < 80; ++j) {
        double x, y;
        x = 0 + (4 * M_PI / 79) * j;
        y = function(x, str_parse, amount);
        if (y >= -1 - 1e-6 && y <= 1 + 1e-6) {
            for (int i = 0; i < 25; ++i) {
                if (y < -1 + 2. / 24 * (i + 0.5)) {
                    app[i][j] = '*';
                    break;
                }
            }
        }
    }

    for (int i = 0; i < 25; ++i) {
        for (int j = 0; j < 80; ++j)
            printf("%c", app[i][j]);
        printf("\n");
    }
}
