
#ifndef STR_H
    #define STR_H

    #include <stdbool.h>
    #include <stddef.h>

typedef unsigned int uint_t;

// Get str size
uint_t STR_len(char *);

// Get pointer to begin
char *STR_begin(char *);

// Get pointer to end
char *STR_end(char *);

// Is the string is alpha
bool STR_is_alpha(char *);

// Is the string is numeric
bool STR_is_num(char *);

// Compare two string
bool STR_compare(char *, char *);

// Is the string is empty
bool STR_empty(char *);

// Clear the string
void STR_clear(char **, char);

// Substring string
char *STR_substr(char *, uint_t, uint_t);

// Duplicate string
char *STR_dup(char *);

// Reverse string
char *STR_rev(char *, bool);

// Get number from string
int STR_getnbr(char *);

// Set upcase string characters
void STR_upcase(char **);

// Set lowcase string characters
void STR_lowcase(char **);

// Capitalize all words in string
void STR_capitalize(char **);

// String to array
char **STR_to_array(char *);




#endif /* STR */