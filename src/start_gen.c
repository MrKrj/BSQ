/*
** EPITECH PROJECT, 2022
** B-CPE-101 : BSQ
** File description:
** start.c
*/

#include <unistd.h>
#include <stdlib.h>
#include "functions.h"
#include "macro.h"

int start_with_pattern(int size, const char *pattern)
{
    int i = 0;
    int j = 0;
    int content_size = size * size;
    int pattern_size = str_len(pattern);
    char *content = malloc(sizeof(char) * (content_size + size + 1));

    if (content == NULL) {
        disp_err("BSQ: Not enougth memory to allocate.\n");
        return (ERROR);
    }
    while (i < content_size + size) {
        content[i++] = pattern[j++];
        j = j == pattern_size ? 0 : j;
        if (i != 0 && (i + 1) % (size + 1) == 0)
            content[i++] = '\n';
    }
    content[i] = '\0';
    bsq(content, size, size);
    free(content);
    return (SUCCESS);
}