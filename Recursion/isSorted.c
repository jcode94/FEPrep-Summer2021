// Justice Smith
// May 16, 2021
// Recursion practice for foundation exam

/*
Write a recursive function that returns 1 if an array of size n is in sorted 
orderfrom smallest to largestwith all values less than or equal to max, and 0 
otherwise. Note: If array a stores 3, 6, 7, 7, 12, then isSorted(a, 12, 5)
should return 1 but isSorted(a, 11, 5)should return 0. If array b 
stores 3, 4, 9, 8, then isSorted(b, 20, 4)should return 0, since 9 is bigger 
than 8but appears before it.The function prototype is given below.
*/



#include <stdio.h>

int isSorted(int * array, int max, int n);

int main()
{
    int array[] = {3, 6, 7, 7, 12};
    if (isSorted(array, 12, 5))
        printf("Sorted!\n");
    else
        printf("Unsorted or exceeds bounds\n");
        
    return 0;    
}

int isSorted(int * array, int max, int n)
{
    if (n == 1) return array[n-1] <= max;
    
    if (array[n - 1] <= max && array[n - 1] >= array[n - 2])        
        return isSorted(array, max, n - 1);
            
    return 0;
}
