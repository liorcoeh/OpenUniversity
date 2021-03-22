
typedef struct BufferStruct Buffer;

/**************************************************************************
*************************** THE MAIN FUNCTIONS ****************************
**************************************************************************/

/*
 * choiceMaking: Prints out a request for the user to choose the type of
 *               data base he want's to use.
 * Receive: Nothing.
 * Return: int, the user's choice.
 */
int choiceMaking();

/*
 * askForInput: If the user made a valid choice, asks him to insert text.
 * Receive: int, the user's choice.
 * Return: Nothing.
 */
void askForInput(int choice);

/*
 * readText: Reads text from standart input and saves it into a data base.
 * Receive: The type of data base to save the text into.
 *          Pointer to the data base to save the text into.
 * Return: If all the text was saved return 0.
 *         If there was no more space and not all the text was saved
 *         it will return 1 -> error.
 */
int readText(int choice, Buffer* buffer);

/*
 * printText: Prints the saved text from the data base into the starndart
 * output. Each line of the print will be 60 characters long exactly,
 * except maybe, the last line.
 * Receive: The type of data base to print the text from.
 *          Pointer to the data base to print the text from.
 * Return: Nothing.
 */
void printText(int choice, Buffer* buffer);

/*
 * errorMessage: In case there was an error in allocating more space will
 *               print out an error message.
 * Receive: int, the status from the "readText" function.
 * Return: Nothing.
 */
void errorMessage(int check);

/*
 * createBuffer: Creates a data base buffer.
 * Receive: Nothing.
 * Return: Pointer to the beggining of the buffer.
 *         If the allocation failed, will return NULL.
 */
Buffer* createBuffer();

/*
 * destroyBuffer: Frees all the allocated memory of the buffer.
 * Receive: int, the use choice of which data base to use.
 *          Pointer to the buffer to free.
 * Return: Nothing.
 */
void destroyBuffer(int choice, Buffer* buffer);