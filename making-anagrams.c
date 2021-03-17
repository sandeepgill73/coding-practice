#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

/* We consider two strings to be anagrams of each other if the first string's letters can be 
rearranged to form the second string. In other words, both strings must contain the same exact 
letters in the same exact frequency For example, bacdc and dcbac are anagrams, but bacdc and dcbad are not.
Given two strings, a and b, that may or may not be of the same length, determine the minimum number
of character deletions required to make a and b anagrams. Any characters can be deleted from either of
the strings. 
*/
int main(){
    char* a = (char *)malloc(512000 * sizeof(char));
    scanf("%s",a);
    char* b = (char *)malloc(512000 * sizeof(char));
    scanf("%s",b);
    
    unsigned long int len1 = strlen(a);
    unsigned long int len2 = strlen(b);
    
    if ((len1 > 10000) || (len1 < 1) || (len2 > 10000) || (len2 < 1)) 
    {
        return -1;
    }
    
    int *lettercounts = (int *) malloc(26 * sizeof(int));
    
    for(unsigned long int i = 0; i < len1; i++)
    {
        char c = a[i];
        lettercounts[c - 'a']--;
    }
    
    for(unsigned long int i = 0; i < len2; i++)
    {
        char c = b[i];
        lettercounts[c - 'a']++;
    }
    
    int result = 0;
    
    for(int i = 0; i < 26; i++)
    {
        result += abs(lettercounts[i]);
    }
    
    printf("%d", result);
    
    return 0;
}
