#ifndef _BINARY_H_
#define _BINARY_H_
#include <stdlib.h>

/**
 * @file Binary Representation
*/

/**
 * @brief Print the binary representation of a variable.
 *
 * @param address the address of the variable in memory
 * @param size the size, in bytes, of the variable
*/
void PrintBin(void *address, size_t size);

#endif

