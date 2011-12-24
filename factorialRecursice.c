/* Computes the n factorial using recursion*/
#include<stdio.h>

long factorial(long n); /*function prototype*/
 

int main (void) 
{
   long fact;
   int i;/*counter*/

   for(i = 0; i <=10 ; i++ ) {
     fact = factorial(i);
     printf("%2d! = %ld\n", i, fact);
   }

}/*end main*/

/*factorial uses a long: anything past factorial(16) goes 
   beyond the limit of int, factorial(17) goes beyond the limit of long*/
long factorial (long n) 
{
   
   if (n == 1)      return 1;/*base case*/
   else if (n == 0) return 1;/*base case*/
   
   /*recursive*/
   else {
      return (n * factorial (n-1));
   }
}/*end factorial*/
