/* A program with a widget(a button). that displays hello world
   a la GTK */

#include <gtk/gtk.h>

/* This is a callback function (That will be called when the button
 * is "clicked"). The data arguments are ignored in this example. 
 * More on callbacks below. */

static void hello ( GtkWidget *widget,
                    gpointer  data)
{
   g_print ("Hello World!\n");
}

/* This is also a callback function. This occurs when the window
 * manager sends this event to the application.*/
static gboolean delete_event( GtkWidget  *widget,
                              GdkEvent   *event, 
			      gpointer    data )
{
   /* If you return FALSE in the "delete-event" signal handler,
    * GTK will emit the "destroy" signal. Returning TRUE means
    * you don't want the window to be destroyed.
    * This is useful for popping up 'are you sure you want to quit?'
    * type dialogs. */

    g_print ( "delete event occured\n");

    /* Change TRUE to FALSE and the main window will be destroyed 
     * with a "delete-event". */
     
    return TRUE;

}/* end delete_event */

/*Another callback which is called by delete_event. This is called
 * out "destroy" signal handler. */
static void destroy ( GtkWidget  *widget,
                      gpointer    data )
{
   gtk_main_quit();
}

int main (int   argc,
          char *argv[] )
{
   /* (pointers to a structure of type)GtkWidget is the storage 
    * type for widgets */
   GtkWidget *window;
   GtkWidget *button;

   /* This is called in all GTK applications. Arguments are passed
    * from the command line and are returned to the application. 
    * This initializes the toolkit, and parses the arguments found
    * on the command line. */
    gtk_init (&argc, &argv);

    /* create a new window */
    window = gtk_window_new (GTK_WINDOW_TOPLEVEL);

    /* When the window is given the "delete-event" signal (this is 
     * given by the window manager, usually by the "close" option, 
     * or on the titlebar), we ask it to call the delete_event()
     * function as defined above. The data passed to the callback
     * function is NULL and is ignored in the callback function. 
     * G_CALLBACK is a macro that performs type casting and checking
     * for us, as well as aid the readability of the code. */
     g_signal_connect (window, "delete-event",
                       G_CALLBACK (delete_event), NULL);

     /* Here we connect the "destroy" event to a signal handler. 
      * This event occurs when we call gtk_widget_destroy() on the
      * window, or if we return FALSE in the "delete-event" 
      * callback*/
     g_signal_connect (window, "destroy",
                       G_CALLBACK (destroy), NULL);

     /* Sets the border width of the window. Which is an attribute
      * of the container object. GTL_CONTAINER is a macro to perform
      * type casting. */
     gtk_container_set_border_width (GTK_CONTAINER (window), 10);

     /* Creates a new button with the label "Hello World!". */
     button = gtk_button_new_with_label ("Hello World!");

     /* When the button recieves the "clicked" signal, it will call 
      * the function hello() passing it NULL as its argument. 
      * The hello() function is defined above. */
     g_signal_connect (button, "clicked",
                       G_CALLBACK (hello), NULL);

     /* This will cause the window to be destroyed by calling 
      * gtk_widget_destroy(window) when "clicked". Again, the destroy      * signal would come from here, or the window manager. */
     g_signal_connect_swapped (button, "clicked",
	                       G_CALLBACK (gtk_widget_destroy),
			       window);

     /*This(is a packing call) packs the button into the window 
      * (a gtk container). */
     gtk_container_add (GTK_CONTAINER (window), button);
     
     /*The final step is to display this newly created widget. */
     gtk_widget_show (button);
 
     /* and the window */
     gtk_widget_show (window);

     /* All GTK applications must have a gtk_main(). Control ends 
      * here and waits for an event to occur (like a key press or 
      * mouse event). */
     gtk_main();

     return 0;

}
