#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int check_prime(int a);

int main()
{
    int p; 
    scanf("%d",&p);
    
    if((p < 1) || (p > 30)) return -1;
    
    for(int a0 = 0; a0 < p; a0++)
    {
        int n; 
        scanf("%d",&n);
        
        if ((n < 1) || (n > 2000000000))
        {
            return -1;
        }
        else if (n == 1)
        {
            printf("Not prime\n");
        }
        else
        {
            if (check_prime(n))
            {
                printf("Prime\n");
            }
            else
            {
                printf("Not prime\n");
            }
        }  
    }
    
    return 0;
}

int check_prime(int a)
{
    int c;
    //Faster solution
    for (c = 2; c <= (int)sqrt(a); c++)
    { 
       if (a % c == 0)
       {
          return 0;
       }
    }

    return 1;
    
    /*// Slower solution
    for (c = 2 ; c <= a - 1 ; c++ )
    {
        if (a % c == 0)
        {
            return 0;
        }
    }
    
    if (c == a)
    {
        return 1;
    }
    
    return 0;*/
}
