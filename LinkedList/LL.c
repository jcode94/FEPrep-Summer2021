/***************************************************
* Author: Justice Smith
* Date: May 5, 2021
* Description: Linked Lists
* Note: As per the established Foundation Exam 
        structure, students must be able to:
        i. How to allocate space for a new node (malloc)
        ii. When to check for NULL
        iii. What free does
        iv. Iteration vs. Recursion
        v. Insertion
        vi. Deletion
        vii. Structural Modification
***************************************************/

// General Linked List operations to demonstrate minimum 
// proficiency with the LL data structure

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Node Node;

struct Node {
    int data;
    Node * next;
};

Node * createNode(int value);
void print(Node * head);
void printRec(Node * head);
Node * insertHead(Node * head, int data);
void freeList(Node * head);
int sum(Node * head);
void printBackwardsRec(Node * head);
int isSorted(Node * head);
Node * insertRec(Node * head, int data);

// Two different delete fucntions
Node * deleteRec(Node * head, int value);
Node * deleteAllRec(Node * head, int value);

// Reversing a linked list iteratively.
Node * reverseLL(Node * head);

// Reversing a linked list recursively.
Node * reverseLLRec(Node * head);

int main()
{
    Node * head = NULL;
    head = insertHead(head, 7);
    head = insertHead(head, 11);
    head = insertHead(head, 7);
    head = insertHead(head, 7);
    head = insertHead(head, 9);
    head = insertHead(head, 3);
    head = insertHead(head, 8);
    head = insertHead(head, 7);
    head = insertHead(head, 24);
    head = insertHead(head, 1);
    head = insertHead(head, 13);
    head = insertHead(head, 7);
    
    print(head);
    head = deleteAllRec(head, 7);
    printRec(head);
    head = deleteAllRec(head, 24);
    print(head);
    head = reverseLL(head);
    print(head);
    head = reverseLLRec(head);
    print(head);
    
    Node * sortCheck = NULL;
    sortCheck = insertHead(sortCheck, 3);
    sortCheck = insertHead(sortCheck, 1);
    sortCheck = insertHead(sortCheck, 2);
    printf("%s\n", isSorted(sortCheck) ? "Sorted" : "Unsorted"); 
    return 0;   
}

Node * createNode(int value)
{   
    Node * newNode = malloc(1 * sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    
    return newNode;
}

// Iterative print
void print(Node * head)
{
    Node * cur = head;
    while (cur != NULL)
    {
        printf("%d->", cur->data);
        cur = cur->next;
    }
    printf("NULL\n");
}

// Recursive print
void printRec(Node * head)
{
    if (head != NULL)
    {
        printf("%d->", head->data);
        print(head->next); 
    }
    printf("NULL"); 
}

Node * insertHead(Node * head, int data)
{
    Node * newNode = createNode(data);
    if (head == NULL) return newNode;
    
    newNode->next = head;
    
    return newNode;
}

void freeList(Node * head)
{
    if (head != NULL)
    {
        freeList(head->next);
        free(head);
    }
}

int sum(Node * head)
{
    if (head == NULL) return 0;
    return head->data + sum(head->next);
}

void printBackwardsRec(Node * head)
{
    if (head != NULL)
    {
        printBackwardsRec(head->next);
        printf("%d->", head->data);
    }
    
    printf("NULL->");
}

int isSorted(Node * head)
{
    if (head == NULL || head->next == NULL) return 1;
    if (head->next->data > head->data)
        return isSorted(head->next);
    return 0;
}

// This function inserts a value in the correct position
// to ensure that all values in the linked list remain sorted
// ascending
Node * insertRec(Node * head, int data)
{
    Node * newNode = createNode(data);
    
    // Empty list or belongs at front
    if (head == NULL || data < head->data)
    {
        newNode->next = head;
        return newNode;
    }
    
    head->next = insertRec(head->next, data);
    return head;
}

// Deletes first instance of search value
Node * deleteRec(Node * head, int value)
{
    Node * temp;
    if (head == NULL) return NULL;
    if (head->data == value)
    {
        temp = head->next;
        free(head);
        return temp;
    }    
    
    head->next = deleteRec(head->next, value);
    return head;
}

// Deletes every instance of search value
Node * deleteAllRec(Node * head, int value)
{
    Node * temp;
    if (head == NULL) return NULL; // empty or end
    
    if (head->data == value)
    {
        temp = head->next;
        free(head);
        
        return deleteAllRec(temp, value);
    }
    
    head->next = deleteAllRec(head->next, value);
    
    return head;
}

// 1->2->3->4->5
// head: 1, second = (head->next: 2)            1->2->3->4->5
// head->next: NULL                             1  2->3->4->5

// third = (second(2)->next: 3)                         
// second->next = (head: 1)                     2->1  3->4->5
// head = (second: 2), second = (third: 3)      

// third = (second(3)->next: 4)                 
// second->next = (head: 2)                     3->2->1  4->5
// head = (second: 3), second = (third: 4)

// third = (second(4)->next: 5)                 
// second->next = (head: 3)                     4->3->2->1  5
// head = (second: 4), second = (third: 5)

// third = (second(5)->next: NULL)                 
// second->next = (head: 4)                     5->4->3->2->1
// head = (second: 5), second = (third: NULL)
Node * reverseLL(Node * head)
{
    // list size == 0 or 1
    if (head == NULL || head->next == NULL) return head;
    
    // set up ptr for next
    Node * second = head->next;
    head->next = NULL;
    
    while (second != NULL)
    {
        Node * third = second->next;
        
        second->next = head;
        
        head = second;
        second = third;
    }
    
    return head;
}

// reverseLLRec stack trace
// 1->2->3->4->5
// second = (head->next: 2)
// ret = reverseLLrec(second:2)
    // second = (head(2)->next: 3)
    // ret = reverseLLRec(second:3)
        // second = (head(3)->next: 4)
        // ret = reverseLLrec(second:4)
            // second = (head(4)->next: 5)
            // ret = reverseLLrec(second:5)
                // head(5)->next == NULL, return 5
            // ret = 5->NULL
            // second(5)->next = head:4
            // head(4)->next = NULL
            // return ret
        // ret = 5->4->NULL
        // second(4)->next = head:3
        // head(3)->next = NULL
        // return ret
    // ret = 5->4->3->NULL
    // second(3)->next = head:2
    // head(2)->next = NULL
    // return ret
// ret = 5->4->3->2->NULL
// second(2)->next = head:1
// head(1)->next = NULL
// return ret
Node * reverseLLRec(Node * head)
{
    Node * second;
    Node * ret;
    
    // list size 0 or 1
    if (head == NULL || head->next == NULL) return head;
    
    second = head->next;
    // Perform reversal on remaining portion of LL
    ret = reverseLLRec(second); 
    second->next = head;
    
    head->next = NULL;
    
    return ret;
}

