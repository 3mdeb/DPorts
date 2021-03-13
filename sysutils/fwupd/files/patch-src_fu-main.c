--- src/fu-main.c.orig	2021-02-23 14:54:50 UTC
+++ src/fu-main.c
@@ -14,7 +14,9 @@
 #include <glib/gi18n.h>
 #include <glib-unix.h>
 #include <locale.h>
+#ifndef __DragonFly__
 #include <malloc.h>
+#endif
 #ifdef HAVE_POLKIT
 #include <polkit/polkit.h>
 #endif
@@ -2037,9 +2037,10 @@ main (int argc, char *argv[])
 	else if (timed_exit)
 		g_timeout_add_seconds (5, fu_main_timed_exit_cb, priv->loop);
 
+#ifdef __linux__
 	/* drop heap except one page */
 	malloc_trim (4096);
-
+#endif
 	/* wait */
 	g_message ("Daemon ready for requests (locale %s)", g_getenv ("LANG"));
 	g_main_loop_run (priv->loop);
