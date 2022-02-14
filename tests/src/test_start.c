
#include <criterion/criterion.h>
#include "functions.h"
#include <stdio.h>

Test(get_size, test_get_size)
{
    cr_assert_eq(-1, get_size("bad_file.txt"));
    cr_assert_eq(1432, get_size("Makefile"));
}