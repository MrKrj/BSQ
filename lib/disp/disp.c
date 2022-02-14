
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "disp.h"

void DISP_char(char c)
{
    write(1, &c, 1);
}

void DISP_str(char *str)
{
    for (uint_t i = 0; str[i] != '\0'; ++i)
        DISP_char(str[i]);
}

void DISP_err(char *str)
{
    for (uint_t i = 0; str[i] != '\0'; ++i)
        write(2, &str[i], 1);
}

void DISP_nbr(int nb)
{
    if (nb < 0) {
        DISP_char('-');
        nb *= -1;
    }
    if (nb / 10 != 0)
        DISP_nbr(nb / 10);
    DISP_char(nb % 10 + '0');
}

static void PRINT_str(va_list args_list)
{
    DISP_str(va_arg(args_list, char *));
}

static void PRINT_int(va_list args_list)
{
    DISP_nbr(va_arg(args_list, int));
}

static void PRINT_char(va_list args_list)
{
    DISP_char(va_arg(args_list, int));
}

op_fct_t op_fct[] = {
    {'s', &PRINT_str},
    {'d', &PRINT_int},
    {'c', &PRINT_char}
};

void DISP_print(char *str, ...)
{
    va_list args_list;
    
    va_start(args_list, str);
    for (uint_t i = 0; str[i] != '\0'; ++i) {
        if (str[i] != '%')
            DISP_char(str[i]);
        else {
            if (str[++i] == '%')
                DISP_char('%');
            else {
                for (uint_t j = 0; j < 3; j++) {
                    if (op_fct[j].op == str[i])
                        op_fct[j].fct(args_list);
                }
            }
        }
    }
}