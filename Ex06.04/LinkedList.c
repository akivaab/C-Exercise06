#include <malloc.h>
#include <stdio.h>
#include "LinkedList.h"

List *CreateList(void)
{
    List *list = (List *)malloc(sizeof(List));
    if (list)
    {
        list->head = NULL;
    }
    else
    {
        printf_s("ERROR: No memory available\n");
    }
    return list;
}

void FreeList(List *list)
{
    if (list)
    {
        Node *node = GetListHead(list);
        if (node)
        {
            while (node)
            {
                Node *nextNode = GetNextNode(node);
                free(node);
                node = nextNode;
            }
        }
        free(list);
    }
    else
    {
        printf_s("ERROR: Passed null parameter\n");
    }
}

size_t GetListSize(List *list)
{
    size_t counter = 0;
    if (list)
    {
        Node *node = GetListHead(list);
        while (node)
        {
            ++counter;
            node = GetNextNode(node);
        }
    }
    else
    {
        printf_s("ERROR: Passed null parameter\n");
    }
    return counter;
}

Node *GetListHead(List *list)
{
    if (list)
    {
        return list->head;
    }
    else
    {
        printf_s("ERROR: Passed null parameter\n");
        return NULL;
    }
}

Node *GetNextNode(Node *currentNode)
{
    if (currentNode)
    {
        return currentNode->next;
    }
    else
    {
        printf_s("ERROR: Passed null parameter\n");
        return NULL;
    }
}

ListDataType GetValue(Node *node)
{
    if (node)
    {
        return node->val;
    }
    else
    {
        printf_s("ERROR: Passed null parameter\n");
        return 0;
    }
}

Node *Insert(Node *after, ListDataType newValue)
{
    if (after)
    {
        Node *afterAfter = GetNextNode(after);
        Node *newNode = (Node *)malloc(sizeof(Node));
        if (newNode)
        {
            newNode->val = newValue;
            newNode->next = afterAfter;
            newNode->previous = after;
            after->next = newNode;
            afterAfter->previous = newNode;
        }
        else
        {
            printf_s("ERROR: No memory available\n");
        }
        return newNode;
    }
    else
    {
        printf_s("ERROR: Passed null parameter\n");
        return NULL;
    }
}

Node *PushFront(List *list, ListDataType newValue)
{
    if (list)
    {
        Node *newNode = (Node *)malloc(sizeof(Node));
        if (newNode)
        {
            newNode->val = newValue;
            newNode->next = GetListHead(list);
            newNode->previous = NULL;
            list->head = newNode;
        }
        else
        {
            printf_s("ERROR: No memory available\n");
        }
        return newNode;
    }
    else
    {
        printf_s("ERROR: Passed null parameter\n");
        return NULL;
    }
}

Node *PushBack(List *list, ListDataType newValue)
{
    if (list)
    {
        Node *node = GetListHead(list);

        if (node)
        {
            while (GetNextNode(node))
            {
                node = GetNextNode(node);
            }
        }

        Node *newNode = (Node *)malloc(sizeof(Node));
        if (newNode)
        {
            newNode->val = newValue;
            newNode->next = NULL;
            newNode->previous = node;
            if (node)
            {
                node->next = newNode;
            }
            else
            {
                list->head = newNode;
            }
        }
        else
        {
            printf_s("ERROR: No memory available\n");
        }
        return newNode;
    }
    else
    {
        printf_s("ERROR: Passed null parameter\n");
        return NULL;
    }
}

ListDataType PopFront(List *list)
{
    if (list)
    {
        Node *frontNode = GetListHead(list);
        if (frontNode)
        {
            ListDataType frontNodeValue = GetValue(frontNode);
            DeleteNode(list, frontNode);
            return frontNodeValue;
        }
        else
        {
            printf_s("ERROR: List is empty\n");
            return 0;
        }
    }
    else
    {
        printf_s("ERROR: Passed null parameter\n");
        return 0;
    }
}

ListDataType PopBack(List *list)
{
    if (list)
    {
        Node *node = GetListHead(list);
        if (node)
        {
            while (GetNextNode(node))
            {
                node = GetNextNode(node);
            }

            ListDataType backNodeValue = GetValue(node);
            DeleteNode(list, node);
            return backNodeValue;
        }
        else
        {
            printf_s("ERROR: List is empty\n");
            return 0;
        }
    }
    else
    {
        printf_s("ERROR: Passed null parameter\n");
        return 0;
    }
}

void DeleteNode(List *list, Node *target)
{
    if (!list || !target)
    {
        printf_s("ERROR: Passed null parameter\n");
        return;
    }

    if (GetListHead(list) == target)
    {
        list->head = target->next;
        target->next->previous = NULL;
    }
    else if (!GetNextNode(target))
    {
        target->previous->next = NULL;
    }
    else
    {
        target->previous->next = target->next;
        target->next->previous = target->previous;
    }
    free(target);
}

Node *DeleteValue(List *list, ListDataType value)
{
    if (list)
    {
        Node *nodeWithValue = Find(list, value);
        if (nodeWithValue)
        {
            if (GetListHead(list) == nodeWithValue)
            {
                list->head = nodeWithValue->next;
                nodeWithValue->next->previous = NULL;
            }
            else if (!GetNextNode(nodeWithValue))
            {
                nodeWithValue->previous->next = NULL;
            }
            else
            {
                nodeWithValue->previous->next = nodeWithValue->next;
                nodeWithValue->next->previous = nodeWithValue->previous;
            }
        }
        return nodeWithValue;
    }
    else
    {
        printf_s("ERROR: Passed null parameter\n");
        return NULL;
    }
}

Node *Find(List *list, ListDataType value)
{
    if (list)
    {
        Node *node = GetListHead(list);
        if (node)
        {
            while (node->val != value && node)
            {
                node = GetNextNode(node);
            }
        }
        else
        {
            printf_s("ERROR: List is empty\n");
        }
        return node;
    }
    else
    {
        printf_s("ERROR: Passed null parameter\n");
        return NULL;
    }
}