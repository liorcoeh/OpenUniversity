#include <stdio.h> /* printf() */
#include <stdlib.h> /* calloc(), realloc() */

#include "myText.h"

#define BUFFER_SIZE (90) /* The minimum size of each buffer unit */
#define LINE_SIZE (60)   /* The size of a line to print out */

struct BufferStruct
{
    struct BufferStruct* next;
    char* container;
};


/**************************************************************************
****************** SUPPORT FUNCTIONS DECLARATIONS *************************
**************************************************************************/

/*
 * resizeBuffer: Adds BUFFER_SIZE space to the single buffer when needed.
 * Receive: Pointer to the single buffer.
 *          int, the current size of the buffer.
 * Return: 0 if it was successful.
 *         1 if the allocation failed.
 */
static int resizeBuffer(Buffer* buffer, int current_size);

/*
 * readIntoBuffer: Reads the text from the standart input into the single
 *                 buffer.
 * Receive: Pointer to the buffer to read into.
 * Return: 0 if it was seuccessful.
 *         1 if there was a problem and not all the input was read.
 */
static int readIntoBuffer(Buffer* buffer);

/*
 * printFromBuffer: Print out the info from the single buffer.
 * Receive: Pointer to the buffer to read from.
 * Return: Nothing.
 */
static void printFromBuffer(Buffer* buffer);

/*
 * resizeList: Adds BUFFER_SIZE'd node to the linked list buffer when needed.
 * Receive: Pointer to the buffer.
 * Return: 0 if it was successful.
 *         1 if the allocation failed.
 */
static int resizeList(Buffer* head);

/*
 * readIntoList: Reads the text from the standart input into the linked list
 *               buffer.
 * Receive: Pointer to the buffer to read into.
 * Return: 0 if it was seuccessful.
 *         1 if there was a problem and not all the input was read.
 */
static int readIntoList(Buffer* buffer);

/*
 * printFromList: Print out the info from the linked list buffer.
 * Receive: Pointer to the buffer to read from.
 * Return: Nothing.
 */
static void printFromList(Buffer* buffer);

/**************************************************************************
*************************** THE MAIN FUNCTIONS ****************************
**************************************************************************/

int choiceMaking()
{
    int choice = 0;

    printf("Please choose the way you want to use the data base:\n");
    printf("For a one single buffer, choose 1.\n");
    printf("For a linked list of small buffers, choose 2.\n");
    scanf("%d", &choice);

    return (choice);
}

/*************************************************************************/

int readText(int choice, Buffer* buffer)
{
    int check = 0;

    if (1 == choice)
    {
        check = readIntoBuffer(buffer);
    }
    else if (2 == choice)
    {
        check = readIntoList(buffer);
    }

    return (check);
}

/*************************************************************************/

void printText(int choice, Buffer* buffer)
{
    printf("\n\n");

    if (1 == choice)
    {
        printFromBuffer(buffer);
    }
    else if (2 == choice)
    {
        printFromList(buffer);
    }

    printf("\n\n");
}

/*************************************************************************/

void askForInput(int choice)
{
    printf("\n");
    switch(choice)
    {
        case (1):
            printf("You chose the option of one single buffer.\n");
            break;
        case (2):
            printf("You chose the option of a linked list of buffers.\n");
            break;
        default:
            printf("You have to chose between 1 or 2 only.\n");
            printf("Good Bye\n");
            exit (1);
    }
    
    printf("Please enter your text now.\n\n");
}

void errorMessage(int check)
{
    if (1 == check)
    {
        printf("\n\nThere wasn't enough space for all the input text.\n\n");
    }
}

/*************************************************************************/

Buffer* createBuffer()
{
    Buffer* new_buf = (Buffer*)malloc(sizeof(Buffer));
    if (!new_buf)
    {
        printf("Failed to create buffer\n");
        return (NULL);
    }

    new_buf->next = NULL;

    new_buf->container = (char*)calloc(BUFFER_SIZE, sizeof(char));
    if (!new_buf->container)
    {
        free(new_buf);
        new_buf = NULL;

        printf("Failed to create a buffer\n");
        return (NULL);
    }

    return (new_buf);
}

/*************************************************************************/

void destroyBuffer(int choice, Buffer* buffer)
{
    if (1 == choice)
    {
        free(buffer->container);
        buffer->container = NULL;

        free(buffer);
        buffer = NULL;
    }

    else if (2 == choice)
    {
        if (NULL == buffer)
        {
            return;
        }

        destroyBuffer(choice, buffer->next);

        free(buffer->container);
        buffer->container = NULL;

        free(buffer);
        buffer = NULL;
    }
}


/**************************************************************************
****************** SUPPORT FUNCTIONS DECLARATIONS *************************
**************************************************************************/

/************************ SINGLE BUFFER DATA BASE ************************/


static int resizeBuffer(Buffer* buffer, int current_size)
{
    buffer->container = (char*)realloc(buffer->container, current_size + BUFFER_SIZE);
    if (!buffer->container)
    {
        printf("Failed to resize the buffer\n");
        return (1); /* Failure */
    }

    return (0); /* Success */
}

/*************************************************************************/

static int readIntoBuffer(Buffer* buffer)
{
    char c = 0;
    int i = 0;
    int check = 0;

    while ((c = getchar()) != EOF)
    {
        if ('\n' != c)
        {
            buffer->container[i] = c;
            ++i;
        }

        if ((i % BUFFER_SIZE) == 0)
        {
            check = resizeBuffer(buffer, i);
            if (1 == check)
            {
                buffer->container[i - 1] = EOF;
                return (1); /* Failure */
            }
        }
    }

    buffer->container[i] = EOF;

    return (0); /* Success */
}

/*************************************************************************/

static void printFromBuffer(Buffer* buffer)
{
    int i = 0;

    while (buffer->container[i] != EOF)
    {
        printf("%c", buffer->container[i]);
        ++i;

        if ((i % LINE_SIZE) == 0)
        {
            printf("\n");
        }
    }
}


/************************* LINKED LIST DATA BASE *************************/

static int resizeList(Buffer* head)
{
    if (NULL == head->next)
    {
        head->next = createBuffer();
        if (NULL == head->next)
        {
            return (1); /* Failure */
        }
        
        return (0); /* Success */
    }

    return (resizeList(head->next));
}

/*************************************************************************/

static int readIntoList(Buffer* buffer)
{
    char c = 0;
    int i = 0;
    int check = 0;

    Buffer* iter = buffer;

    while ((c = getchar()) != EOF)
    {
        if ('\n' != c)
        {
            iter->container[i] = c;
            ++i;
        }

        if (i != 0 && (i % BUFFER_SIZE) == 0)
        {
            check = resizeList(iter);
            if (1 == check)
            {
                iter->container[i - 1] = EOF;
                return (1); /* Failure */
            }
            i = 0;

            iter = iter->next;
        }
    }

    iter->container[i] = EOF;

    return (0); /* Success */
}

/*************************************************************************/

static void printFromList(Buffer* buffer)
{
    int i = 0;
    int line_counter = 0;

    Buffer* iter = buffer;

    while (iter->container[i] != EOF)
    {
        printf("%c", iter->container[i]);
        ++i;
        ++line_counter;

        if ((line_counter % LINE_SIZE) == 0)
        {
            line_counter = 0;
            printf("\n");
        }

        if ((i % BUFFER_SIZE) == 0)
        {
            i = 0;
            iter = iter->next;
        }
    }
}