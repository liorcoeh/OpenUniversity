#include <stdio.h>  /* printf() */
#include <stdlib.h> /* system() */
#include <math.h>   /* sin()    */

#define PRECISION (0.000001)

/*
 * my_sin: Calculates the sinus of a radian angle according to Taylor series.
 * Receive: double, the radian angle to calculate the sinus for.
 * Return: double, the result.
 */
double my_sin(double x);

/*
 * pow: Calculates the power of a number 'base' by another number 'power'.
 *      Both numbers will be equal to, or largerd than zero.
 * Receive: double, a positive number to activate the power on it.
 *          double, a positive number to count how many times to activate the power.
 * Return: double, the result.
 * 
 * ### I didn't know we could use the build functions so I did it myself ###
 */
double pow(double base, double power);

/*
 * factorial: Calculates the factorial of a given number.
 * Receive: double, the number to calculate the factorial for.
 * Return: double, the result.
 */
double factorial(double num);

/* gcc -Wall -ansi -pedantic -o my_sin my_sin_test.c -lm */

int main()
{
    double x = 0;
    double result = 0;

    system("clear");

    printf("\n\nPlease enter number between -25.0 and 25.0:\n");
    printf("(Remember that the number you are entering is an angle in radians and not in degrees)\n");
    scanf("%lf", &x);

    result = my_sin(x);

    printf("The sinus of %f is: %f\n", x, result);
    printf("The sinus of %f acording to the C math function is: %f\n", x, sin(x));

    return (0);
}

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