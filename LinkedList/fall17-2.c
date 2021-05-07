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
2) (10pts)DSN(Linked Lists)

Write a recursive function that takes in the head of 
a linked list and frees all dynamically allocated
memory associated with that list. You may assume  
that all the nodes in any linked list passed to 
your function (including the head node) have been dynamically 
allocated. It’s possible that your function might receive 
an empty linked list (i.e., a NULL pointer), and you should 
handle that case appropriately.

*/

typedef struct node {
    struct node * next;
    int data;
} node;

void destroy_list(node * head) {
    if (head == NULL) return;
    
    destroy_list(head->next);
    free(head);
}
