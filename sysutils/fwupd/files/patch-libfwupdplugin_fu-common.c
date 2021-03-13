--- libfwupdplugin/fu-common.c.orig	2021-02-23 14:54:50 UTC
+++ libfwupdplugin/fu-common.c
@@ -2257,7 +2257,7 @@ fu_byte_array_set_size (GByteArray *array, guint lengt
 gboolean
 fu_common_kernel_locked_down (void)
 {
-#ifndef _WIN32
+#ifdef __linux__
 	gsize len = 0;
 	g_autofree gchar *dir = fu_common_get_path (FU_PATH_KIND_SYSFSDIR_SECURITY);
 	g_autofree gchar *fname = g_build_filename (dir, "lockdown", NULL);
