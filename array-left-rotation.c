#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

/*
Given an array of n integers and number d, perform d left rotations on the array. Then print the
updated array as a single line of space-separated integers 
*/
int main(){
    int n; 
    int d;
    int fst;
    int lst;
    int new_index;
    
    scanf("%d %d",&n,&d);
    if((n > 100000) || (n < 1)) 
    {
        return -1;
    }
    
    if((d > n) || (d < 1)) 
    {
        return -1;
    }

    int *a = malloc(sizeof(int) * n);
    int *new_arr = malloc(sizeof(int) * n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d",&a[i]);
        if((a[i] > 1000000) || (a[i] < 1))
        {
            return -1;
        }
    }
    
    for(int i = 0; i < n; i++)
    {
        new_index = (i + d) % n;
        new_arr[i] = a[new_index];
    }
    
    for(int i = 0; i < n; i++)
    {
        printf("%d ",new_arr[i]);
    }
    
    
    return 0;
}
