/*
** EPITECH PROJECT, 2020
** Tek1
** File description:
** utilities
*/

#include "../../include/runner.h"

char *int_to_char(int nb)
{
    int len = 0;
    char *str;
    int tmp = nb;

    for (; tmp > 0; len++)
        tmp /= 10;
    str = malloc(sizeof(*str) * (len + 1));
    str[len] = '\0';
    for (; len--; nb /= 10)
        str[len] = nb % 10  + '0';
    return (str);
}

