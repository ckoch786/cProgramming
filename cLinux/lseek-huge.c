/* Create Large Files with lseek
 * Takes as command-line arguments a filename and a target file size
 * in megabytes. The program opens a new file, advances past the end 
 * of the file using lseek, and then writes a single 0 byte before 
 * closing the file. */
#include <fcntl.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main (int argc, char* argv[])
{
   int zero = 0;
   const int megabyte = 1024 * 1024;

   char* filename = argv[1];
   size_t length = (size_t) atoi (argv[2]) * megabyte;

   /* Open a new file. */
   int fd = open (filename, O_WRONLY | O_CREAT | O_EXCL, 0666);
   /* Jump to 1 byte short of where we want the file to end. */
   lseek (fd, length - 1, SEEK_SET);
   /* Write a single 0 byte. */
   write (fd, &zero, 1);

   /*All done */
   close(fd);

   return 0; /*indicates successful termination*/
}/*end main*/
