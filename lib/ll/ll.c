
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include "ll.h"

void L_delete(node_t *node)
{
    free(node->data);
    free(node);
}

void L_clear(node_t **list)
{
    if (*list == NULL)
        return;
    L_clear(&((*list)->next));
    L_delete(*list);
    *list = NULL;
}

uint_t L_size(node_t *list)
{
    uint_t len = 0;

    while (NULL != list) {
        len++;
        list = list->next;
    }
    return len;
}

bool L_empty(node_t *list)
{
    if (L_size(list) == 0)
        return true;
    return false;
}

static void *char_data(char c)
{
    char *data = malloc(sizeof(char));

    *data = c;
    return (void *)(data);
}

static void *double_data(double nb)
{
    double *data = malloc(sizeof(double));

    *data = nb;
    return (void *)(data);
}

static void *int_data(int nb)
{
    int *data = malloc(sizeof(int));

    *data = nb;
    return (void *)(data);
}

static void *str_data(char *str)
{
    int len = 0;
    char *data;

    for (; str[len] != '\0'; ++len);
    data = malloc(sizeof(char) * (len + 1));
    for (int i = 0; str[i] != '\0'; ++i)
        data[i] = str[i];
    data[len] = '\0';
    return  (void *)(data);
}

int L_int(node_t *node)
{
    return *((int *)node->data);
}

double L_double(node_t *node)
{
    return *((double *)node->data);
}

char *L_str(node_t *node)
{
    return ((char *)node->data);
}

char L_char(node_t *node)
{
    return *((char *)node->data);
}

static void display_node(node_t *node)
{
    switch (node->type) {
        case INTEGER:
            printf("%d\n", *((int *)node->data)); break;
        case STR:
            printf("%s\n", ((char *)node->data)); break;
        case DOUBLE:
            printf("%.3f\n", *((double *)node->data)); break;
        case CHAR:
            printf("%c\n", *((char *)node->data)); break;
    }
}

void L_display(node_t *list)
{
    node_t *tmp = list;

    while (tmp != NULL) {
        display_node(tmp);
        tmp = tmp->next;
    }
}

static node_t *create_node(va_list args_list, type_t type)
{
    node_t *new = malloc(sizeof(node_t));

    switch (type) {
        case INTEGER:
            new->data = int_data(va_arg(args_list, int)); break;
        case STR:
            new->data = str_data(va_arg(args_list, char *)); break;
        case DOUBLE:
            new->data = double_data(va_arg(args_list, double)); break;
        case CHAR:
            new->data = char_data(*va_arg(args_list, char *)); break;
        default:
            new->data = NULL;
    }
    new->type = type;
    new->prev = NULL;
    new->next = NULL;
    return new;
}

node_t *L_push_front(node_t **list, type_t type, ...)
{
    va_list args_list;
    node_t *new;

    va_start(args_list, type);
    new = create_node(args_list, type);
    if (*list == NULL) {
        *list = new;
    } else {
        new->next = *list;
        (*list)->prev = new;
        *list = new;
    }
    return new;
}

node_t *L_push_back(node_t **list, type_t type, ...)
{
    va_list args_list;
    node_t *new;
    node_t *tmp = *list;

    va_start(args_list, type);
    new = create_node(args_list, type);
    if (NULL == *list) {
        *list = new;
    } else {
        while (tmp->next != NULL)
            tmp = tmp->next;
        tmp->next = new;
        new->prev = tmp;
    }
    return new;
}

node_t *L_pop_front(node_t **list)
{
    node_t *tmp = *list;

    if (NULL == *list)
        return NULL;
    if (L_size(*list) == 1) {
        *list = NULL;
        return tmp;
    }
    *list = (*list)->next;
    (*list)->prev = NULL;
    tmp->next = NULL;
    return tmp;
}

node_t *L_pop_back(node_t **list)
{
    node_t *tmp = *list;
    node_t *to_return;

    if (NULL == *list)
        return NULL;
    if (L_size(*list) == 1) {
        *list = NULL;
        return tmp;
    }
    while (NULL != tmp->next)
        tmp = tmp->next;
    to_return = tmp;
    to_return->prev->next = NULL;
    to_return->prev = NULL;
    return to_return;
}

void L_erase_front(node_t **list)
{
    node_t *tmp = *list;

    if (NULL == *list)
        return;
    if (L_size(*list) == 1) {
        L_delete(*list);
        *list = NULL;
        return;
    }
    *list = (*list)->next;
    L_delete(tmp);
    (*list)->prev = NULL;
}

void L_erase_back(node_t **list)
{
    node_t *tmp = *list;
    node_t *to_delete;

    if (NULL == *list)
        return;
    if (L_size(*list) == 1) {
        L_delete(*list);
        *list = NULL;
        return;
    }
    while (NULL != tmp->next)
        tmp = tmp->next;
    tmp->prev->next = NULL;
    L_delete(tmp);
}

node_t *L_begin(node_t *list)
{
    node_t *tmp = list;

    while (tmp->prev != NULL)
        tmp = tmp->prev;
    return tmp;
}

node_t *L_end(node_t *list)
{
    node_t *tmp = list;

    while (tmp->next != NULL)
        tmp = tmp->next;
    return tmp;
}