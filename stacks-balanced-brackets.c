#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

/*
Two brackets are considered to be a matched pair if the an opening bracket (i.e., ( , [ , or { ) occurs to the
left of a closing bracket (i.e., ) , ] , or } ) of the exact same type . There are three types of matched pairs
of brackets: [] , {} , and () .
A matching pair of brackets is not balanced if the set of brackets it encloses are not matched. For
example, {[(])} is not balanced because the contents in between { and } are not balanced. The pair of
square brackets encloses a single, unbalanced opening bracket, ( , and the pair of parentheses encloses a
single, unbalanced closing square bracket, ] .

By this logic, we say a sequence of brackets is considered to be balanced if the following conditions are
met:
It contains no unmatched brackets.
The subset of brackets enclosed within the confines of a matched pair of brackets is also a matched
pair of brackets.

Given n strings of brackets, determine whether each sequence of brackets is balanced. If a string is
balanced, print YES on a new line; otherwise, print NO on a new line. 
*/

#define push(sp, n) (*((sp)++) = (n))
#define pop(sp) (*--(sp))

bool is_balanced(char expression[]) 
{
    unsigned long int len = strlen(expression);
    int stack[len];
    int *sp = (int *) &stack[0];

    for(unsigned long int i = 0; i < strlen(expression); i++)
    {           
        char c = expression[i];
        
        switch (c)
        {
            case '{':
            case '[':
            case '(':
                push(sp, c);
                break;
            case '}':
                if ((sp == &stack[0]) || (pop(sp) != '{'))
                    return false;
                break;
            case ']':
                if ((sp == &stack[0])  || (pop(sp) != '['))
                    return false;
                break;
            case ')':
                if ((sp == &stack[0])  || (pop(sp) != '('))
                    return false;
                break;       
        }
    }

    if (!(sp == &stack[0]))
        return false;

    return true; 
}

int main(){
    int t; 
    scanf("%d",&t);
    
    if ((t > 1000) || (t < 1)) return -1;
    
    for(int a0 = 0; a0 < t; a0++){
        char* expression = (char *)malloc(512000 * sizeof(char));
        scanf("%s",expression);
        
        unsigned long int len = strlen(expression);
        if ((len > 1000) || (len < 1)) return -1;
        
         bool answer = is_balanced(expression);
         if(answer)
          printf("YES\n");
         else
          printf("NO\n");
    }
    return 0;
}
