// 1. REVERSE bits
#include <stdio.h>
#define CHAR_BITS  8  // size of character
#define INT_BITS  ( sizeof(int) * CHAR_BITS) //bits in integer
unsigned int ReverseTheBits(unsigned int num)
{
unsigned int iLoop = 0;
unsigned int tmp = 0;         
int iNumberLopp = (INT_BITS - 1);     
for(; iLoop < iNumberLopp; iLoop++)
{
if((num & (1 << iLoop))) 
{
tmp |= 1 << ((INT_BITS - 1) - iLoop);
}    
}
return tmp;
}

unsigned int ReverseTheBits2(unsigned int num)
{
unsigned int iLoop = 0;
unsigned int tmp = 0;         
int iNumberLopp = (INT_BITS - 1);
for(; iLoop < iNumberLopp; iLoop++)
{
tmp |= num & 1; 
num >>= 1; 
tmp <<= 1; 
}
return tmp;
}

unsigned int ReverseTheBits3(unsigned int x)
{
	x = (((x & 0xaaaaaaaa) >> 1) | ((x & 0x55555555) << 1));
	x = (((x & 0xcccccccc) >> 2) | ((x & 0x33333333) << 2));
	x = (((x & 0xf0f0f0f0) >> 4) | ((x & 0x0f0f0f0f) << 4));
	x = (((x & 0xff00ff00) >> 8) | ((x & 0x00ff00ff) << 8));
	return((x >> 16) | (x << 16));
}


void fun(unsigned n)
{
short int iPos;
for (iPos = (INT_BITS -1) ; iPos >= 0 ; iPos--)
{
(n & (1 << iPos))? printf("1"): printf("0");	
}
printf("\n");
}

int main()
{
fun(ReverseTheBits(15));
fun(ReverseTheBits2(15));
fun(ReverseTheBits3(15));
return 0;
}
