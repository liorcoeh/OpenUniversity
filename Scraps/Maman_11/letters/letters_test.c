#include <stdlib.h> /* system() */

#include "letters.h"

/* gcc -Wall -ansi -pedantic -o letters letters_test.c letters.c */

int main()
{
    char *buffer = NULL;

    system("clear");

    buffer = createBuffer();

    instructionsMessage();

    buffer = GetInput(buffer);

    UpdateInput(buffer);

    printOutBuffer(buffer);

    destroyBuffer(buffer);

    return (0);
}