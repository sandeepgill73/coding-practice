#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

/* Davis has s staircases in his house and he likes to climb each staircase 1, 2, or 3 steps at a time. Being a
very precocious child, he wonders how many ways there are to reach the top of the staircase.
Given the respective heights for each of the s staircases in his house, find and print the number of ways
he can climb each staircase on a new line. 
For example - for 3 stairs there are 4 ways; for 7 there are 44. 
*/

static int countpathsI(int);
static int countpathsDP(int, int *);
static int countpathsMemo(int, int*);
static int countpathsR(int);
    
int main(){
    int s; 
    scanf("%d",&s);
    if (s < 1 || s > 5) return -1;
    for(int a0 = 0; a0 < s; a0++)
    {
        int n; 
        scanf("%d",&n);
        if (n < 1 || n > 36) return -1;
        
        printf("%d\n", countpathsI(n));
        
        //int *paths = malloc(sizeof(int *) * (n + 1));
        //printf("%d\n", countpathsDP(n, paths));
        //free(paths);

        //int *memo = malloc(sizeof(int *) * (n + 1));
        //memset(memo, -1, sizeof(int *) * (n + 1));
        //printf("%d\n", countpathsMemo(n, memo));
        //free(memo);
        
        //printf("%d\n", countpathsR(n));
    }
    return 0;
}

// iterative approach takes space O(3), time O(n)
static int countpathsI(int steps)
{
    if(steps < 0) return 0;
    else if (steps <= 1) return 1;
    
    int paths[3] = {1, 1, 2};

    for (int i = 3; i <= steps; i++)
    {
        int count = paths[2] + paths[1] + paths[0];
        paths[0] = paths[1];
        paths[1] = paths[2];
        paths[2] = count;
    }
                    
    return paths[2];
}

//dynamic programming approach - space O(n), time O(n)
static int countpathsDP(int steps, int *paths)
{
    if(steps < 0) return 0;
    else if (steps <= 1) return 1;
    
    paths[0] = 1;
    paths[1] = 1;
    paths[2] = 2;

    for (int i = 3; i <= steps; i++)
    {
        paths[i] = paths[i-1] + paths[i-2] + paths[i-3];
    }
                    
    return paths[steps];
}

//memoization approach - space O(n) + recursive stack space, time O(n)
static int countpathsMemo(int steps, int *memo)
{
    if(steps < 0) return 0;
    else if (steps <= 1) return 1;

    if (memo[steps] == -1)
    {
        memo[steps] = countpathsmemo(steps - 1, memo) + 
                      countpathsmemo(steps - 2, memo) + 
                      countpathsmemo(steps - 3, memo);
    }
    
    return memo[steps];
}

//recursive approach - recursive stack space, solution times out for large value
static int countpathsR(int steps)
{
    if(steps < 0) return 0;
    else if (steps <= 1) return 1;
    else if (steps == 2) return 2;
    return countpathsR(steps - 1) + countpathsR(steps - 2) + countpathsR(steps - 3) ;
}
