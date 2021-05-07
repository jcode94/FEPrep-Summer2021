/***************************************************
* Author: Justice Smith
* Date: May 7, 2021
* Description: Linked Lists
* Note: As per the established Foundation Exam 
        structure, students must be able to:
        i. Converting infix to postfix expressions
        ii. Evaluating postfix expressions
        iii. Array Implementation
        iv. Linked List Implementation
***************************************************/

// General stack operations to demonstrate minimum 
// proficiency with the stack abstract data structure
// This implementation is based on Guha's queue 
// array implementation.

#include <stdio.h>

#define EMPTY -1
#define INIT_SIZE 10

// Stores our queue.
typedef struct queue {
    int * elements;
    int front;
    int numElements;
    int queueSize;
} queue;




