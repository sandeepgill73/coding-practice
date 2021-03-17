/*
Given a non negative integer number num. 
For every numbers i in the range 0 ≤ i ≤ num calculate the 
number of 1's in their binary representation and return them as an array.

Example:
For num = 5 you should return [0,1,1,2,1,2]

run time O(n)
Space complexity should be O(n).
*/

int* countBits(int num) 
{
    int *ret = (int *) (malloc(sizeof(int) * (num + 1)));
    
    if(num >= 0)
    {
        ret[0] = 0;
    }

    for(int i = 1;i <= num; i++)
    {
        
        ret[i] = ret[i/2] + i%2;
    }
    
    return ret;
}
