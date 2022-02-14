
#include "functions.h"
#include "macro.h"
#include "str.h"
#include "disp.h"

static int help(void)
{
    DISP_str("\n\t\t\t--- HELP ---\n\n");
    DISP_str("\tThe purpose of this program is to find the most\n\tsquare possible in a two dimensional map.\n\n");
    return SUCCESS;
}

static int params(void)
{
    DISP_err("./BSQ <file>\n");
    return (ER_ARGS);
}

int main(int ac, char **av)
{
    if (ac == 2 && STR_compare(av[1], "-h"))
        return help();
    if (ac != 2)
        return params();
    return start(ac, av);
}