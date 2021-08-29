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

/**
 * @brief Print zeros before the binary number so 8 digits appear total.
 * 
 * @param binaryStr string representation of a binary value 
 * 
 * @return the index after the zeros
*/
int PrintFrontZeros(char binaryStr[]);

/**
 * @brief Fill in digits after the zeros so there are 4 total, followed by a space.
 * 
 * @param binaryStr string representation of a binary value
 * @param endZerosIndex index after the zeros
 * 
 * @return the index after the space
*/
int FillFirstFourDigits(char binaryStr[], int endZerosIndex);

/**
 * @brief Print the remaining 4 digits. 
 * 
 * @param binaryStr string representation of a binary value 
 * @param spaceIndex index after the space
*/
void PrintEndFourDigits(char binaryStr[], int spaceIndex);

#endif

