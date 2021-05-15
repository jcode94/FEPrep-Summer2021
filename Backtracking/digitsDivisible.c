// Justice Smith
// 05.15.21
// Backtracking practice for Foundation Exam
// Copied for familiarity/muscle memory from Arup Guha's implementation

#include <stdio.h>

#define N 18
#define PRINTSOLS 1

int digitDivisible(long long prefix, int k);

int main()
{
    int numSols = digitDivisible(0, 0);
    printf("We found %d solutions. \n", numSols);
    return 0;
}

int digitDivisible(long long prefix, int k)
{
    // Filled in the whole number.
    if (k == N)
    {
        if (PRINTSOLS) printf("%lld\n", prefix);
        return 1;
    }
    
    // Calculate the first possible digit for this slot.
    // int start = k == 0 ? 1 : 0;
    int start = 0;
    if (k = 0) start = 1;
    
    int i, res = 0;
    
    // Try each digit in slot k.
    for (i = start, i < 10; i++)
    {
        // Add digit i to the end of prefix.
        long long newnum = 10*prefix + i;
        
        // Skip it, the first k+1 digits aren't divisible by k+1;
        if (newnum % (k + 1) != 0) continue;
        
        // Recurse with this digit filled in.
        res += digitDivisible(newnum, k+1);
    }
    
    // This is how many solutions we found.
    return res;
}
