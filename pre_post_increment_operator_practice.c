//pre increment and post increment practice
#include <stdio.h>
int main()
{
    int a = 5;
    //int g = a++ + ++a + a++; // Gives output 18 on VC++ compiler, 19 on GDB compiler
    //int g = ++a + ++a + a++; // Gives output 21 on VC++ compiler, 21 on GDB compiler
    //int g = ++a + ++a + ++a; // Gives output 24 on VC++ compiler, 22 on GDB compiler
    //int g = a++ + a++ + a++; // Gives output 15 on VC++ compiler, 18 on GDB compiler
    printf("value of a = %d\n",a);
    printf("value = %d\n",g);
    return 0;
}
