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

static int get_size(const char *file)
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

static char *get_content(const char *str, int size)
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

static int get_params(len_t *len, char *content, int nb)
{
    for (; content[len->width] != '\n'; len->width++);
    for (int i = 0; content[i] != '\0'; ++i) {
        if (content[i] != '.' && content[i] != 'o' && content[i] != '\n') {
            disp_err("BSQ: Forbidden character.\n");
            return (ERROR);
        }
        if ((content[i] == '\n') && ((len->height == 0 && i != len->width)
            || (len->height > 0 && (i + 1) % (len->width + 1) != 0))) {
            disp_err("BSQ: Unmatched line size.\n");
            return (ERROR);
        }
        if (content[i] == '\n')
            len->height++;
    }
    if (nb == len->height)
        return (SUCCESS);
    disp_err("BSQ: Number of line doesn't match.\n");
    return (ERROR);
}

int start_with_file(const char *file)
{
    char *content;
    char *tmp;
    int nb;
    len_t len = {0, 0, get_size(file)};

    if (len.size == -1 || len.size == 0)
        return (ERROR);
    content = get_content(file, len.size);
    if (content == NULL)
        return (ERROR);
    nb = str_getnbr(content);
    tmp = content;
    while (content[0] != '\n')
        ++content;
    ++content;
    if (get_params(&len, content, nb) == ERROR)
        return (ERROR);
    bsq(content, len.height, len.width);
    free(tmp);
    return (SUCCESS);
}