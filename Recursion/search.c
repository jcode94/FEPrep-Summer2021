// Justice Smith
// May 16, 2021
// Recursion practice

/*
efficient recursive function 
    -takes in a sorted array numbers, 
    - two integers, lowand high, representing indexes into the array, and 
    - another integer, value 
    
    returns: index in the array where value is found  
    
    If value is NOT found in the array, the function should return -1.
*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int search(int numbers[], int low, int high, int value);

int main()
{
    // seeding rng
    srand(time(NULL));
    
    // length of array 1-20
    int len = rand() % 20 + 1; 
    // init array of length len
    int arr[len]; 
    
    printf("Array: ");
    for (int i = 0; i < len; i++)
    {
        // Ascending range with one number from each hundreds partition
        arr[i] = (rand() % 100) + (i * 100); 
        printf("%d ", arr[i]);   
    }
    printf("\n");
    
    // Check for correctness
    int searchNum = rand() % len; // idx < len
    // We search for number we know exists by passing value from array
    int ret = search(arr, 0, len-1, arr[searchNum]); 
    
    if (ret == -1) 
        printf("%d not found in array\n", arr[searchNum]);
    else 
        printf("We found the element %d at arr[%d]\n", arr[ret], ret);

    // Now we test for values not found
    for (int i = 0; i < 10; i++)
    {
        int test = rand() % 1000;
        if (search(arr, 0, len - 1, test) == -1)
            printf("%d not found\n", test);
    }
    return 0;        
}

int search(int numbers[], int low, int high, int value)
{
    if (low > high) return -1;    
    
    if (low == high)
        if (low == value) return low;
        else return -1;
    
    int mid = (low + high)/2;
    
    if (value < numbers[mid])
        return search(numbers, low, mid - 1, value);
        
    else if (value > numbers[mid])
        return search(numbers, mid + 1, high, value);
        
    else // value == numbers[mid]
        return mid;
}

