/*
** EPITECH PROJECT, 2022
** B-CPE-101 : BSQ
** File description:
** utils.c
*/

#include <stdbool.h>

int str_len(const char *str)
{
    int i = 0;

    for(; str[i] != '\0'; ++i);
    return (i);
}

bool str_compare(const char *target, const char *dest)
{
    if (str_len(target) != str_len(dest))
        return (false);
    for (int i = 0; target[i] != '\0'; ++i)
        if (target[i] != dest[i])
            return (false);
    return (true);
}

static bool is_num(char c)
{
    if ((c < '0' || c > '9') && (c != '-' && c != '+'))
        return (false);
    return (true);
}

int str_getnbr(char *str)
{
    int sign = 1;
    int nb = 0;

    for (int i = 0; str[i] != '\0' && str[i] != '\n'; ++i) {
        while (!is_num(str[i]))
            ++i;
        if (str[i] == '-' || str[i] == '+') {
            sign *= str[i] == '-' ? -1 : 1;
        } else {
            nb = (nb * 10) + (str[i] - '0');
        }
    }
    return (nb * sign);
}

bool str_is_num(char *str)
{
    for (int i = 0; str[i] != '\0'; ++i)
        if (!is_num(str[i]))
            return (false);
    return (true);
}
