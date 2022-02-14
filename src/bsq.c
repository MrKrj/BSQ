
#include <unistd.h>
#include "functions.h"
#include "macro.h"
#include "disp.h"

static int square(char *content, int pos, int h, int w, int len)
{
    for (int i = 0; i < len; ++i) {
        for (int j = 0; j < len; ++j) {
            if (((pos + (i * (w + 1)) + j) > h * (w + 1)) ||
                (content[pos + (i * (w + 1)) + j] != '.'))
                return len - 1;
        }
    }
    return square(content, pos, h, w, len + 1);
}

void bsq(char *content, int h, int w)
{
    int max = 0;
    int pos = 0;
    int tmp;

    for (int i = 0; content[i] != '\0'; ++i) {
        if (content[i] != '.')
            continue;
        tmp = square(content, i, h, w, 1);
        if (tmp > max || (tmp == max && (i % w < pos % w))) {
            max = tmp;
            pos = i;
        }
    }
    for (int i = 0; i < max; ++i) {
        for (int j = 0; j < max; ++j) {
            content[pos + (i * (w + 1)) + j] = 'x';
        }
    }
    write(1, content, h * (w + 1));
}