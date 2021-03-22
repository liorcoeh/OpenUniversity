

/**************************************************************************
*************************** THE MAIN FUNCTIONS ****************************
**************************************************************************/

/*
 * createBuffer: Allocates memory for a buffer the size of BUFFER_SIZE.
 * Receive: Nothing.
 * Return: Pointer to the new allocated buffer.
 */
char* createBuffer();

/*
 * destoryBuffer: Frees all the memory allocated for a given buffer.
 * Receive: Pointer to the buffer.
 * Return: Nothing.
 */
void destroyBuffer(char* buffer);

/*
 * instructionsMessage: Print out a message for the user.
 * Receive: Nothing.
 * Return: Nothing.
 */
void instructionsMessage();

/*
 * GetInput: Function that gets an input from the user and puts it inside
 *           a buffer. The input can be standart input or from a file.
 * Recieve: Pointer to the buffer.
 * Return: Pointer to the buffer with the input inside it.
 */
char* GetInput(char* buffer);

/* 
 * UpdateInput: Function that updates the input into the given requirements.
 * Recieve: Pointer to a buffer with the input in it.
 * Return: Pointer to a new buffer with the updated input in it.
 */
char* UpdateInput(char* input);

/*
 * printOutBuffer: Print out the input inside a buffer.
 * Receive: Pointer to the buffer to print from.
 * Return: Nothing.
 */
void printOutBuffer(char* output);