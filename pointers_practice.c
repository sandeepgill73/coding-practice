//pointers practice
#include <stdio.h>
int main(void)
{
 
 char acData[5] ={'4','3','2','4','5'};
 char *pcData = NULL;
 //char *pcData = "ABCDEF";

 pcData = acData;
 printf("Addr = %x \n", pcData);
 
 /* This prints 2 and address incremented by 1*/
 pcData = acData;
 pcData++;
  printf("pcData++;\n");
 printf("Data = %c \n", *pcData);
 printf("Addr = %x \n", pcData);
 
 /* This prints 2 and address incremented by 1*/
 pcData = acData;
 *pcData++;
  printf("*pcData++;\n");
 printf("Data = %c \n", *pcData);
 printf("Addr = %x \n", pcData);
 
 /* This prints 2 and address not incremented */
 pcData = acData;
 (*pcData)++;
 printf("(*pcData)++;\n");
 printf("Data = %c \n", *pcData);
 printf("Addr = %x \n", pcData);
 
 /* This prints 2 and address incremented by 1 */
 pcData = acData;
 (*pcData++);
  printf("(*pcData++);\n");
 printf("Data = %c \n", *pcData);
 printf("Addr = %x \n", pcData);
 
 /* This prints 2 and address incremented by 1 */
 pcData = acData;
 *++pcData;
 printf(" *++pcData;\n");
 printf("Data = %c \n", *pcData);
 printf("Addr = %x \n", pcData);
 
 /* This prints 2 and address incremented by 1 */
 pcData = acData;
 (*++pcData);
  printf("  (*++pcData);\n");
 printf("Data = %c \n", *pcData);
 printf("Addr = %x \n", pcData);

 
 return 0;
}