#ifndef _HEXADECIMAL_H_
#define _HEXADECIMAL_H_
#include <stdlib.h>

/**
 * @file Hexadecimal Representation
*/

/**
 * @brief Print the hexadecimal representation of a variable.
 * @param address the address of the variable in memory
 * @param size the size, in bytes, of the variable
*/
void PrintHex(void *address, size_t size);

#endif
