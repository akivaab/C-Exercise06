#include <stdio.h>
#include "LinkedList.h"

int main(void)
{
    List *list = CreateList();
    printf_s("List size: %zu\n", GetListSize(list));

    Node *node1 = PushBack(list, 1);
    Node *node2 = PushBack(list, 2);
    Node *node3 = PushFront(list, 3);
    Insert(node1, 4);
    printf_s("Value of node2 is: %d\n", GetValue(node2));
    printf_s("List size: %zu\n", GetListSize(list));

    int val = PopBack(list);
    printf_s("Value popped: %d\n", val);
    printf_s("List size: %zu\n", GetListSize(list));

    FreeList(list);

    return 0;
}