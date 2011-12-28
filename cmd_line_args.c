/*On many systems, it is possible to pass arguments to main from a command line by 
including parameters int argc and char *argv[] in the parameter list of main. 
Parameter `argc' recieves the number of command-line arguments. Parameter `argv' 
is an array of strings in which the actual command-line arguments are stored. 
Common used of command-line arguments include passing options to a program and 
passing filenames to a program. 
  cmd_line_args.c 
      copies another file one character at a time. We assume that the executable
      file for the program is called mycopy. A typical command line for the mycopy 
      program on a Linux/Unix system is
         $ mycopy input output
      This command line indicates that file input is to be copied to file output.
      When the program is executed, if argc is not 3( mycopy counts as one of the 
      arguments), the program prints an error message and terminates. Otherwise,
      array argv contains the strings "mycopy", "input", and "output". The second
      and third arguments on the command line are used as file names by the program.
      The files are opened using function fopen. If both files are opened successfully,
      characters are read from file input and writted to file output untill the end-if-file
      indicator for file input is set. Then the  program terminates. 
*/

#include <stdio.h>

int main ( int argc, char *argv[] )
{
   FILE *inFilePtr; /* input file pointer*/
   FILE *outFilePtr; /*output file pointer*/
   int   c;         /*define c to hold charaters input by user*/

   /*check number of command-line arguments */
   if ( argc !=3 ) {
      printf( "Usage: mycopy infile outfile\n" );
   }
   else {
       /* if input file can be opened */
       if ( ( inFilePtr = fopen ( argv[ 1 ], "r" ) ) != NULL ) {
	   
	   /*if output file can be opened*/
	   if ( ( outFilePtr = fopen ( argv[ 2 ], "w" ) ) != NULL ) {

	       /* read and output characters */
	       while ( ( c = fgetc( inFilePtr ) ) != EOF ) {
		   fputc( c, outFilePtr );
	       }/*end while*/
	  }/*end if*/
	  else { /* output file could not be opened */
	      printf( "File \"%s\" could not be opened\n", argv[ 2 ] );
	  }/*end else*/
       }/* end if */
       else{ /* input file could not be opened */
	   printf( "File \"%s\" could not be opened\n", argv[ 1 ] );
       }/* end else */
   }/* end else */

   return 0; /* indicate successful termination */

}/*end main */
