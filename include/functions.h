/*
** EPITECH PROJECT, 2022
** B-CPE-101 : BSQ
** File description:
** functions.h
*/

#ifndef FUNCTIONS_H
    #define FUNCTIONS_H

    #include <stdbool.h>

/* Project */
int start_with_file(char *);
int start_with_pattern(int, char *);
void bsq(char  *, int, int);
int get_size(char *);

/* Utils */
int str_len(const char *);
bool str_compare(const char *, const char *);
int str_getnbr(char *);
bool str_is_num(char *);

/* Disp */
void disp_str(const char *);
void disp_err(const char *);


#endif /* FUNCTIONS_H */