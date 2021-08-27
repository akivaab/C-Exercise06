#include <stdio.h>
#include <string.h>
#include "Binary.h"

void PrintBin(void *address, size_t size)
{
    char buffer[9];
    for (size_t count = 0; count < size; count++) {
        _itoa_s(*((unsigned char *)address + count), buffer, 9, 2);

        char bufferCopy[9];
        if (strlen(buffer) < 8)
        {
            
            int i;
            for (i = 0; i < 8 - strlen(buffer); ++i)
            {
                bufferCopy[i] = '0';
            }
            bufferCopy[i] = buffer;
        }

        printf("%s\n", bufferCopy);
    }

    printf("\n");
}