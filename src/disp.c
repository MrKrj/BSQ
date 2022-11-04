/*
** EPITECH PROJECT, 2022
** B-CPE-101 : BSQ
** File description:
** disp.c
*/

#include <unistd.h>

void disp_err(const char *str)
{
    for (int i = 0; str[i] != '\0'; ++i) {
        write(2, &str[i], 1);
    }
}

void disp_str(const char *str)
{
    for (int i = 0; str[i] != '\0'; ++i) {
        write(1, &str[i], 1);
    }
}