#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif
#include <stdlib.h>
#include "lkc.h"
#include "images.c"
#include <glade/glade.h>
#include <gtk/gtk.h>
#include <glib.h>
#include <gdk/gdkkeysyms.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
void on_window1_destroy(GtkObject * object, gpointer user_data)
{
	gtk_main_quit();
}
#if GTK_CHECK_VERSION(2,1,4) // bug in ctree with earlier version of GTK
#else
#endif
#ifdef DEBUG
#endif
#ifdef DEBUG
#endif
