#include <stdio.h>  /* EOF, printf() */
#include <string.h> /* memset() */
#include <stdlib.h> /* malloc() */

#include "utility.h"
#include "set.h"

/*******************************************************************************
*********************    FUNCTIONS FOR THE SET FILES    ************************
*******************************************************************************/

void initializeSet(set *group)
{
    int i = 0;

    for (i = 0; i < 16; ++i)
    {
        group->numbers[i] = 0;
    }
}

/******************************************************************************/

void insertFromAtoB(set *a_group, set *b_group)
{
    int bit = 0;
    int byte = 0;

    /* Inserting into c_group from TEMP */
    while (byte < 16 && bit < 8)
    {
        if (a_group->numbers[byte] & (1 << bit))
        {
            b_group->numbers[byte] |= (1 << bit);
        }
        
        ++bit;

        if (bit % BYTE_SIZE == 0)
        {
            ++byte;
            bit = 0;
        }
    }
}


/*******************************************************************************
**************************    GENERAL FUNCTIONS    *****************************
*******************************************************************************/

static void printArr(int arr[])
{
    int i = 0;

    printf("\n\n");
    while (arr[i] != -1)
    {
        printf("%d -> ", arr[i]);
        ++i;
    }
    printf("\n\n");
}


void mainHandler(set sets[])
{
    char c = 0;
    char buffer[BUFFER_SIZE] = {0};
    char func_name[15] = {0};

    int spaces_check = 0;
    int spaces_counter = 0;

    int comma_check = 0;
    int comma_counter = 0;
    int comma_error = 0;

    int i = 0;

    while ((c = getchar()) != EOF)
    {
        /* Handling a line from the input */
        if (c == '\n')
        {
            printf("%s\n", buffer);
            
            if (comma_error == 1)
            {
                printf("Missing comma\n");
            }
            else if (comma_error == 2)
            {
                printf("Multiple consecutive commas\n");
            }
            else
            {
                getFuncName(buffer, func_name);

                if (strcmp(func_name, "read_set") == 0)
                {
                    printf("read_set\n");
                }
                else if (strcmp(func_name, "print_set") == 0)
                {
                    printf("print_set\n");
                }
                else if (strcmp(func_name, "union_set") == 0)
                {
                    printf("union_set\n");
                }
                else if (strcmp(func_name, "intersect_set") == 0)
                {
                    printf("intersect_set\n");
                }
                else if (strcmp(func_name, "sub_set") == 0)
                {
                    printf("sub_set\n");
                }
                else if (strcmp(func_name, "symdiff_set") == 0)
                {
                    printf("symdiff_set\n");
                }
                else
                {
                    printf("Undefined command name\n");
                }
            }
            
            memset(buffer, 0, BUFFER_SIZE);
            i = 0;

            spaces_check = 0;

            comma_check = 0;
            comma_error = 0; 
        }

        /* Ignoring all blank spaces at the beggining of a line */
        else if (spaces_check == 0 && (c == ' ' || c == '\t'))
        {
            ;
        }

        /* Counting all the blank spaces after input */
        else if (c == ' ' || c == '\t')
        {
            ++spaces_counter;
        }

        /* Counting amount of commas between valid inputs */
        else if (c == ',' && comma_check == 1)
        {
            printf("HERE\n");
            ++comma_counter;
        }

        else
        {
            if (comma_check == 1 && comma_counter == 0)
            {
                comma_error = 1;
                comma_check = 2;
            }
            else if (comma_check == 1 && comma_counter > 1)
            {
                comma_error = 2;
                comma_check = 2;
            }
            /* Replacing all the blank spaces with one space (' ') */
            if (spaces_counter > 0)
            {
                buffer[i] = ' ';
                ++i;
                spaces_counter = 0;
            }

            buffer[i] = c;
            ++i;

            spaces_check = 1;

            if (comma_error == 0)
            {
                comma_check = 1;
                comma_counter = 0;
            }
        }
    }
}


/* read_set SETA, 15, 6, 5, 76, 44, 23, 23, 98, 23, -1 */


void getFuncName(char *buffer, char* func_name)
{
    int i = 0;

    while (buffer[i] != ' ')
    {
        func_name[i] = buffer[i];
        ++i;
    }
    func_name[i] = '\0';

    /* Checking if the stop function was given */
    isStop(func_name);
}


void isStop(char *buffer)
{
    if (strcmp(buffer, "stop") == 0)
    {
        printf("Exiting the program (the right way)\n");
        stop();
    }
}

/* read_set SETA15, 6, 5, 76, 44, 23, 23, 98, 23, -1 */

SET_NAMES getGroupName(char *buffer, int index)
{
    char group_name[5] = {0};
    SET_NAMES name = ERROR;

    int i = 0;

    while (i < SET_NAME_SIZE)
    {
        group_name[i] = buffer[index];
        ++i;
        ++index;
    }

    if (strcmp(group_name, "SETA") == 0)
    {
        name = E_SETA;
    }
    else if (strcmp(group_name, "SETB") == 0)
    {
        name = E_SETB;
    }
    else if (strcmp(group_name, "SETC") == 0)
    {
        name = E_SETC;
    }
    else if (strcmp(group_name, "SETD") == 0)
    {
        name = E_SETD;
    }
    else if (strcmp(group_name, "SETE") == 0)
    {
        name = E_SETE;
    }
    else if (strcmp(group_name, "SETF") == 0)
    {
        name = E_SETF;
    }
    else
    {
        printf("Undefined set name\n");
        name = ERROR;
    }

    return (name);
}

int fillNumsArray(char *buffer, int arr[])
{
    char num[4] = {0};
    int i = 0;
    int comma_counter = 0;
    int check = 0;

    int arr_index = 0;
    int index = 13;

    /*if (buffer[index] != )*/

    printf("%s\n", buffer);

    while (buffer[index] != '-' && buffer[index + 1] != '1')
    {
        if (buffer[index] >= '0' && buffer[index] <= '9')
        {
            num[i] = buffer[index];
            ++i;
        }
        else if (buffer[index] == ' ')
        {
            if (comma_counter == 0)
            {
                printf("Missing comma\n");
                return (1); /* Failure */
            }

            i = 0;

            arr[arr_index] = atoi(num);

            if (check != 0)
            {
                ++arr_index;
            }
            check = 1;

            memset(num, 0, 4);
            comma_counter = 0;
        }
        else
        {
            ++comma_counter;
        }

        ++index;

        if (comma_counter > 1)
        {
            printf("Multiple consecutive commas\n");
            return (1); /* Failure */
        }
    }

    arr[arr_index] = -1;

    return (0); /* Success */
}