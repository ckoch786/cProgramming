/* recursively computes the nth fibonacci number */
#include<stdio.h>

long fibo ( long n ); /*function prototype*/

int main ( void )
{
   int i; /*counter*/

   for ( i = 0; i < 10; i++ ) {
      printf( "  fibo(%d) = %ld\n", i, fibo(i) );
   }
   
   return 0;/* indicates successful termination*/

}/*end main*/

/*Recursively computes the nth fibonacci number*/
long fibo ( long n )
{
   /*if (n == 0)      return 0;
   else if (n == 1) return 1; 
       Or a more elegant way */
   if ( n == 0 || n ==1 ) return n; /*base case*/
   else { /*recursive step*/
      return ( fibo(n-1) + fibo(n-2) );
   }
}/*end fibo*/
