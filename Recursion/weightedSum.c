// Justice Smith
// May 16, 2021
// Recursion practice

/*
Define  the  weighted  sum  of  an  integer  array  a[0],  a[1],  ...,  a[n-1] 
to  be ∑(𝑖𝑎[𝑖−1])𝑛𝑖=1.  For example, the weighted sum of the array [7, 5, 8] 
would be 1×7+2×5+3×8=41. Write a recursivefunction that takes in an array 
numbersand its length n, and returns its weighted sum. You may assume that 
there will be no issues with integer overflow.The function prototype is given 
below.
*/

#include <time.h>
#include <stdlib.h>
#include <stdio.h>

int weightedSum(int numbers[], int n);

int main()
{
    srand(time(NULL));
    
    int len = rand() % 10 + 1; // length of array 1-10(inc)
    int arr[len];
    
    printf("Array: ");
    for (int i = 0; i < len; i++)
    {
        arr[i] = rand() % 10; // fill array with numbers 0-9(inc.)
        printf("%d ", arr[i]);   
    }
    printf("\n");
    
    printf("Weighted sum of array: %d\n", weightedSum(arr, len));
    
    return 0; 
}

int weightedSum(int numbers[], int n)
{
    if (n == 1) return numbers[n-1];
    return (n * numbers[n-1]) + weightedSum(numbers, n - 1);
}

