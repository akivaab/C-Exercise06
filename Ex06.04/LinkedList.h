#ifndef _LINKED_LIST_H_
#define _LINKED_LIST_H_
#include <stdlib.h>

/**
 * @file Linked List
*/

/**
 * @brief ListDataType used to easily change the value stored in the list.
*/
typedef int ListDataType;

/**
 * @brief Representation of a node, contains a value, and pointers to the nodes before and after it in the list.
*/
typedef struct Node_t Node;
typedef struct Node_t
{
    ListDataType val;
    Node *next;
    Node *previous;
} Node;

/**
 * @brief Representation of a list, contains a pointer to the head.
*/
typedef struct List_t
{
    Node *head;
} List;

/**
 * @brief Initializes a list.
 
 * @return the list created 
*/
List *CreateList(void);

/**
 * @brief Free the memory used by the list.
 * 
 * @param list the list being deleted
*/
void FreeList(List *list);

/**
 * @brief Finds the size of the list.
 * 
 * @param list the list being measured
 * 
 * @return the size 
*/
size_t GetListSize(List *list);

/**
 * @brief Gets the head of the list.
 * 
 * @param list the list whose head we're getting

 * @return a pointer ot the node at the head of the list 
*/
Node *GetListHead(List *list);

/**
 * @brief Gets the next node.
 * 
 * @param currentNode the current node 
 * 
 * @return the node following the one received 
*/
Node *GetNextNode(Node *currentNode);

/**
 * @brief Gets the value of a node.
 * 
 * @param node the node hwose value we're getting
 * 
 * @return the value
*/
ListDataType GetValue(Node *node);

/**
 * @brief Inserts a new node after an existing one.

 * @param after the node we wish to place the new node after 
 * @param newValue the value of the new node
 * 
 * @return the new node 
*/
Node *Insert(Node *after, ListDataType newValue);

/**
 * @brief Push a new node onto the front of a list.
 * 
 * @param list the list
 * @param newValue the value of the new node
 * 
 * @return the new node
*/
Node *PushFront(List *list, ListDataType newValue);

/**
 * @brief Push a new node onto the back of a list.
 *
 * @param list the list
 * @param newValue the value of the new node
 *
 * @return the new node
*/
Node *PushBack(List *list, ListDataType newValue);

/**
 * @brief Pop the front node from a list.
 * 
 * @param list the list
 * 
 * @return the value of the node justed popped
*/
ListDataType PopFront(List *list);

/**
 * @brief Pop the back node from a list.
 *
 * @param list the list
 *
 * @return the value of the node justed popped
*/
ListDataType PopBack(List *list);

/**
 * @brief Deletes a node from a list.
 * 
 * @param list the list
 * @param target the node being removed
*/
void DeleteNode(List *list, Node *target);

/**
 * @brief Removes (not deletes!) the first node containing a certain value from a list.
 * 
 * @param list the list
 * @param value the value whose corresponding node is being removed
 * 
 * @return the node removed from the list
*/
Node *DeleteValue(List *list, ListDataType value);

/**
 * @brief Finds the first node containing a certain value in a list.
 * 
 * @param list the list being searched through 
 * @param value the value being searched for
 * 
 * @return the node that has this value
*/
Node *Find(List * list, ListDataType value);

int GetLastLinkedListError(void);

#endif