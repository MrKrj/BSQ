
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "functions.h"
#include "macro.h"
#include "disp.h"
#include "str.h"

int get_size(char *file)
{
    stat_t s;

    if (stat(file, &s) == -1) {
        DISP_err("BSQ: ");
        DISP_err(file);
        DISP_err(" is not a valid file.\n");
        return -1;
    }
    return s.st_size;
}

static char *get_content(char *str, int size)
{
    int fd = open(str, O_RDONLY);
    char buffer[BUFFSIZE];
    char *content = malloc(sizeof(char) * (size + 1));
    int rd = 0;
    int tmp;

    if (buffer == NULL) {
        DISP_err("BSQ: Not enougth memory to allocate.\n");
        return NULL;
    }
    if (fd == -1) {
        DISP_err("BSQ: ");
        DISP_err(str);
        DISP_err(" is not a valid file.\n");
        return NULL;
    }
    while (rd < size) {
        tmp = read(fd, buffer, BUFFSIZE);
        for (int i = 0; i < tmp; ++i, ++rd)
            content[rd] = buffer[i];
    }
    content[size] = '\0';
    close(fd);
    return content;
}

int start(int ac __attribute__((unused)), char **av __attribute__((unused)))
{
    char *content;
    char *tmp;
    int size = get_size(av[1]);
    int height = 0;
    int width = 0;

    if (size == -1)
        return ER_FILE;
    content = get_content(av[1], size);
    if (content == NULL)
        return ERROR;
    tmp = content;
    while (content[0] != '\n')
        ++content;
    ++content;
    for (; content[width] != '\n'; ++width);
    for (int i = 0; content[i] != '\0'; ++i)
        if (content[i] == '\n')
            ++height;
    bsq(content, height, width);
    free(tmp);
    return SUCCESS;
}