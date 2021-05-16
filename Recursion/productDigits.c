// Justice Smith
// May 16, 2021
// Recursion practice

/*
Write a recursive function that returns the product of the digits of its 
integer input parameter,n. You may assume that n is non-negative. For example, productDigits(274)should return 56, since 2 x 7 x 4 = 56.The function 
prototype is given below.
*/

#include <time.h>
#include <stdlib.h>
#include <stdio.h>

int productDigits(int n);

int main()
{
    srand(time(NULL));
    for (int i = 0; i < 10; i++)
    {
        int test = rand() % 1000 + 1;
        printf("Product of digits(%d): %d\n", test, productDigits(test));
    }
    return 0;
}

int productDigits(int n)
{
    if (n == 0) return 1;
    return n%10 * productDigits(n/10);
}
