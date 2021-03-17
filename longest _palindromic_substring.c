/* 
Given a string s, find the longest palindromic substring in s. 
You may assume that the maximum length of s is 1000.
*/

// A dynamic programming solution for longest palindr.
// This code is adopted from following link
// http://www.leetcode.com/2011/11/longest-palindromic-substring-part-i.html
//Time complexity: O ( n^2 )
//Auxiliary Space: O ( n^2 )
 
#include <stdio.h>
#include <string.h>
 
// A utility function to print a substring str[low..high]
void printSubStr( char* str, int low, int high )
{
    for( int i = low; i <= high; ++i )
        printf("%c", str[i]);
}
 
// This function prints the longest palindrome substring
// of str[].
// It also returns the length of the longest palindrome
int longestPalindrome( char *str )
{
    int maxLength = 1;  // The result (length of LPS)
 
    int start = 0;
    int len = strlen(str);
 
    int low, high;
 
    // One by one consider every character as center point of 
    // even and length palindromes
    for (int i = 1; i < len; ++i)
    {
        // Find the longest even length palindrome with center points
        // as i-1 and i.  
        low = i - 1;
        high = i;
        while (low >= 0 && high < len && str[low] == str[high])
        {
            if (high - low + 1 > maxLength)
            {
                start = low;
                maxLength = high - low + 1;
            }
            --low;
            ++high;
        }
 
        // Find the longest odd length palindrome with center 
        // point as i
        low = i - 1;
        high = i + 1;
        while (low >= 0 && high < len && str[low] == str[high])
        {
            if (high - low + 1 > maxLength)
            {
                start = low;
                maxLength = high - low + 1;
            }
            --low;
            ++high;
        }
    }
 
    printf("Longest palindrome substring is: ");
    printSubStr( str, start, start + maxLength - 1 );
 
    return maxLength; // return length of LPS
}
 
// Driver program to test above functions
int main()
{
    char str[] = "forgeeksskeegfor";
    printf("nLength is: %dn", longestPalindrome( str ) );
    return 0;
}


/* return result string
char* t = (char*)malloc(sizeof(char)*(maxLength+1));
memcpy(t, str+start, sizeof(char)* maxLength);
t[maxLength] = '\0';
return t;
*/
