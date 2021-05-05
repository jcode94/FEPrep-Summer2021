/***************************************************
* Author: Justice Smith
* Date: May 5, 2021
* Description: Dynamic memory allocation
* Note: As per the established Foundation Exam 
        structure, students must be able to 
        manage/manipulate memory in a dynamic 
        format. The following methods abstract 
        that partitioning for clarity.
***************************************************/
// I have chosen this problem because it scored very low in the last 
// 5 years for the DMA question, indicating unusual difficulty.

/*
1)(10pts) DSN (Dynamic Memory Management in C)

Suppose we are planning a party and we would like to create an array 
to store our list of supplies. Currently our list is stored in 
a text file with the name of each item to be purchased on a line by itself. 

Write a function called make_grocery_list that 
    reads these items from a file and 
    stores them in a two-dimensional character array. 

Your function should take 2 parameters: 
    a pointer to the file and 
    an integer indicating the number of grocery items in the file. 
    
It should return a pointer to the array of items. 

Be sure to allocate memory for the array dynamically and 
only allocate as much space as is needed. 

You may assume that all of the strings stored in the file representing 
grocery items are alphabetic strings of no more than 127 characters 
(so the buffer declared is adequate to initially read in the string).
*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

char ** make_grocery_list (FILE *ifp, int numItems)
{
    char buffer[128];
    char **list = NULL;
    int i;
 
    // Allocating space for a pointer to each item name
    list = malloc(numItems * sizeof(char *));
    
    for (i = 0; i < numItems; ++i)
    {
        scanf("%s", buffer);        // should be fscanf(ifp, "%s", buffer);
        list[i] = strdup(buffer);   
    }
    
    return list;    
}

/*
FE solution uses strcpy. What follows is the strcpy version:

char ** make_grocery_list (FILE *ifp, int numItems)
{
    char buffer[128];
    char **list = NULL;
    int i;
 
    // Allocating space for a pointer to each item name
    list = malloc(numItems * sizeof(char *));
    
    for (i = 0; i < numItems; ++i)
    {
        fscanf(ifp, "%s", buffer);
        list[i] = malloc((strlen(buffer) + 1) * sizeof(char));
        strcpy(list[i], buffer);
    }
    
    return list;    
}
*/

