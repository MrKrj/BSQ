/*
** EPITECH PROJECT, 2022
** B-CPE-101 : BSQ
** File description:
** start.c
*/

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>
#include "functions.h"
#include "macro.h"

int get_size(char *file)
{
    stat_t s;

    if (stat(file, &s) == -1) {
        disp_err("BSQ: ");
        disp_err(file);
        disp_err(" is not a valid file.\n");
        return (-1);
    }
    return (s.st_size);
}

static void read_fd(char *content, int fd, int size)
{
    char buffer[BUFFSIZE];
    int rd = 0;
    int tmp;

    while (rd < size) {
        tmp = read(fd, buffer, BUFFSIZE);
        for (int i = 0; i < tmp; ++i, ++rd)
            content[rd] = buffer[i];
    }
    content[size] = '\0';
}

static char *get_content(char *str, int size)
{
    int fd = open(str, O_RDONLY);
    char *content;

    if (fd == -1) {
        disp_err("BSQ: ");
        disp_err(str);
        disp_err(" is not a valid file.\n");
        return (NULL);
    }
    content = malloc(sizeof(char) * (size + 1));
    if (content == NULL) {
        disp_err("BSQ: Not enougth memory to allocate.\n");
        return (NULL);
    }
    read_fd(content, fd, size);
    return (content);
}

int start_with_file(char *file)
{
    char *content;
    char *tmp;
    len_t len = {0, 0, get_size(file)};

    if (len.size == -1)
        return (ERROR);
    content = get_content(file, len.size);
    if (content == NULL)
        return (ERROR);
    tmp = content;
    while (content[0] != '\n')
        ++content;
    ++content;
    for (; content[len.width] != '\n'; ++len.width);
    for (int i = 0; content[i] != '\0'; ++i)
        if (content[i] == '\n')
            ++len.height;
    bsq(content, len.height, len.width);
    free(tmp);
    return (SUCCESS);
}

int start_with_pattern(int size, char *pattern)
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