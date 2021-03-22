#include <stdio.h>
#include <string.h> /* memset() */

#include "set.h"
#include "utility.h"

int main()
{
    set SETA = {0};
    set SETB = {0};
    set SETC = {0};
    set SETD = {0};
    set SETE = {0};
    set SETF = {0};

    set sets[6] = {0};

    set *first_group_name = NULL;
    SET_NAMES set_name = ERROR;

    char c = 0;
    char buffer[BUFFER_SIZE] = {0};
    char func_name[15] = {0};

    int values_arr[1000] = {0};

    int i = 0;
    int set_amount = 0;
    int check = 0;
    int valid = 0;
    int counter = 0;
    int comma_counter = 0;

    sets[0] = SETA;
    sets[1] = SETB;
    sets[2] = SETC;
    sets[3] = SETD;
    sets[4] = SETE;
    sets[5] = SETF;

    mainHandler(sets);

    /* Main loop to get the input 
    while ((c = getchar()) != EOF)
    {
         Handling a line from the input 
        if (c == '\n')
        {
            getFuncName(buffer, func_name);

            if (strcmp(func_name, "read_set") == 0)
            {
                set_name = getGroupName(buffer, 9);
                valid = 0;

                switch (set_name)
                {
                    case (E_SETA):
                        first_group_name = &SETA;
                        break;

                    case (E_SETB):
                        first_group_name = &SETB;
                        break;

                    case (E_SETC):
                        first_group_name = &SETC;
                        break;

                    case (E_SETD):
                        first_group_name = &SETD;
                        break;

                    case (E_SETE):
                        first_group_name = &SETE;
                        break;

                    case (E_SETF):
                        first_group_name = &SETF;
                        break;

                    default:
                        valid = 1;
                }

                if (valid == 0)
                {
                    valid = fillNumsArray(buffer, values_arr);
                    if (valid == 0)
                    {
                        printf("%s %d\n", func_name, set_name);

                        read_set(first_group_name, values_arr);
                        print_set(first_group_name);
                    }
                }
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


            memset(buffer, 0, BUFFER_SIZE);
            i = 0;
            check = 0;
        }
         Ignoring all blank spaces at the beggining of a line 
        else if (check == 0 && (c == ' ' || c == '\t'))
        {
            ;
        }

         Counting amount of dashes between valid datas 
        else if (c == ',')
        {
            ++comma_counter;
        }

         Not blank, inserting into the buffer 
        else if (c != ' ' && c != '\t')
        {
             Replacing all the blank spaces with one space (' ') 
            if (counter > 0)
            {
                buffer[i] = ' ';
                ++i;
                counter = 0;
            }

            buffer[i] = c;
            ++i;
            check = 1;
        }

         Counting amount of blank spaces after valid data 
        else if (check == 1 && (c == ' ' || c == '\t'))
        {
            ++counter;
        }

    }

     Making sure that there is no stop function request before EOF was given 
    isStop(buffer);

     If there was no stop function request will print an error 
    printf("Exit error - EOF\n\n"); */

    return (0);
}