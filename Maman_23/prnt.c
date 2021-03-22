#include <string.h> /* strcpy(), strcat() */
#include <stdlib.h> /* system() */

#define CUT ("cut -f 1 ")
#define DOT (".c")

/* gcc -ansi -Wall -pedantic -o prnt prnt.c */

int main(int argc, char ** argv)
{
    char name[100] = {0};

    system("clear");

    /******************************************************************************
    **                                                                           **
    ** Hello and Welcome :)                                                      **
    ** This file is a very special file!!                                        **
    ** I bet by now you must be wondering what is so special about this one...   **
    ** Right?                                                                    **
    **                                                                           **
    ** Well this file, after being compiled, creates an executable file          **
    ** that prints out to the stdout, the contents of it's source file.          **
    ** ME!!!                                                                     **
    **                                                                           **
    ** Think about it this way: If it wouldn't have done it...                   **
    ** You wouldn't have read what you just read LOL                             **
    **                                                                           **
    ******************************************************************************/

    /* Putting the "cut" command line command into a buffer */
    strcpy(name, CUT);

    /* Contcatenate the name of the file to the buffer */
    strcat(name, argv[0]);

    /* Contcatenate the ending ".c" to the buffer */
    strcat(name, DOT);

    /* Running the "cut" command in the command line, using "system" */
    system(name);

    return (0);
}

