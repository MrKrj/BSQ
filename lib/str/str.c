
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "str.h"


uint_t STR_len(char *str)
{
    uint_t len = 0;

    for (; str[len] != '\0'; ++len);
    return len;
}

static bool is_alpha_numeric(char c)
{
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') ||
        (c >= '0' && c <= '9'))
        return true;
    return false;
}

static int count_words(char *str)
{
    uint_t words = 0;

    for (int i = 0; str[i] != '\0';) {
        if (is_alpha_numeric(str[i])) {
            while (is_alpha_numeric(str[i]))
                ++i;
            words++;
        }
        if (str[i] != '\0')
            ++i;
    }
    return words;
}

static char **free_my_array(char **array)
{
    for (int i = 0; array[i] != NULL; ++i)
        free(array[i]);
    free(array);
    return NULL;
}

static char **allocate_memory_per_words(char **array, char *str)
{
    uint_t word_index = 0;
    uint_t word_size = 0;

    for (int i = 0; str[i] != '\0';) {
        if (is_alpha_numeric(str[i])) {
            while (is_alpha_numeric(str[i])) {
                word_size++;
                i++;
            }
            array[word_index] = malloc(sizeof(char) * (word_size + 1));
            if (array[word_index] == NULL)
                return free_my_array(array);
            word_index++;
            word_size = 0;
        }
        if (str[i] != '\0')
            ++i;
    }
    return array;
}

static char **copy_words_in_array(char **array, char *str)
{
    uint_t word_index = 0;
    uint_t char_index = 0;

    for (int i = 0; str[i] != '\0';) {
        if (is_alpha_numeric(str[i])) {
            while (is_alpha_numeric(str[i])) {
                array[word_index][char_index] = str[i];
                i++;
                char_index++;
            }
            array[word_index][char_index] = '\0';
            word_index++;
            char_index = 0;
        }
        if (str[i] != '\0')
            ++i;
    }
    return array;
}

char **STR_to_array(char *str)
{
    char **array;

    uint_t words = count_words(str);
    array = malloc(sizeof(char *) * (words + 1));
    if (array == NULL)
        return NULL;
    array[words] = NULL;
    array = allocate_memory_per_words(array, str);
    if (array == NULL)
        return NULL;
    array = copy_words_in_array(array, str);
    return array;
}

char *STR_begin(char *str)
{
    return &str[0];
}

char *STR_end(char *str)
{
    return &str[STR_len(str) - 1];
}

bool STR_is_alpha(char *str)
{
    for (uint_t i = 0; str[i] != '\0'; ++i)
        if ((str[i] < 'A') || (str[i] > 'Z' && str[i] < 'a') || (str[i] > 'z'))
            return false;
    return true;
}

static bool is_num(char c)
{
    if ((c < '0' || c > '9') && (c != '-' && c != '+'))
        return false;
    return true;
}

bool STR_is_num(char *str)
{
    for (uint_t i = 0; str[i] != '\0'; ++i)
        if (!is_num(str[i]))
            return false;
    return true;
}

bool STR_compare(char *str1, char *str2)
{
    if (STR_len(str1) != STR_len(str2))
        return false;
    for (uint_t i = 0; str1[i] != '\0'; ++i)
        if (str1[i] != str2[i])
            return false;
    return true;
}

bool STR_empty(char *str)
{
    if (str[0] == '\0')
        return true;
    return false;
}

void STR_clear(char **str, char c)
{
    for (uint_t i = 0; *str[i] != '\0'; ++i)
        *str[i] = c;
}

char *STR_substr(char *str, uint_t begin, uint_t end)
{
    uint_t idx = 0;
    char *substr;

    if (end < begin)
        return NULL;
    if (STR_len(str) < end)
        end = STR_len(str);
    substr = malloc(sizeof(char) * (end - begin + 1));

    for (; begin < end; ++begin, ++idx)
        substr[idx] = str[begin];
    substr[idx] = '\0';
    return substr;
}

char *STR_dup(char *str)
{
    uint_t i;
    char *dup = malloc(sizeof(char) * (STR_len(str) + 1));

    for (i = 0; str[i] != '\0'; ++i)
        dup[i] = str[i];
    dup[i] = '\0';
    return dup;
}

char *STR_rev(char *str, bool to_free)
{
    int len = STR_len(str);
    int y = 0;
    char *rev = malloc(sizeof(char) * (len + 1));

    if (rev == NULL)
        return NULL;
    for (int i = len - 1; i >= 0; --i, ++y) {
        rev[y] = (str)[i];
    }
    rev[len] = '\0';
    if (to_free)
        free(str);
    return rev;
}

int STR_getnbr(char *str)
{
    int sign = 1;
    int nb = 0;

    for (int i = 0; str[i] != '\0'; ++i) {
        while (!is_num(str[i]))
            ++i;
        if (str[i] == '-' || str[i] == '+') {
            if (str[i] == '-')
                sign *= -1;
        } else {
            nb = (nb * 10) + (str[i] - '0');
        }
    }
    return nb * sign;
}

void STR_upcase(char **str)
{
    for (uint_t i = 0; (*str)[i] != '\0'; ++i)
        if ((*str)[i] >= 'a' && (*str)[i] <= 'z')
            (*str)[i] -= 32;
}

void STR_lowcase(char **str)
{
    for (uint_t i = 0; (*str)[i] != '\0'; ++i)
        if ((*str)[i] >= 'A' && (*str)[i] <= 'Z')
            (*str)[i] += 32;
}

void STR_capitalize(char **str)
{
    for (uint_t i = 0; (*str)[i] != '\0'; ++i) {
        if ((*str)[i + 1] != '\0' && ((*str)[i] == ' ' || (*str)[i] == '-'))
            if ((*str)[i + 1] >= 'a' && (*str)[i + 1] <= 'z')
                (*str)[i + 1] -= 32;
    }
}