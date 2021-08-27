#include "Binary.h"

int main(void)
{
    int integer1 = 0x11223344;
    int integer2 = 23;
    char character1 = 'A';
    char character2 = 'B';
    char character3 = 'a';

    PrintBin(&integer1, sizeof(integer1));
    PrintBin(&integer2, sizeof(integer2));
    PrintBin(&character1, sizeof(character1));
    PrintBin(&character2, sizeof(character2));
    PrintBin(&character3, sizeof(character3));
    
    return 0;
}