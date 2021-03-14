// Implements a dictionary's functionality

#include <stdbool.h>
#include <string.h>
#include <strings.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
// const unsigned int N = 50;   //My hash function [A+A, A+B, ..., Z+Z (50)]
const unsigned int N = 100000; //big big number to reduce time taken

// Hash table
node *table[N];

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    int index = hash(word);
    node *cursor = NULL;
    cursor = table[index];
    if (table[index] == NULL)
    {
        return false;
    }
    if (strcasecmp(word, cursor->word) == 0)   //check if the first word is in the linked list
    {
        return true;
    }
    else
    {
        for (cursor = table[index]; cursor != NULL; cursor = cursor->next)
        {
            if (strcasecmp(word, cursor->word) == 0)
            {
                return true;
            }
        }
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // Output is between 0 to (N-1) inclusive, [N is defined at the top of code]

    // =========== My Hash Function ==============
    // Sum of the first 2 values (the no of bins required will be 50) (bin 0 will be aa... and bin 50 will be zz...)
    // Change N to 50
    // Ensure sure that words with only one letter dont get summed and only abs values
    // if (strlen(word) > 1)   // > one letter words
    // {
    //     unsigned int value1;
    //     unsigned int value2;

    //     if (tolower(word[0]) < 97)  //if first char is '
    //     {
    //         value1 = 0;
    //     }
    //     else
    //     {
    //         value1 = abs(tolower(word[0]) - 97);
    //     }

    //     if (tolower(word[1]) < 97)  //if second char is '
    //     {
    //         value2 = 0;
    //     }
    //     else
    //     {
    //         value2 = abs(tolower(word[1]) - 97);
    //     }

    //     return (value1 + value2);
    // }

    // else    // one letter words
    // {
    //     if (tolower(word[0]) < 97)  //if first char is '
    //     {
    //         return 0;
    //     }
    //     unsigned int value = abs(tolower(word[0]) - 97);
    //     return value;
    // }
    // =========== End Of My Hash Function ==============

    // djb2 hash function from http://www.cse.yorku.ca/~oz/hash.html
    unsigned long hashed = 5381;
    int c;

    while ((c = *word++))
    {
        hashed = ((hashed << 5) + hashed) + tolower(c);
    }
    return hashed % N;
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    // Hash function -> Generate an integer where the word from dict will be placed into hash table
    // eg for just first letters hash table size [25], where [0] is A and so on..
    // or first 2 letters, hash table size [676], where [0] is A, [1] is AA and so on..

    // Open dictionary file
    FILE *dict = fopen(dictionary, "r");
    if (dict == NULL)
    {
        return false;
    }

    // Read strings from file
    char dictWord[LENGTH]; //Character array where the word is read into
    while (fscanf(dict, "%s", dictWord) != EOF)
    {
        // Create a new node
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            return false;
        }
        strcpy(n->word, dictWord);

        // Insert node into hash table using hash function
        // Hash word
        int index = hash(n->word);  //this number is the index for the hash table for that particular word

        if (table[index] == NULL)   //if there is no index for that word initially, then it will be "head"
        {
            table[index] = n;
            n->next = NULL;
        }
        else
        {
            n->next = table[index]; // (next) of new element point to first element of linked list first
            table[index] = n;   // old head point to new element
        }
    }
    fclose(dict);
    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    // Iterate through hash table
    int wordCount = 0;
    for (int i = 0; i < N; i ++)
    {
         node *cursor = table[i];
         while (cursor != NULL)
         {
             wordCount ++;
             cursor = cursor->next;
         }
    }
    return wordCount;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    for (int i = 0; i < N; i ++)
    {
        // head = table[i]
        node *cursor = table[i];

        while (cursor != NULL)
        {
            node *tmp = cursor;
            cursor = cursor->next;
            free(tmp);
        }
    }
    return true;
}
