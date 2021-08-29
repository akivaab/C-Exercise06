#include <stdio.h>
#include "LinkedList.h"

int main(void)
{
    List *list = CreateList();
    printf("%zu\n", GetListSize(list));
    PushBack(list, 1);
    PushBack(list, 2);
    PushFront(list, 3);
    printf("%zu\n", GetListSize(list));
    int val = PopBack(list);
    printf("%zu\n", GetListSize(list));
    printf("%d\n", val);
    FreeList(list);
    printf("%zu\n", GetListSize(list));
    printf("%d\n", GetLastLinkedListError());

    return 0;
}