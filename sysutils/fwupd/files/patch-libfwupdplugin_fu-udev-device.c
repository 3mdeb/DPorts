--- libfwupdplugin/fu-udev-device.c.orig	2021-02-23 14:54:50 UTC
+++ libfwupdplugin/fu-udev-device.c
@@ -1588,7 +1588,7 @@ gboolean
 fu_udev_device_write_sysfs (FuUdevDevice *self, const gchar *attribute,
 			    const gchar *val, GError **error)
 {
-#ifndef _WIN32
+#ifdef __linux__
 	ssize_t n;
 	int r;
 	int fd;
