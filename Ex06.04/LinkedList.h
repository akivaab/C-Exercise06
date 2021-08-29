#ifndef _LINKED_LIST_H_
#define _LINKED_LIST_H_
#include <stdlib.h>

typedef int ListDataType;
typedef struct Node_t Node;
typedef struct Node_t
{
    ListDataType val;
    Node *next;
    Node *previous;
} Node;

typedef struct List_t
{
    Node *head;
} List;

List *CreateList(void);

void FreeList(List *list);

size_t GetListSize(List *list);

Node *GetListHead(List *list);

Node *GetNextNode(Node *currentNode);

ListDataType GetValue(Node *node);

Node *Insert(Node *after, ListDataType newValue);

Node *PushFront(List *list, ListDataType newValue);

Node *PushBack(List *list, ListDataType newValue);

ListDataType PopFront(List *list);

ListDataType PopBack(List *list);

void DeleteNode(List *list, Node *target);

Node *DeleteValue(List *list, ListDataType value);

Node * Find(List * list, ListDataType value);

int GetLastLinkedListError(void);

#endif