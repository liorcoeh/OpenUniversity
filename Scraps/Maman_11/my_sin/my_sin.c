#include <stdio.h>  /* printf() */
#include <stdlib.h> /* exit() */

#include "my_sin.h"

#define PRECISION (0.000001)

double my_sin(double x)
{
    double result = 0;
    double num = 3;
    double sign = -1;
    double counter = 1;
    double temp = x;

    while (temp > PRECISION || temp < (sign * PRECISION))
    {
        result += temp;
        temp = (pow(x, num) / factorial(num));

        temp *= pow(sign, counter);
        ++counter;
        num += 2;
    }

    return (result);
}

double pow(double base, double power)
{
    double result = 1;

    while (power)
    {
        result *= base;
        --power;
    }

    return (result);
}

double factorial(double num)
{
    double result = 1;

    if (num < 0)
    {
        printf("Can't have a negative number in a factorial\n");
        exit(1);
    }

    while (num)
    {
        result *= num;
        --num;
    }

    return (result);
}