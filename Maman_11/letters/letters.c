#include <stdio.h>  /* printf() */
#include <stdlib.h> /* system() */
#include <ctype.h>  /* toupper(), tolower() */


/*******************************************************************************
******************** SUPPORT FUNCTIONS DECLARATIONS ****************************
*******************************************************************************/

/*
 * instructionsMessage: Print out a message for the user.
 * Receive: Nothing.
 * Return: Nothing.
 */
void instructionsMessage();

/*
 * isFirstLetterToUpperCase: Checks if the first character input should
 *                           be uppercase or not.
 * Receive: char, the character to check.
 * Return: 1 if needs to change to uppercase, 0 if not.
 */
int isFirstLetterToUpperCase(char c);

/*
 * shouldUpperCaseInQuotationMarks: Checks if a character should be upercase
 *                                  when there is a quoatation mark.
 * Recieve: char, the character to check.
 * Return: 1 if needs to change to uppercase, 0 if not
 */
int shouldUpperCaseInQuotationMarks(char c);

/*
 * shouldUpperCaseAfterPoint: Checks if a character should be uppercase
 *                            after a point character.
 * Receive: char, the charcter to check.
 *          int, a flag that shows is there is quatation mark before the
 *          point character.
 * Return: 1 if needs to change to uppercase, 0 if not.
 */
int shouldUpperCaseAfterPoint(char c, int quotation_marks_on);



/*******************************************************************************
*********************              MAIN             ****************************
*******************************************************************************/

int main()
{
    char c = 0;
    int quotation_marks_on = 0;

    system("clear");
    instructionsMessage();


    /* Dealing with the case of the first letter in the whole text */
    c = getchar();
    if (isFirstLetterToUpperCase(c) && c != EOF)
    {
        c = toupper(c);
    }
    printf("%c", c);

    while ((c = getchar()) != EOF)
    {
        quotation_marks_on = shouldUpperCaseInQuotationMarks(c);
        if (quotation_marks_on)
        {
            c = toupper(c);
        }
        else
        {
            c = tolower(c);
        }

        if (shouldUpperCaseAfterPoint(c, quotation_marks_on))
        {
            c = toupper(c);
        }

        printf("%c", c);
    }

    printf("\n\n");

    return (0);
}


/*******************************************************************************
******************** SUPPORT FUNCTIONS DEFINITIONS *****************************
*******************************************************************************/

void instructionsMessage()
{
    printf("\n\nHello and Welcome :)\n");
    printf("Please enter a text input:\n\n");
}

/******************************************************************************/

int isFirstLetterToUpperCase(char c)
{
    return (c >= 'a' && c <= 'z');
}

/******************************************************************************/

int shouldUpperCaseInQuotationMarks(char c)
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
    else if (quotation_marks_flag == 1 && ((c >= 'a' && c <= 'z') ||
                                                    (c >= 'A' && c <= 'Z')))
    {
        return (1);
    }
    else if (quotation_marks_flag == 0 && ((c >= 'a' && c <= 'z') ||
                                                    (c >= 'A' && c <= 'Z')))
    {
        return (0);
    }

    return (0);
}

/******************************************************************************/

int shouldUpperCaseAfterPoint(char c, int quotation_marks_on)
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