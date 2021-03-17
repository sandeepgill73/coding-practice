/*
Implement atoi to convert a string to an integer.

sizeof(int) is 2bytes
maximum value of int: 32767
minimum value of int: -32768

sizeof(int) is 4bytes
maximum value of int: 2147483647
minimum value of int: -2147483648

discards all leading whitespaces
sign of the number
overflow
invalid input
*/

int myAtoi(char* str) 
{
    int sign = 1, base = 0, i = 0;
    
    while (str[i] == ' ')
    { 
        i++; 
    }
    
    if (str[i] == '-' || str[i] == '+') 
    {
        sign = 1 - 2 * (str[i++] == '-'); 
    }
    
    while (str[i] >= '0' && str[i] <= '9') 
    {
        if (base >  INT_MAX / 10 || (base == INT_MAX / 10 && str[i] - '0' > 7)) 
        {
            if (sign == 1) 
            {
                return INT_MAX;
            }
            else 
            {
                return INT_MIN;
            }
        }
        
        base  = 10 * base + (str[i++] - '0');
    }
    
    return base * sign;
}