#include <stdio.h>  /* printf() */
#include <stdlib.h> /* exit()   */

#include "set.h"
#include "utility.h"

#define MAX_IN_LINE (16)

void read_set(set *group, int arr[])
{
    int i = 0;
    int bit = 0;
    int byte = 0;

    initializeSet(group);

    /* As long as the value in the array isn't END (-1) continue    */
    while (arr[i] != END)
    {
        /* Getting the number of the byte to work on between 0 - 15 */
        byte = arr[i] / BYTE_SIZE;

        /* Getting the bit to work on, in the byte, between 0 - 7   */
        bit = arr[i] % BYTE_SIZE;

        /* Set the bit on even if it is already set, this way       */
        /* it disregards duplicated values in the array             */
        group->numbers[byte] |= (1 << bit);

        ++i;
    }
}

/******************************************************************************/

void print_set(set *group)
{
    int bit = 0;
    int byte = 0;

    int num = 0;
    int counter = 0;

    while (byte < BYTES_AMOUNTS && bit < BYTE_SIZE)
    {
        if (group->numbers[byte] & (1 << bit))
        {
            num = byte * BYTE_SIZE + bit;
            printf("%d ", num);
            ++counter;
        }

        if (counter == MAX_IN_LINE)
        {
            printf("\n");
            counter = 0;
        }

        ++bit;

        if (bit % BYTE_SIZE == 0)
        {
            ++byte;
            bit = 0;
        }
    }

    printf("\n\n");
}

/******************************************************************************/

void union_set(set *a_group, set *b_group, set *c_group)
{
    /* Creating a TEMP set, in case that one of the groups given is */
    /* equal to another given. So the data wont be erased           */
    set TEMP = {0};

    int bit = 0;
    int byte = 0;

    /* Running on a_group and b_group and inserting into TEMP when a_group  */
    /* is true OR (||) when b_group is true                                 */
    while (byte < BYTES_AMOUNTS && bit < BYTE_SIZE)
    {
        if ((a_group->numbers[byte] & (1 << bit)) ||
                        (b_group->numbers[byte] & (1 << bit)))
        {
            TEMP.numbers[byte] |= (1 << bit);
        }

        ++bit;

        if (bit % BYTE_SIZE == 0)
        {
            ++byte;
            bit = 0;
        }
    }

    initializeSet(c_group);

    insertFromAtoB(&TEMP, c_group);
}

/******************************************************************************/

void intersect_set(set *a_group, set *b_group, set *c_group)
{
    /* Creating a TEMP set, in case that one of the groups given is */
    /* equal to another given. So the data wont be erased           */
    set TEMP = {0};

    int bit = 0;
    int byte = 0;

    /* Running on a_group and b_group and inserting into TEMP when both */
    /* a_group and b_group is true                                      */
    while (byte < BYTES_AMOUNTS && bit < BYTE_SIZE)
    {
        if ((a_group->numbers[byte] & (1 << bit)) &&
                        (b_group->numbers[byte] & (1 << bit)))
        {
            TEMP.numbers[byte] |= (1 << bit);
        }

        ++bit;

        if (bit % BYTE_SIZE == 0)
        {
            ++byte;
            bit = 0;
        }
    }

    initializeSet(c_group);

    insertFromAtoB(&TEMP, c_group);
}

/******************************************************************************/

void sub_set(set *a_group, set *b_group, set *c_group)
{
    /* Creating a TEMP set, in case that one of the groups given is */
    /* equal to another given. So the data wont be erased           */
    set TEMP = {0};

    int bit = 0;
    int byte = 0;

    /* Running on a_group and b_group and inserting into TEMP when a_group  */
    /* is true AND (&&) b_group IS NOT (!) true                             */
    while (byte < BYTES_AMOUNTS && bit < BYTE_SIZE)
    {
        if ((a_group->numbers[byte] & (1 << bit)) &&
                        !(b_group->numbers[byte] & (1 << bit)))
        {
            TEMP.numbers[byte] |= (1 << bit);
        }

        ++bit;

        if (bit % BYTE_SIZE == 0)
        {
            ++byte;
            bit = 0;
        }
    }

    initializeSet(c_group);

    insertFromAtoB(&TEMP, c_group);
}

/******************************************************************************/

void symdiff_set(set *a_group, set *b_group, set *c_group)
{
    /* Creating a TEMP set, in case that one of the groups given is */
    /* equal to another given. So the data wont be erased           */
    set TEMP = {0};

    int bit = 0;
    int byte = 0;

    /* Running on a_group and b_group and inserting into TEMP when either   */
    /* a_group is true and b_group isn't true OR a_group isn't ture and     */
    /* b_group is true                                                      */
    while (byte < BYTES_AMOUNTS && bit < BYTE_SIZE)
    {
        if (((a_group->numbers[byte] & (1 << bit)) &&
                            !(b_group->numbers[byte] & (1 << bit))) ||
            (!(a_group->numbers[byte] & (1 << bit)) &&
                            (b_group->numbers[byte] & (1 << bit))))
        {
            TEMP.numbers[byte] |= (1 << bit);
        }

        ++bit;

        if (bit % BYTE_SIZE == 0)
        {
            ++byte;
            bit = 0;
        }
    }

    initializeSet(c_group);

    insertFromAtoB(&TEMP, c_group);
}

/******************************************************************************/

void stop()
{
    exit (0);
}