#include "includes.h"
#include <webkit/webkit.h>
#include "common.h"
#include "browser.h"
static void win_cb_destroy(GtkWidget *win, struct browser_context *ctx)
{
	wpa_printf(MSG_DEBUG, "BROWSER:%s", __func__);
	gtk_main_quit();
}
