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

2) (5pts)DSN (Linked Lists)
Given the linked list structure named node, in lines 1 through 4, 
and the function named eFunction defined in lines 6 through 14, 
answer the questions below.

1  typedef struct node{
2      int data;
3      truct node * next;
4  } node;
5 
6  node* eFunction(node* aNode){
7     if(aNode == NULL) return NULL;
8     if(aNode->next == NULL) return aNode;
9 
10    node* rest = eFunction(aNode->next);
11    aNode->next->next= aNode;
12    aNode->next= NULL;
13    return rest;
14 }


5 4 3 2 1
      1   2
       2 1 
       
        
(a)(1 pt) Is this function recursive? (Circle the correct answer below.)

yes

(b)(2 pts) What does the function eFunction do, in general to the list 
pointed to by its formal parameter, aNode?

reverses the linked list, returns pointer to reversed list

(c)(2 pts) What important task does line 12 perform?

sets the end of the list to null to avoid cycling

*/


