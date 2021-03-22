#include <stdio.h>  /* printf() */
#include <stdlib.h> /* system() */

#include "myText.h"

int main()
{
    Buffer* buffer = NULL;
    int choice = 0;
    int check = 0;

    system("clear");

    choice = choiceMaking();

    askForInput(choice);

    buffer = createBuffer();

    check = readText(choice, buffer);
    printText(choice, buffer);

    errorMessage(check);

    destroyBuffer(choice, buffer);

    return (0);
}