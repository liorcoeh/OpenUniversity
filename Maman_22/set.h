#ifndef SET_H
#define SET_H

#define BYTE_SIZE (8)
#define BYTES_AMOUNTS (16)
#define END (-1)

typedef struct DataType
{
    char numbers[BYTES_AMOUNTS];
} set;

/*
 * read_set: Inserts values into a given set.
 *           If a value is repeated it will disregard repeated values.
 * Receive: Pointer to the set to put the values in it.
 *          Array of the values to insert into the set.
 * Return: Nothing.
 */
void read_set(set *group, int arr[]);

/*
 * print_set: Prints the values from a given set.
 * Receive: Pointer to the set.
 * Return: Nothing.
 */
void print_set(set *group);

/*
 * union_set: Takes all the values from two sets and puts them into
 *            a third set. If there are duplicates, disregards them.
 * Receive: Pointer to the first set to take values from.
 *          Pointer to the second set to take values from.
 *          Pointer to the third set, to put the result in it.
 * Return: Nothing.
 */
void union_set(set *a_group, set *b_group, set *c_group);

/*
 * intersect_set: Takes all the values that are the same from two sets
 *                and puts them into a third set.
 * Receive: Pointer to the first set to take values from.
 *          Pointer to the second set to take values from.
 *          Pointer to the third set, to put the result in it.
 * Return: Nothing.
 */
void intersect_set(set *a_group, set *b_group, set *c_group);

/*
 * sub_set: Takes all the values that are in one set and are not
 *          in a second set, and puts them into a third set.
 * Receive: Pointer to the first set to take values from.
 *          Pointer to the second set to take values from.
 *          Pointer to the third set, to put the result in it.
 * Return: Nothing.
 */
void sub_set(set *a_group, set *b_group, set *c_group);

/*
 * sub_set: Takes all the values that are in one set OR a second
 *          set, but not in both of these sets, and puts them into
 *          a third set.
 * Receive: Pointer to the first set to take values from.
 *          Pointer to the second set to take values from.
 *          Pointer to the third set, to put the result in it.
 * Return: Nothing.
 */
void symdiff_set(set *a_group, set *b_group, set *c_group);

/*
 * stop: Terminates the program immediately.
 * Receive: Nothing.
 * Return: Nothing.
 */
void stop();

#endif /* SET_H */