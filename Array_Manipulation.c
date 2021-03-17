#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

/* 
You are given a list(1-indexed) of size n, initialized with zeroes. You have to perform m operations on the
list and output the maximum of final values of all the n elements in the list. For every operation, you are
given three integers a, b and k and you have to add k value to all the elements ranging from index a to b (both inclusive).
Consider list a of size 3, the initial list would be a = [0,0,0] and after performing the update 2,3,30 the
new list would be = [0, 30, 30]. 
*/

int main() {
    long long int n; 
    long long int m; 
    scanf("%lld %lld", &n, &m);

    if ((n < 3) || (n > 10000000)) return -1;
    if ((m < 1) || (m > 200000)) return -1;
    
    long long int *list = (long long int *) malloc(sizeof(long long int *) * (n + 1));
    //memset(list, 0, sizeof(long long int *) * (n + 1));
    
    long long int max = 0;
    
    for(long long int a0 = 0; a0 < m; a0++)
    {
        long long int a; 
        long long int b; 
        long long int k; 
        scanf("%lld %lld %lld", &a, &b, &k);
        
        if ((a < 1) || (a > b)) return -1;
        if ((b < a) || (b > n)) return -1;
        if ((k < 0) || (k > 1000000000)) return -1;
        
        /* This loop times out
        for(long long int j = a; j <= b; j++)
        {
            list[j] += k;
            if (list[j] > max)
            {
                max = list[j];
            }
        }
        */
        
        /* Instead of storing the actual values in the array, 
           store the difference between the current element and 
           the previous element. By the end of all this, you have 
           an array that shows the difference between every 
           successive element. */
        list[a] += k;
        if((b + 1) <= n) 
        {
            list[b + 1] -= k;
        }
    }
    
    long long int x = 0;
    for(long long int i = 1;i <= n;i++)
    {
        /* By adding all the positive differences, 
           you get the value of the maximum element */
        x = x + list[i];
        
        if(max < x) 
        {
            max = x;
        }
    }
    
    printf("%lld", max);
    return 0; 
}