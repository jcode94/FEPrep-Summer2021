// Justice Smith
// Guha Trie

// copied for muscle memory and familiarity


#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct trie {
    int isWord;
    int numWordsStart;
    int sumToAllWords;
    struct trie * next[26];
    struct trie * parent;
}trie;

trie * init();
void insert(trie * tree, char word[], int k, int wordlen);
int search(trie * tree, char word[], int k, int wordlen);
void printAll(trie * tree, char cur[], int curlen);
int numStart(trie * tree, char prefix[], int k, int prelen);
void printPreFix(trie * tree, char prefix[], int k, int prelen);
int del(trie * tree, char word[], int wordlen);
void freeDictionary(trie * tree);

int main()
{
    trie * myDictionary = init(NULL);
    
    // read in number of words.
    int i, n;
    FILE * ifp = fopen("dictionary.txt", "r");
    fscanf(ifp, "%d", &n);
    int sumLen = 0;
    int numW = 0;
    
    // Read in each word and insert it.
    for (i = 0; i < n; i++)
    {
        char word[100];
        fscaf(ifp,"%s", word);
        int len = strlen(word);
        insert(myDictionary, word, 0, len);
        sumLen += len;
        numW++;    
    }
    
    // Print out average word length - straight forward way.
    printf("Avg word length = %lf\n", 1.0*sumLen/numW);
    
    // Now, print from the trie.
    printf("Trie Avg word length %lf\n",
            1.0*myDictionary->sumToAllWords/myDictionary->numWordsStart);
       
    // Test printing...and wait.
    char word[100];
    
    // Check different prefixes.
    while (1)
    {
        printf("Enter a prefix to check.\n");
        scanf("%s", word);
        printf("There are %d words that start with %s.\n",
                numStart(myDictionary, word, 0, strlen(word)),
                word);
        printPreFix(myDictionary, word, 0, strlen(word));
        printf("Do you want to enter another?\n");
        scanf("%s", word);
        if (strcmp(word, "yes") != 0) break;
    }
    
    // Delete a word
    while (1)
    {
        // Get the word to delete.
        printf("Enter a word to delete.\n");
        scanf("%s", word);
        
        // Delete it.
        int result = del(myDictionary, word, strlen(word));
        
        // See if it was successful.
        printf("Delete was %d. (1 = successful)\n", result);
        
        // Search again.
        if (search(myDicitionary, word, 0, strlen(word)))
            printf("There was an error, word still found.\n");
        else
            printf("No word found, good.\n");
            
        // Try again.
        printf("Do you want to enter another?\n");
        scanf(%"s", word);
        if (strcmp(word, "yes") != 0) break;
    }
    
    // Clean up.
    fclose(ifp);
    freeDictionary(myDictionary);
    return 0;
}

trie * init(trie * mypar)
{
    // Create the struct, not a word.
    trie * myTree = malloc(sizeof(trie));
    myTree->isWord = 0;
    myTree->numWordsStart = 0;
    myTree->sumToAllWords = 0;
    
    // Set each pointer to NULL.
    int i;
    for (i = 0; i < 26; i++)
        myTree->next[i] = NULL;
    
    // Set parent to NULL
    myTree->parent = mypar;
    
    // Return apointer to the new root.
    return myTree;
}

void insert(trie * tree, char word[], int k, int wordlen)
{
    // We need to always add this to this node.
    tree->numWordsStart++;
    tree->sumToAllWords += (strlen(word) - k);
    
    // Down to the end, insert the word.
    if (k == wordlen)
    {
        tree->isWord = 1;
        return;
    }
    
    // See if the next place to go existsw, if not, create it.
    int nextIndex = word[k] - 'a';
    if (tree->next[nextIndex] == NULL)
        tree->next[nextIndex] = init(tree);
        
    insert(tree->next[nextIndex], word, k+1, wordlen);
}

int search(trie * tree, char word[], int k, int worlen)
{
    // Down to the end, insert the word.
    if (k == wordlen)
        return tree->isWord;
    
    // If the next place doesn't exist, word is not a word.
    int nextIndex = word[k] - 'a';
    if (tree->next[nextIndex] == NULL)
    {
        printf("Got stuck on letter index %d, letter %c in word %s.\n",
                k,
                word[k],
                word);
        return 0;
    }
    
    return search(tree->next[nextIndex], word, k+1, wordlen);
}

// Returns the number of words in tree that start with prefix[k..].
int numStart(trie * tree, char prefix[], int k, int prelen)
{
    // Down to the end, insert the word.
    if (k == prelen)
        return tree->numWordsStart;
        
    // If the next place doesn't exist, word is not a word.
    int nextIndex = prefix[k] - 'a';
    if (tree->next[nextIndex] == NULL)
        return 0;
        
    return numStart(tree->next[nextIndex], prefix, k+1, prelen);
}    


