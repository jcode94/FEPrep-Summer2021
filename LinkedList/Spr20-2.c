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

// I have chosen this problem because it scored very low 
// in the last 5 years for the Linked List question.

/*
2) (5pts)ALG (Linked Lists)

Suppose we have a linked list implemented with the 
structure below. We also have a function that takes
in the head of the list and the current number of 
nodes in the list. 
*/
typedef struct node {
    int num;
    struct node * next;
} node;

int whatDoesItDo (node * head, int size) {
    node * current = head;
    node * other;
    
    if (size < 2)
        return size;
    
    other = head->next;
    
    while (current != NULL) {
        current->next = other->next;
        free(other);
        current = current->next;
        size--;
        if (current != NULL && current->next != NULL) {
            current = current->next;
            other = current->next;
        }
    }
    
    return size;
}

/*
If we call whatDoesItDo(head, 8) on the following list, 
show the list after the function has finished and state 
the return value.

head ->  3 -> 8 -> 12 -> 5 -> 1 -> 7 -> 19 -> 2

Picture of List Pointed to by head After Function Call:

3 12 5 7 19 

Function Return Value: 5
*/

