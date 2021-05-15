// Justice Smith
// Base converter in a procedural paradigm
// Prep for Foundation Exam, May 2021

// This program converts to and from bases less than or equal to 10
// I haven't accounted for the convention of using letters for bases 
//      greater than 10, thus this limitation.

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define BASE_DECIMAL 10

long long baseConverter();
long long converter(long long baseFrom, long long baseTo, long long num);
long long fastPow(long long base, long long exponent);
long long srcToDecimal(long long src, long long srcBase);
long long decimalToBase(long long decimal, long long destBase);

long long main()
{
    long long exit_status = baseConverter();
    
    printf("Exit Status: %lli, %s\n", exit_status, 
                                   !exit_status ? "Success" : "Fail");
    
    return 0;
}

long long baseConverter()
{
    long long srcBase, destBase, src;
    srcBase = destBase = src = 0;
    
    char userResp = 'n';
    
    printf("\n\t\tBase Converter, by Justice Smith\n");
    printf("--------------------------------");
    printf("--------------------------------\n");
    
    do {
        printf(" srcBase: ");    
        scanf("%lli", &srcBase);
        
        printf(" destBase: ");
        scanf("%lli", &destBase);
        
        printf(" Number to convert: ");
        scanf("%lli", &src);
        
        long long converted = converter(srcBase, destBase, src);
        printf(" Thus, %lli base %lli to base %lli: %lli\n", 
                src, 
                srcBase, 
                destBase, 
                converted
              );
        printf("--------------------------------");
        printf("--------------------------------\n");
        
        char userResp;
        printf("Convert another?(y/n) ");
        getchar(); // clear newline
        scanf("%c", &userResp);
        printf("--------------------------------");
        printf("--------------------------------\n");
        if (userResp == 'n') break;
        
    }while (1);
    
    
    return 0;
    
}

// returns zero if no conversion done, which in turn signals termination
long long converter(long long baseFrom, long long baseTo, long long num)
{
    long long ret = 0;
    
    // No conversion necessary when src and dest bases are same
    if (baseFrom == baseTo) return num;
    // No need to convert to decimal when src is in decimal
    if (baseFrom == BASE_DECIMAL) return decimalToBase(num, baseTo);
    // No need to convert from decimal when dest is in decimal
    if (baseTo == BASE_DECIMAL) return srcToDecimal(num, baseFrom);

    // Neither src nor dest is decimal, we use decimal as intermediary step
    long long decimal = srcToDecimal(num, baseFrom);
    ret = decimalToBase(decimal, baseTo);
    
    return ret;
}

// Converts src to base 10
long long srcToDecimal(long long src, long long srcBase)
{
    long long numDigits = 0;
    long long ret = 0;
    
    printf("\n First we convert to decimal:\n");
    
    while (src >= BASE_DECIMAL)
    {
        ret += (src % BASE_DECIMAL) * fastPow(srcBase, numDigits);
        printf(" %lli * %lli^%lli + \n", 
                (src % BASE_DECIMAL), 
                srcBase, 
                numDigits
              );
        numDigits++;
        src /= BASE_DECIMAL;
    }
    
    ret += (src % BASE_DECIMAL) * fastPow(srcBase, numDigits);
    printf(" %lli * %lli^%lli = %lli\n", 
            (src % BASE_DECIMAL), 
            srcBase, 
            numDigits, 
            ret
          );
    
    return ret;
}

// Converts temp base 10 to target base
long long decimalToBase(long long decimal, long long destBase)
{
    long long numDigits = 0;
    long long ret = 0;
    
    printf("\n Now we convert from decimal to the target base:\n");
    while (decimal >= destBase)
    {
        ret += (decimal % destBase) * fastPow(BASE_DECIMAL, numDigits);
        printf(" (%lli %% %lli) * %i^%lli + \n", decimal, destBase, BASE_DECIMAL, numDigits);

        decimal /= destBase;
        numDigits++;
    }
    
    ret += (decimal % destBase) * fastPow(BASE_DECIMAL, numDigits);
    printf(" (%lli %% %lli) * %i^%lli = %lli\n", 
            decimal, 
            destBase, 
            BASE_DECIMAL, 
            numDigits, 
            ret
          );
    
    return ret;
}

// recursive power function, speedy boy
// based on guha and wikipedia modular exponentiation
long long fastPow(long long base, long long exponent)
{    
    if (exponent == 0) return 1;
    
    if (exponent % 2 == 0)
    {
        long long mySqrt = fastPow(base, exponent/2);
        return (mySqrt * mySqrt);
    }
    
    return (base * fastPow(base, exponent-1));
}

