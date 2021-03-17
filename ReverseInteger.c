/*
Given a 32-bit signed integer, reverse digits of an integer.
Assume we are dealing with an environment which could only hold integers within 
the 32-bit signed integer range. For the purpose of this problem, 
assume that your function returns 0 when the reversed integer overflows.
*/

int reverse(int x) 
{
	/* long long make res a 64 bit number, the overflow is checked.*/
    long long res = 0;
    while(x) 
    {
        res = res*10 + x%10;
        x /= 10;
    }
    
    return (res<INT_MIN || res>INT_MAX) ? 0 : res;
}   