--- src/fu-engine.c.orig	2021-02-23 14:54:50 UTC
+++ src/fu-engine.c
@@ -6299,7 +6299,7 @@ fu_engine_load (FuEngine *self, FuEngineLoadFlags flag
 	guint backend_cnt = 0;
 	g_autoptr(GPtrArray) checksums_approved = NULL;
 	g_autoptr(GPtrArray) checksums_blocked = NULL;
-#ifndef _WIN32
+#ifdef __linux__
 	g_autoptr(GError) error_local = NULL;
 #endif
 
@@ -6311,7 +6311,7 @@ fu_engine_load (FuEngine *self, FuEngineLoadFlags flag
 		return TRUE;
 
 /* TODO: Read registry key [HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Cryptography] "MachineGuid" */
-#ifndef _WIN32
+#ifdef __linux__
 	/* cache machine ID so we can use it from a sandboxed app */
 	self->host_machine_id = fwupd_build_machine_id ("fwupd", &error_local);
 	if (self->host_machine_id == NULL)
