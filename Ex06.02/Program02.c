#include "Hexadecimal.h"

int main(void)
{
    int integer1 = 0x112233;
    int integer2 = 23;
    char character1 = 'A';
    char character2 = 'B';
    char character3 = 'a';

    PrintHex(&integer1, sizeof(integer1));
    PrintHex(&integer2, sizeof(integer2));
    PrintHex(&character1, sizeof(character1));
    PrintHex(&character2, sizeof(character2));
    PrintHex(&character3, sizeof(character3));
    return 0;
}