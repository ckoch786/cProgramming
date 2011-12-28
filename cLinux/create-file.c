/* Creates a new file using Linux system calls 
 *    With the Linux low-level I=O operations, you use a handle caled a 
 * 'file desciptor' instead of a FILE* pointer. A file descriptor is a 
 * an integer value that refers to a particular instace of an open file in a single 
 * process. It can be open for reading, for writing, or for both reading and writing. 
 * A file desciptor doesn't have to refer to an open file;
 * it can represent a connection with another system compnent
 * that is capable of sending or recieving data. For example a connection 
 * to a hardware device is represented by a file descriptor, as is an open socket,
 * or one end f a pipe. */

#include <fcntl.h> /* header files for low-level I/O functions */
#include <stdio.h>
#include <sys/stat.h> /* header files for low-level I/O functions */
#include <sys/types.h> /* header files for low-level I/O functions */
#include <unistd.h> /* header files for low-level I/O functions */

/* Creates a new file with the filename specified on the command
 * line. It uses the O_EXCL flag with open, so if the file aready exits, 
 * an error occurs. The new file is given read and write permissions for the owner
 * and owing goup, and read permissions only for others. ( if your umask is
 * set to a nonzero value, the actual permissions may be more restrictive.) */
int main (int argc, char* argv[])
{
   /* The path at which to create the new file. */
   char* path = argv[1];
   /* The permissions for the new file. */
   mode_t mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH;

   /* Create the file. */
   int fd = open (path, O_WRONLY | O_EXCL | O_CREAT, mode);
   if ( fd == -1 ) {
      /* An error occured. Print an error message and bail. */
      perror ("open");
      return 1;
}
   return 0; /* indicates successful termination */
}/* end main */
