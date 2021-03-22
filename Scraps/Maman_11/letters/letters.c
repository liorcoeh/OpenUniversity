#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "letters.h"

#define BUFFER_SIZE (10)

/**************************************************************************
****************** SUPPORT FUNCTIONS DECLARATIONS *************************
**************************************************************************/

/* resizeBuffer: Changes the size of a buffer, to add to it another
 *               BUFFER_SIZE memory space.
 * Receive: Pointer to the buffer to reallocate.
 *          int, the current size memory of the given buffer.
 * Return: Pointer to the reallocated buffer.
 */     
static char* resizeBuffer(char* buffer, int new_size);

/*
 * IsFirstLetterToUpperCase: Checks if the first character input should
 *                           be uppercase or not.
 * Receive: char, the character to check.
 * Return: 1 if needs to change to uppercase, 0 if not.
 */
static int IsFirstLetterToUpperCase(char c);

/*
 * ShouldUpperCaseAfterPoint: Checks if a character should be uppercase
 *                            after a point character.
 * Receive: char, the charcter to check.
 *          int, a flag that shows is there is quatation mark before the
 *          point character.
 * Return: 1 if needs to change to uppercase, 0 if not.
 */
static int ShouldUpperCaseAfterPoint(char c, int quotation_marks_on);

/*
 * ShouldUpperCaseInQuotationMarks: Checks if a character should be upercase
 *                                  when there is a quoatation mark.
 * Recieve: char, the character to check.
 * Return: 1 if needs to change to uppercase, 0 if not
 */
static int ShouldUpperCaseInQuotationMarks(char c);

/*
 * IsNotADigit: Checks if a character given is not a digit.
 * Receive: char, the charcter to check.
 * Return: 1 if it is not a digit, 0 if it is.
 */
static int IsNotADigit(char c);


/**************************************************************************
*************************** THE MAIN FUNCTIONS ****************************
**************************************************************************/

char* createBuffer()
{
    char* new_buffer = (char*)malloc(sizeof(char) * BUFFER_SIZE);
    if (!new_buffer)
    {
        printf("Failed to create a buffer\n");
        exit (1);
    }

    return (new_buffer);
}

/*************************************************************************/

void destroyBuffer(char* buffer)
{
    free(buffer);
    buffer = NULL;
}

/*************************************************************************/

void instructionsMessage()
{
    printf("Hello and Welcome :)\n");
    printf("Please enter a text input:\n\n");
}

/*************************************************************************/

char* GetInput(char* buffer)
{
    char c = 0;
    int i = 0;

    while ((c = getchar()) != EOF)
    {
        if (IsNotADigit(c))
        {
            buffer[i] = c;
            ++i;
        }

        /* If the index reached the end of the buffer - resize it */
        if (i != 0 && (i % BUFFER_SIZE) == 0)
        {
            buffer = resizeBuffer(buffer, i + BUFFER_SIZE);
        }
    }

    buffer[i] = EOF;

    return (buffer);
}

/*************************************************************************/

char* UpdateInput(char* buffer)
{
    int i = 0;
    int quotation_marks_on = 0;

    /* Dealing with the case of the first letter in the whole text */
    if (IsFirstLetterToUpperCase(buffer[i]))
    {
        buffer[i] = toupper(buffer[i]);
    }
    ++i;

    while (buffer[i] != EOF)
    {
        quotation_marks_on = ShouldUpperCaseInQuotationMarks(buffer[i]);
        if (quotation_marks_on)
        {
            buffer[i] = toupper(buffer[i]);
        }
        else
        {
            buffer[i] = tolower(buffer[i]);
        }

        if (ShouldUpperCaseAfterPoint(buffer[i], quotation_marks_on))
        {
            buffer[i] = toupper(buffer[i]);
        }

        ++i;
    }

    buffer[i] = EOF;

    return (buffer);
}

/*************************************************************************/

void printOutBuffer(char* output)
{
    int i = 0;

    printf("\n\n==== Your updated input is: ====\n\n");
    while (output[i] != EOF)
    {
        printf("%c", output[i]);
        ++i;
    }
    printf("\n\n");
}

/**************************************************************************
****************** SUPPORT FUNCTIONS DECLARATIONS *************************
**************************************************************************/


static char* resizeBuffer(char* buffer, int new_size)
{
    buffer = (char*)realloc(buffer, new_size);
    if (!buffer)
    {
        printf("Failed to resize the buffer\n");
        exit(1);
    }

    return (buffer);
}

/*************************************************************************/

static int IsFirstLetterToUpperCase(char c)
{
    return (c >= 'a' && c <= 'z');
}

/*************************************************************************/

static int ShouldUpperCaseAfterPoint(char c, int quotation_marks_on)
{
    static int on_flag = 0;

    if (quotation_marks_on == 1)
    {
        on_flag = 0;
        return (0);
    }

    if (c == '.')
    {
        on_flag = 1;
    }

    if (on_flag == 1 && ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')))
    {
        on_flag = 0;
        return (1);
    }

    return (0);
}

/*************************************************************************/

static int ShouldUpperCaseInQuotationMarks(char c)
{
    static int quotation_marks_flag = 0;

    if (c == '"' && quotation_marks_flag == 0)
    {
        quotation_marks_flag = 1;
    }
    else if (c == '"' && quotation_marks_flag == 1)
    {
        quotation_marks_flag = 0;
    }
    else if (quotation_marks_flag == 1 && ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')))
    {
        return (1);
    }
    else if (quotation_marks_flag == 0 && ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')))
    {
        return (0);
    }

    return (0);
}

/*************************************************************************/

static int IsNotADigit(char c)
{
    return (c < '0' || c > '9');
}