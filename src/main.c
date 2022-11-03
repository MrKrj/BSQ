
#include "functions.h"
#include "macro.h"
#include "str.h"
#include "disp.h"

static int help(void)
{
    DISP_str("\n\t\t\t--- HELP ---\n\n");
    DISP_str("\tThe purpose of this program is to find the most\n\tsquare possible in a two dimensional map.\n");
    DISP_str("\t./BSQ <file>\n");
    DISP_str("\t./BSQ <size> <pattern>\n");
    DISP_str("\t<pattern> must be composed of '.' and 'o'.\n\n");
    return SUCCESS;
}

static int show_params(void)
{
    DISP_err("./BSQ <file>\n");
    DISP_err("./BSQ <size> <pattern>\n");
    DISP_str("<pattern> must be composed of '.' and 'o'.\n");
    return ER_ARGS;
}

static bool is_pattern(char *arg)
{
    for (int i = 0; arg[i] != '\0'; ++i)
        if (arg[i] != '.' && arg[i] != 'o')
            return false;
    return true;
}

int main(int ac, char **av)
{
    if (ac == 2 && (STR_compare(av[1], "--help") || STR_compare(av[1], "-h")))
        return help();
    if (ac == 3 && STR_is_num(av[1]) && is_pattern(av[2]))
        return start_with_pattern(STR_getnbr(av[1]), av[2]);
    if (ac != 2)
        return show_params();
    return start_with_file(av[1]);
}