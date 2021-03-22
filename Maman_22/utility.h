#ifndef UTILITY_H
#define UTILITY_H

#include "set.h"

#define BUFFER_SIZE (1000)
#define SET_NAME_SIZE (4)

typedef enum NUMBER_OF_SETS
{
    ZERO = 0,
    ONE = 1,
    THREE = 3
} AMOUNT_OF_SETS;

typedef enum SET_NAMES
{
    ERROR = 0,
    E_SETA,
    E_SETB,
    E_SETC,
    E_SETD,
    E_SETE,
    E_SETF
} SET_NAMES;

/*******************************************************************************
*********************    FUNCTIONS FOR THE SET FILES    ************************
*******************************************************************************/

/*
 * initializeSet: Initializes a given set to be empty.
 * Receive: Pointer to the group.
 * Return: Nothing.
 */
void initializeSet(set *group);

/*
 * insertFromAtoB: Copies the data from one set into another set.
 * Receive: Pointer to the set to get the data from.
 *          Pointer to the set to put the data into.
 * Return: Nothing.
 */
void insertFromAtoB(set *a_group, set *b_group);


/*******************************************************************************
**************************    GENERAL FUNCTIONS    *****************************
*******************************************************************************/

void mainHandler(set sets[]);

/*
 * getLine: Gets a line from the input and inserts it into a buffer.
 * Receive: Pointer to the buffer to insert the data into.
 * Return: Nothing.
 */
void getLine(char *buffer);

void isStop(char *buffer);

/*
 * checkFuncName: Checks what is the function name given in the input.
 *                In case there is no valid function name, will print an error
 *                and return.
 * Receive: Pointer to the buffer where the input to check is.
 * Return: Nothing.
 */
void getFuncName(char *buffer, char* func_name);



/*
 * getGroupName: Checks what is the group name that is given in the input, and
 *               inserts it into a buffer.
 *               In case there is no valid group name will print an error.
 * Receive: Pointer to a buffer to put the group name into.
 *          Pointer to the buffer where the input to check is.
 *          int, the index of the buffer where to check.
 * Return: 0 if there was a valid group name.
 *         1 if there wasn't a valid group name.
 */
SET_NAMES getGroupName(char *buffer, int index);

/*
 * fillNumsArray: Fills a given array with the data given from the input buffer.
 *                In case there is a problem with the data, will print an error.
 * Receive: Pointer to the buffer where the input to check is.
 *          Pointer to the array to insert the input into.
 * Return: 0 if the input is valid.
 *         1 if there was an error in the input.
 */
int fillNumsArray(char *buffer, int arr[]);

#endif /* UTILITY_H */