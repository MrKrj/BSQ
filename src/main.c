/*
** EPITECH PROJECT, 2022
** B-CPE-101 : BSQ
** File description:
** main.c
*/

#include <stdbool.h>
#include "functions.h"
#include "macro.h"

static int help(void)
{
    disp_str("\n\t\t\t--- HELP ---\n\n");
    disp_str("\tThe purpose of this program is to find the most\n");
    disp_str("\tsquare possible in a two dimensional map.\n");
    disp_str("\t./BSQ <file>\n");
    disp_str("\t./BSQ <size> <pattern>\n");
    disp_str("\t<pattern> must be composed of '.' and 'o'.\n\n");
    return (SUCCESS);
}

static int show_params(void)
{
    disp_err("./BSQ <file>\n");
    disp_err("./BSQ <size> <pattern>\n");
    disp_str("<pattern> must be composed of '.' and 'o'.\n");
    return (ERROR);
}

static bool is_pattern(char *arg)
{
    for (int i = 0; arg[i] != '\0'; ++i)
        if (arg[i] != '.' && arg[i] != 'o')
            return false;
    return (true);
}

int main(int ac, char **av)
{
    if (ac == 2 && (str_compare(av[1], "--help") || str_compare(av[1], "-h")))
        return (help());
    if (ac == 3 && str_is_num(av[1]) && is_pattern(av[2]))
        return (start_with_pattern(str_getnbr(av[1]), av[2]));
    if (ac != 2)
        return (show_params());
    return (start_with_file(av[1]));
}