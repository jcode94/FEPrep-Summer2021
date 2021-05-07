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
// array implementation.

#define SIZE 10
#define EMPTY -1

typedef struct Stack {
    int items[SIZE];
    int top;
} Stack;

void initialize(Stack * Stack);
int full(Stack * Stack);
int empty(Stack * Stack);
int push(Stack * Stack);
int pop(Stack * Stack);
int top(Stack * Stack);

int main() {
    int i;
    Stack * myStack;
    
    // Set up the stack and push a couple items, then pop one.
    initialize(&myStack);
    push(&myStack, 4);
    push(&myStack, 5);
    push(&myStack, 8);
    printf("Popping %d\n", pop(&myStack));
    
    // Push a couple more and test top.
    push(&myStack, 22);
    push(&myStack, 16);
    printf("At top now = %d\n", top(&myStack));
    
    // Pop all three off.
    printf("Popping %d\n", pop(&myStack));
    printf("Popping %d\n", pop(&myStack));
    printf("Popping %d\n", pop(&myStack));
    
    // Checking the empty function.
    if (empty(&myStack))
        printf("The stack is empty as expected.\n");
    
    // Fill the stack.
    for (i = 0; i < 10; i++)
        push(&myStack, i);
    
    // Check if full works.
    if (full(&myStack))
        printf("This stack is full as expected.\n");
    
    // Pop everything back off.
    for (i = 0; i < 10; i++)
        printf("popping %d\n", pop(&myStack));
    
    system("PAUSE");
    return 0;
}


void initialize(Stack * stack)
{
    stack->top = -1;
}

// Returns true iff the stack pointed to by Stack is full
int full(Stack * Stack)
{
    return (Stack->top == SIZE - 1);
}

// Returns true iff the stack pointed to by Stack is empty
int empty(Stack * Stack)
{
    return (Stack->top == -1);    
}

int push(Stack * Stack, int value)
{
    // Check if the stack is full
    if (full(Stack))
        return 0;
        
    // Add value to the top of the stack and adjust the value of the top.
    Stack->items[Stack->top + 1] = value;
    (Stack->top)++;
    return 1;
}

// Pre-condition: the stack pointed to by Stack is NOT empty.
// Post-condition: the value on top fo the stack is popped and returned.
// Note: If the stack pointed to by Stack is empty, -1 is returned.
int pop(Stack * Stack)
{
    int ret;
    
    // Check if the stack is empty
    if (empty(Stack))
        return 0;
        
    // Retrieve the item from the top of the stack, 
    // adjust the top and return the item.
    ret = Stack->items[Stack->top];
    (Stack->top)--;
    return ret;
}

int top(Stack * Stack)
{
    // Take care of the empty case.
    if (empty(Stack))
        return EMPTY;
        
    // Return the desired item.
    return Stack->items[Stack->top];
}

