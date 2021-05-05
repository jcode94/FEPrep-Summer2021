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
// 5 years for the DMA question.

/*
1)(5 pts) DSN (Dynamic Memory Management in C)

There is something terribly wrong with the code given below: 
it has two memory leaks. After carefully inspecting the code, 
answer the questions below.

1: int main(void)
2: {
3:     char *str1 = malloc(sizeof(char) * 16);
4:     char *str2 = malloc(sizeof(char) * 16);
5:     
6:     str1[0] = 'p';
7:     str1[1] = 'a';
8:     str1[2] = 's';
9:     str1[3] = 's';
10:    str1[4] = ',';
11:    str1[5] = '\0';
12:    
13:    printf("%s ", str1);
14:    str2 = str1;
15:    printf("%s ", str2);
16:    str2 = NULL;
17:    strcpy(str1, "pass the exam!");
18:    printf("%s\n", str1);
19:    
20:    free(str1);
21:    free(str2);
22:    
23:    return 0;
24: }

(a) (3pts) Draw a picture that indicates the relevant state of memory 
after line 14 has completed. 
(Draw a rectangular box to indicate dynamically allocated memory.)
          0   1   2   3   4   5   6   7   8   9  10  11  12  13  14  15
str1 -> | p | a | s | s | , | 0 |   |   |   |   |   |   |   |   |   |   |
str2 -----^

(b) (1 pt) Explain why line 14 causes a memory leak.
The memory originally allocated to str2 has lost its reference when
we assigned the address stored at str1 to str2.

(c) (1 pt) Why is it possible for the code to crash on line 21?
we're doing a double free. Since both str1 and str2 point to the same
block of memory, after freeing str1 on line 20, we attempt to free the
already free'd block of memory.
 
*/
