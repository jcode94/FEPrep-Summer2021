/***************************************************
* Author: Justice Smith
* Date: May 4, 2021
* Description: Dynamic memory allocation
* Note: As per the established Foundation Exam 
        structure, students must be able to 
        manage/manipulate memory in a dynamic 
        format. The following methods abstract 
        that partitioning for clarity.
***************************************************/
// preprocessor directive that allows for the
// use of malloc, calloc, realloc, and free
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define SIZE 10

typedef struct Struct Struct;
struct Struct {
    int data;
    Struct * next;
    char name[20];
    // Note that with a declaration like name[n] where 
    // only n - k spots are filled, the remaining k spots
    // will be filled with the NULL-terminating character
    // (char name[5] = "hi";) == ({'h', 'i', '\0', '\0', '\0'};)
};

Struct * structAlloc();


int * arrAlloc();
int ** twoDArrAlloc();
// Note that the difference between the first and 
// second of these n-dim allocations is the 
// contiguous nature of the data structure.
// More below.
int ** jaggedArrAlloc();
void freeAllMem(
        Struct * myStruct, 
        int * myArr, 
        int ** my2DArr,
        int ** myJaggedArr
        );

int main()
{
    Struct * myStruct = structAlloc();
    int * myArr = arrAlloc();
    int ** myTwoDArr = twoDArrAlloc();
    int ** myJaggedArr = jaggedArrAlloc(); 
    // void = no return
    freeAllMem(myStruct, myArr, myTwoDArr, myJaggedArr);    
    
    return 0;
}

Struct * structAlloc()
{
    // Struct * newStruct = (Struct *)malloc(sizeof(Struct));
    Struct * newStruct = calloc(1, sizeof(Struct));
    
    // Populating struct fields
    newStruct->data = 0;
    newStruct->next = NULL;
    strcpy(newStruct->name, "Justice");
        
    return newStruct;
}

int * arrAlloc()
{   
    // int * newArr = (int *)malloc(SIZE * sizeof(int));
    int * newArr = calloc(SIZE, sizeof(int));
    
    for (int i = 0; i < SIZE; ++i)
    {
        newArr[i] = i;
    }
    
    return newArr;
}

int ** twoDArrAlloc()
{
    // Allocate space to hold 10(SIZE) int-type pointer addresses
    // int ** newArr = (int **)malloc(SIZE * sizeof(int *));
    int ** newArr = calloc(SIZE, sizeof(int *));
    
    for (int i = 0; i < SIZE; ++i)
    {
        // Allocate 10(SIZE) int-type blocks of memory
        // of length 10(SIZE),
        // storing the address of each block at newArr[i]
        // newArr[i] = (int *)malloc(SIZE * sizeof(int));
        newArr[i] = calloc(SIZE, sizeof(int));
        for (int j = 0; j < SIZE; j++)
        {
            // Assign the numbers 0-9 to the array elements
            newArr[i][j] = j;
        }
    }
    return newArr;
}

// Note that the difference between the first and 
// second of these n-dim allocations is the 
// contiguous nature of the data structure.
// More below.
int ** jaggedArrAlloc()
{
    int jaggedArr0[1] = {1};
    int jaggedArr1[2] = {1, 2};
    int jaggedArr2[0] = {};
    int jaggedArr3[3] = {5, 7, 1};
    int jaggedArr4[1] = {0};
    
    int size = 5;
    // Allocated on heap so we don't lose it when we return
    int ** myJaggedArr = calloc(size, sizeof(int *));
    
    int * jaggedArrays[5] = {
                    jaggedArr0,
                    jaggedArr1,
                    jaggedArr2,
                    jaggedArr3,
                    jaggedArr4
                };
    
    // Copying over the addresses of the local arrays
    for (int i = 0; i < size; ++i)
    {
        myJaggedArr[i] = jaggedArrays[i];
    }
      
    return myJaggedArr;
}

/*
structAlloc.c: In function ‘jaggedArrAlloc’:
structAlloc.c:120:17: warning: initialization of ‘int **’ from incompatible pointer type ‘int *’ [-Wincompatible-pointer-types]
  120 |                 jaggedArr0,

*/

// 
// Array of pointers, where 1 represents a pointer
// {1, 1, 1, 1, 1, 1}
// 1
// 1
// 1
// 1
// 1
// 1
//
// Jagged array, where all memory is contiguous
// and dimensionality is abstract.
// {{1}, {1, 2}, {}, {5, 7, 1}, {0}}
// 1
// 1 2
// 
// 5 7 1
//
// Generic representation of a jagged array,
// where 0 represents an int element of a
// particular row
// 0
// 00000
// 000
// 00
// 0000
// 0
// 000000000
// 000
// 000000
// 


void freeAllMem(
        Struct * myStruct, 
        int * myArr, 
        int ** my2DArr,
        int ** myJaggedArr
        )
{
    int i;
    
    free(myStruct);
    myStruct = NULL;
    
    free(myArr);
    myArr = NULL;
    
    int length = sizeof(my2DArr) / sizeof(*my2DArr);
    for (i = 0; i < length; ++i)
    {
        free(my2DArr[i]);
        my2DArr[i] = NULL;
    }
    
    free(my2DArr);
    my2DArr = NULL;
    
    for (i = 0; i < 5; ++i)
    {
        free(myJaggedArr[i]); // SEGFAULT here
        myJaggedArr[i] = NULL;
    }
    free(myJaggedArr);
    myJaggedArr = NULL;
}
    
