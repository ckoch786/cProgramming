/*Creating and using a programmer-defined function*/

#include<stdio.h>

int square( int y ); /* function prototype */
//int square ( y ) 
  //          int y; 


int main( void ) {
   int i;

   for( i = 1; i <= 10; i++ ) {
      printf( "%d ", square( i ) ); /*function call*/
   } /*end for */

   printf("\n");

   return 0;

}/* end main */

/* square function definition returns square of parameter
   y is a copy of argument to function*/
int square ( int y ) { return y * y; }

/*Note: int square ( int y ) is  reffered to as the function
header*/
