#include <stdio.h>

// With Recursion 
int fibonacci_rec(int n) 
{
    if (n <= 1) return n;
    if (n >=2)
    {
        return fibonacci_rec(n-1) + fibonacci_rec(n-2);
    }
    
    return -1;
};

// Without Recursion 
int fibonacci(int n)
{
	int prev = -1;
	int result = 1;
	int sum;
	int i;
	
	for(i = 0;i <= n;++ i)
	{
		sum = result + prev;
		prev = result;
		result = sum;
	}
	
	return result;
}

int main() {
    int n;
    scanf("%d", &n);
    if (n < 0 || n > 30) return -1;
    printf("%d", fibonacci(n));
    return 0;
}