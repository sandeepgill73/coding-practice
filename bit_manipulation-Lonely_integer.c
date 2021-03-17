#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int main(){
    int n; 
    scanf("%d",&n);
    if (n < 1 || n >= 100) return -1;
    int *a = malloc(sizeof(int) * n);
    int result = 0;
    for(int a_i = 0; a_i < n; a_i++)
    {
        scanf("%d",&a[a_i]);
        if(a[a_i] < 0 || a[a_i] > 100) return -1;
        result ^= a[a_i];
    }
    printf("%d", result);
    return 0;
}
