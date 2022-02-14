

#ifndef DISP_H
    #define DISP_H

    #include <stdarg.h>

typedef unsigned int uint_t;

// Display char
void DISP_char(char);

// Display string
void DISP_str(char *);

// Display error string
void DISP_err(char *);

// Display number
void DISP_nbr(int);

// Display string array
void DISP_str_array(char **);

// Display string with params
void DISP_print(char *, ...);

typedef struct op_fct_s {
    char op;
    void (*fct)(va_list);
} op_fct_t;

#endif /* DISP_H */