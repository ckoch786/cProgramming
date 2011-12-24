/* Addition Program */

#include<stdio.h>

int main( void ) {
   
   int num1;
   int num2;
   int sum;

   printf( "Enter the first integer\n" );
   scanf( "%d", &num1);
   /*Note: scanf takes two arguments
      the first is the "format control string"
      the %d "conversion specifier" indicates that 
      the data should be an integer.
      The second argument begins with an & which is 
      called the (address operator) in C. */

   printf("Enter the second integer\n");
   scanf("%d", &num2);

   sum = num1 + num2;

   printf("Sum id %d\n", sum);

   return 0;

}/* end function main*/
