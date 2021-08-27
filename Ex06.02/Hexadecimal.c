#include <stdio.h>
#include "Hexadecimal.h"

void PrintHex(void *address, size_t size)
{
    for (size_t count = 0; count < size; count++) {
        printf("%02x \n", *((unsigned char *) address + count));
    }
    printf("\n");
}