#include <stdio.h>
#include <string.h>
#include "Binary.h"

void PrintBin(void *address, size_t size)
{
    char buffer[9];
    buffer[8] = '\0';
    for (size_t count = 0; count < size; count++) {
        _itoa_s(*((unsigned char *)address + count), buffer, 9, 2);
        int endZerosIndex = PrintFrontZeros(buffer);
        int spaceIndex = FillFirstFourDigits(buffer, endZerosIndex);
        PrintEndFourDigits(buffer, spaceIndex);
        printf("\n");
    }
    printf("\n");
}

int PrintFrontZeros(char binaryStr[])
{
    unsigned int i;
    for (i = 0; i < 8 - strlen(binaryStr); ++i)
    {
        printf("0");
    }
    return i;
}

int FillFirstFourDigits(char binaryStr[], int endZerosIndex)
{
    int i;
    for (i = 0; i < 4 - endZerosIndex; ++i)
    {
        printf("%c", binaryStr[i]);
    }
    printf(" ");
    return i;
}

void PrintEndFourDigits(char binaryStr[], int spaceIndex)
{
    for (unsigned int i = spaceIndex; i < strlen(binaryStr); ++i)
    {
        printf("%c", binaryStr[i]);
    }
}