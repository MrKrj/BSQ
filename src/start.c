
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

    if (content == NULL) {
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

int start_with_file(char *file)
{
    char *content;
    char *tmp;
    int size = get_size(file);
    int height = 0;
    int width = 0;

    if (size == -1)
        return ER_FILE;
    content = get_content(file, size);
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

int start_with_pattern(int size, char *pattern)
{
    int i = 0;
    int j = 0;
    int content_size = size * size;
    int pattern_size = STR_len(pattern);
    char *content = malloc(sizeof(char) * (content_size + size + 1));

    if (content == NULL) {
        DISP_err("BSQ: Not enougth memory to allocate.\n");
        return ERROR;
    }
    while (i < content_size + size) {
        content[i++] = pattern[j++];
        if (j == pattern_size)
            j = 0;
        if (i != 0 && (i + 1) % (size + 1) == 0)
            content[i++] = '\n';
    }
    content[i] = '\0';
    bsq(content, size, size);
    free(content);
    return SUCCESS;
}