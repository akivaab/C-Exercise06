#include <malloc.h>
#include "LinkedList.h"

static int g_lastLinkedListError = 0;

List *CreateList(void)
{
    List *list = (List *)malloc(sizeof(List));
    if (list)
    {
        list->head = NULL;
    }
    else
    {
        g_lastLinkedListError += 1;
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
        g_lastLinkedListError += 1;
    }
}

size_t GetListSize(List *list)
{
    if (list)
    {
        size_t counter = 0;
        Node *node = GetListHead(list);
        while (node)
        {
            ++counter;
            node = GetNextNode(node);
        }
        return counter;
    }
    else
    {
        g_lastLinkedListError += 1;
        return 0;
    }
}

Node *GetListHead(List *list)
{
    if (list)
    {
        return list->head;
    }
    else
    {
        g_lastLinkedListError += 1;
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
        g_lastLinkedListError += 1;
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
        g_lastLinkedListError += 1;
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
            g_lastLinkedListError += 1;
        }
        return newNode;
    }
    else
    {
        g_lastLinkedListError += 1;
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
            g_lastLinkedListError += 1;
        }
        return newNode;
    }
    else
    {
        g_lastLinkedListError += 1;
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
            g_lastLinkedListError += 1;
        }
        return newNode;
    }
    else
    {
        g_lastLinkedListError += 1;
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
            g_lastLinkedListError += 1;
            return 0;
        }
    }
    else
    {
        g_lastLinkedListError += 1;
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
            g_lastLinkedListError += 1;
            return 0;
        }
    }
    else
    {
        g_lastLinkedListError += 1;
        return 0;
    }
}

void DeleteNode(List *list, Node *target)
{
    if (!list || !target)
    {
        g_lastLinkedListError += 1;
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
        else
        {
            g_lastLinkedListError += 1;
        }
        return nodeWithValue;
    }
    else
    {
        g_lastLinkedListError += 1;
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
            g_lastLinkedListError += 1;
        }
        return node;
    }
    else
    {
        g_lastLinkedListError += 1;
        return NULL;
    }
}

int GetLastLinkedListError(void)
{
    return g_lastLinkedListError;
}