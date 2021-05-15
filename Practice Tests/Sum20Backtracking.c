void printRec(int number[], int k, int n)
{
    // Completed the perms
    if (k == n)
    {
        print(number, n);
        return;
    }
    
    
    int start = 0;
    
    if (k == 0)
        start = 1;
        
    for (int i = start; i < 10; i++)
    {
        if (k == 0 || abs(number[k - 1] - i) >= 2)
        {
            number[k] = i;
            printRec(number, k + 1, n);
        }
    }
}



            
