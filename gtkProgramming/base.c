/* Creates a 200x200 pixel window */

#include <gtk/gtk.h>

int main ( int   argc,
           char  *argv[] )
{
   GtkWidget *window;

   gtk_init (&argc, &argv);

   window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
   gtk_widget_show (window);

   gtk_main ();/* enter the GTK main processing loop*/

   return 0;
} /* end main */
