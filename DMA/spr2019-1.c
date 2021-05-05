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
// I have chosen this problem because it scored the 2nd lowest in the last 
// 5 years for the DMA question.

// (10 pts) DSN (Dynamic Memory Management in C
// This problem relies on the following struct definition:

typedef struct Employee{
    char *first; // Employee's firstname.
    char *last;  // Employee's lastname.
    intID;      // Employee ID.
} Employee;

/*
Consider  the  following  function,  which  takes  three  
arrays – each of length n – containing  the  
    first names,  
    last  names,  and  
    ID  numbers  
of nemployees  for  some  company.  The  function  dynamically 
allocates  an  array  of nEmployeestructs,  copies  the  
information  from  the  array  arguments  into  the 
corresponding array of structs, and returns the dynamically 
allocated array.


Employee *makeArray(char **firstNames, char **lastNames, int *IDs, int n)
{
    int i;
    Employee *array = malloc(_______________________________);
    
    for (i = 0; i < n; ++i)
    {
        array[i].first = malloc(_______________________________);
        
        array[i].last = malloc(_______________________________);
        
        strcpy(array[i].first, firstNames[i]);
        strcpy(array[i].last, lastNames[i]);
        array[i].ID = IDs[i];
    }

    return array;
}

a) Fill in the blanks with the appropriate arguments for each malloc() stmt.

b) Next, write a function that takes a pointer to the array created by the
makeArray() funciton, along with the number of employee records in that array
(n) and frees all the dynamically allocated  memory associated with that array.
The function signature is as follows:

void freeEmployeeArray(Employee *array, int n);
*/

Employee *makeArray(char **firstNames, char **lastNames, int *IDs, int n)
{
    int i;
    // Each position will hold an actual struct(important to note for freeing)
    Employee *array = malloc(n * sizeof(Employee));
    
    for (i = 0; i < n; ++i)
    {
        // + 1 for NTC and parentheses bc operator precedence
        array[i].first = malloc((strlen(firstNames[i]) + 1) * sizeof(char));
        
        array[i].last = malloc((strlen(lastNames[i]) + 1) * sizeof(char));
        
        strcpy(array[i].first, firstNames[i]);
        strcpy(array[i].last, lastNames[i]);
        array[i].ID = IDs[i];
    }

    return array;
}

void freeEmployeeArray(Employee *array, int n)
{
    int i;
    
    for (i = 0; i < n; ++i)
    {
       free(array[i].first);
       free(array[i].last);
    }    
    free(array[i]);
}

