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
// This implementation is based on Guha's stack 
// linked list implementation.

#include <stdlib.h>
#include <stdio.h>

typedef struct stack {
    int data;
    struct stack * next;
} stack;

int push(stack ** top, int value);
stack * pop(stack ** top);
int empty(stack * top);
int peek(stack * top);
void init(stack ** top);

int main() 
{
    stack * stack1, * temp;
    int tempVal;
    
    init(&stack1);
    
    // push attempt    
    if (!push(&stack1, 10))
        printf("Push failed.\n");
    
    // push attempt
    if (!push(&stack1, 3))
        printf("Push failed.\n");
    
    // Test Pop function
    temp = pop(&stack1);
    if (temp != NULL)
        printf("Pop stack = %d\n", temp->data);
    
    // Test containment   
    if (empty(stack1))
        printf("Empty stack\n");
    else
        printf("Contains elements.\n");
        
    tempVal = peek(stack1);
    if (tempVal != -1)
        printf("Top of stack = %d\n", tempVal);
        
    temp = pop(&stack1);
    temp = pop(&stack1);
    if (temp != NULL)
        printf("Top of stack = %d\n", temp->data);
    else
        printf("Tried to pop an empty stack.\n");
    
    return 0;
}

// Pre-condition: front points to the top of the stack.
// Post-condition: a new node storing num will be pushed 
//                 on top of the stack if memory is 
//                 available. In this case a 1 is returned.
//                 If no memory is found, no push is executed
//                 and a 0 is returned.
int push(stack ** top, int value)
{
    stack * temp;
    // Create temp node and link it to front.
    temp = (stack *)malloc(sizeof(stack));
    
    if (temp != NULL)
    {
        temp->data = value;
        temp->next = *top;
        *top = temp;
        return 1;
    }
    else
        return 0;
}

// Pre-condition: front points to the top of a stack
// Post-condition: A pointer to a node storing the top value from the
//                 stack will be returned. If no value exists, the pointer
//                 returned will be pointing to null.
stack * pop(stack ** top)
{
    stack * temp;
    temp = NULL;
    
    if (*top != NULL)
    {
        temp = (*top);
        *top = (*top)->next;
        temp->next = NULL;
    }
    return temp;
}

// Pre-condition: front points to the top of a stack
// Post-condition: returns true if the stack is empty, false otherwise.
int empty(stack * top)
{
    if (top == NULL)
        return 1;
    else
        return 0;
}

// Pre-condition: front points to the top of a stack
// Post-condition: returns the value stored at the top of
//                 the stack if the stack is non-empty, -1 otherwise.
int peek(stack * top)
{
    if (top != NULL)
    {
        return top->data;
    }
    else
        return -1;
}

void init(stack ** top)
{
    *top = NULL;
}

