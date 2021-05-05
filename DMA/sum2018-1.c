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
// I have chosen this problem because it scored the 3rd lowest in the last 
// 5 years for the DMA question.

/*
1)(5pts) DSN(Dynamic Memory Management in C)
Suppose we have an array of structures containing information about our 
group for a group project. 

Each index should contain a group member’s name and phone number.  
The structure is shown below: 
    names are stored as dynamically allocated strings and 
    phone numbers are stored as integers.  

When the semester is over, we will delete this array. 
Write a function called deleteGroup that will take in this array and 
delete all the information, freeing all the memory space that 
the array previously took up. 

Your function should take 2 parameters: 
    a pointer to the beginning of the array and 
    an integer indicating the number of group members. 

It should return a null pointer representing the now empty array.

*/

typedef struct GroupMember {
    char *name;
    int phoneNumber;
} GroupMember;

GroupMember* deleteGroup (GroupMember *group, int numMembers)
{
    int i;
    
    for (i = 0; i < numMembers; ++i)
    {
        free(group[i].name);
    }
    free(group);
    
    return NULL;
}
