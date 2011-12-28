/* Using temporary files 
 * Changes the tabs in a file to spaces. The program prompts the user to 
 * enter the name of a file to be modified. If the file entered by the user 
 * and the temporary file are opened successfully, the program reads characters 
 * from the file to be modified and writes them to the temporary file. If the character
 * read is a tab ('\t'), it is replaced by a space and writted to the temporary file.
 * When the end of the file being modified is reached, the file pointer for each file
 * are repositioned to the start of each file with `rewind'. Next, the temporary file
 * is copied into the original file one character at a time. The program prints the 
 * original file as it copied characters into the temporary file and prints the new
 * file as it copies characters from the temporary file to the original file to 
 * confirm the characters being written. */

#include <stdio.h>

int main ( void )
{
   FILE *filePtr;    /* pointer to file being modified*/
   FILE *tempFilePtr; /* temporary file pointer */
   int   c;           /*define c to hold characters read from a file. */
   char  fileName[ 30 ]; /* create char array */

   printf( "This program changes tabs to spaces.\n"
      "Enter a file to be modified: ");
   scanf( "%29s", fileName );

   /* fopen opens the file */
   if( ( filePtr = fopen ( fileName, "r+" ) ) != NULL ) {

       /* create temporary file */
       if ( ( tempFilePtr = tmpfile() ) != NULL ) {
	   printf( "\nThe file before modification is:\n" );

	   /* read characters from file and place in temporary file */
	   while( (c = getc( filePtr ) ) != EOF ) {
	       putchar( c );
	       putc (c == '\t' ? ' ': c, tempFilePtr );
	   }/* end while */
	   rewind( tempFilePtr );
	   rewind( filePtr );
	   printf( "\n\nThe file after modification is:\n");

	   /* read from temporary file and write into original file */
	   while ( ( c = getc( tempFilePtr ) ) != EOF ) {
	       putchar( c );
	       putc( c, filePtr );
	   }/*end while */
       }/* end of */
       else { /* if temporary file could not be opened */
	   printf( "Unable to open temporary file\n" );
       }/*end else*/
   }/*end if*/
   else { /* if file could not be opened */
       printf( "Unable to open %s\n", fileName );
   }/*end else */

   return 0; /* indicate successful termination */

}/*end main */

