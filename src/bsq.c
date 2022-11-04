/*
** EPITECH PROJECT, 2022
** B-CPE-101 : BSQ
** File description:
** bsq.c
*/

#include <unistd.h>
#include "functions.h"
#include "macro.h"

static int square(char *content, int pos, len_t len)
{
    for (int i = 0; i < len.size; ++i) {
        for (int j = 0; j < len.size; ++j) {
            if (((pos + (i * (len.width + 1)) + j) > len.height * (len.width + 1)) ||
                (content[pos + (i * (len.width + 1)) + j] != '.'))
                return len.size - 1;
        }
    }
    len.size += 1;
    return (square(content, pos, len));
}

void bsq(char *content, int h, int w)
{
    int max = 0;
    int pos = 0;
    int tmp;

    for (int i = 0; content[i] != '\0'; ++i) {
        if (content[i] != '.')
            continue;
        tmp = square(content, i, (len_t){h, w, 1});
        if (((tmp > max)) || (tmp == max && (i / (w + 1) < pos / (w + 1)))
            || (tmp == max && (i / (w + 1) < pos / (w + 1))
            && (i % (w + 1) < pos % (w + 1)))) {
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