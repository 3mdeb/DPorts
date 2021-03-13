--- src/fu-self-test.c.orig	2021-02-23 14:54:50 UTC
+++ src/fu-self-test.c
@@ -583,7 +583,7 @@ fu_engine_requirements_device_func (gconstpointer user
 		"    <firmware compare=\"ge\" version=\"1.2.3\"/>"
 		"    <firmware compare=\"eq\" version=\"4.5.6\">bootloader</firmware>"
 		"    <firmware compare=\"regex\" version=\"USB:0xFFFF|DMI:Lenovo\">vendor-id</firmware>"
-#ifndef _WIN32
+#ifdef __linux__
 		"    <id compare=\"ge\" version=\"4.0.0\">org.kernel</id>"
 #endif
 		"  </requires>"
