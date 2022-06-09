/*
** EPITECH PROJECT, 2020
** delivery
** File description:
** usage
*/

#include "../include/runner.h"

int help(void)
{
    printf("Finite runner created with CSFML.\n\n");
    printf("USAGE\n");
    printf(" ./my_runner map.txt\n\n\n");
    printf("OPTIONS\n");
    printf(" -i                launch the game in infinity mode.\n");
    printf(" -h                print the usage and quit.\n\n");
    printf("USER INTERACTIONS\n");
    printf(" SPACE_KEY        jump.\n");
    printf("to create a map used : 1 2 3 for the ");
    printf("ground and 0 for spaces between platforms\n");
    printf("don't use 0 at the start of the second and third line\n");
    printf("if you touch the void you lose\n");
    printf("play well !\n");
    return (0);
}
