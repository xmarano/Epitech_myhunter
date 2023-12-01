/*
** EPITECH PROJECT, 2023
** my_atoi
** File description:
** my_inttostr.c
*/
#include "../include/my.h"

char *my_inttostr(int nb)
{
    int size = 1;
    int temp = nb;
    int i;
    char *str;
    int digit;

    for (; temp /= 10; size++)
    str = malloc(size + 1);
    i = size - 1;
    while (nb) {
        digit = nb % 10;
        str[i] = digit + '0';
        nb /= 10;
        i--;
    }
    str[i] = '\0';
    return str;
}
