/*Calculates the factorial of a number n through 
   iteration.*/

#include<stdio.h>

int factorial ( int n );/*function prototype*/

int main ( void ) 
{
   int x;
   int xfactorial;
   
   printf("Enter an integer to find the factorial of: \n");
   scanf("%d", &x);

   xfactorial =  factorial(x);
   printf("The %d factorial is %d\n", x, xfactorial);
} /*end main*/

/* Computes the nth factorial for example
   5! = 5 * 4 * 3 * 2 * 1  where 1! = 0! = 1 */
int factorial (int n ) {

   int i;
   int f;

   f = 1;
   for( i = n; i >= 1 ; i--) {
      f *= i;    
   }

   return f; 

} /* end  factorial */


