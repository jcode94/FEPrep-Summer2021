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
2) (10pts)ALG(Linked Lists)

Suppose we have a queue implemented as a doubly linked 
list using the structures shown below. Use head for the 
front of the queue and tail for the end of the queue.

*/

struct node {
    int data; 
    struct node * next, * prev;
};

struct queue {
    int size;
    struct node * head, * tail;
};

// Considerations:
// 1. NULL/Empty Queue
// 2. Queue size 1 (tail will need to be adjusted)
// 3. Adjust size of mutated queue

int dequeue(queue * thisQ) {
    if (thisQ == NULL || thisQ->size == 0)
        return 0;
    
    // grab the return value
    int val = thisQ->head->data;
    
    // freeing and pointer adjustments
    node * temp = thisQ->head;
    
    thisQ->head = thisQhead->next;
    
    if (thisQ->size > 1)
        thisQ->head->prev = NULL;
    else
        thisQ->tail = NULL;

    free(temp);
    
    thisQ->size--;
    
    return val;
}
