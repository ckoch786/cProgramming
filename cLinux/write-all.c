/* Write all of COUNT bytes from BUFFER to file descriptor FD.
 * Returns -1 on error, or the number of bytes written. */

ssize_t write_all (int fd, const void* buffer, size_t count)
{
   size_t left_to_write = count;
   while (left_to_write > 0) {
      size_t written = write (fd, buffer, count);
      if (written == -1)
         /* An error occurred; bail */
	 return -1;
      else
         /* Keep count of how much more we need to write. */
	 left_to_write -= written;
   }
   /* We should have written no mote that COUNT bytes! */
   assert (left_to_write == 0);
   /* The number of bytes written is exactly COUNT */
   return count;
}/* end  write_all*/
