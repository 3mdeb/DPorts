# Created by: Norbert Kamiński <norbert.kaminski@3mdeb.com>
# $FreeBSD$

PORTNAME=	fwupd
DISTVERSION=	1.5.7
CATEGORIES=	sysutils
COMMENT=	This project aims to make updating firmware automatic, safe and reliable.
LICENSE=	LGPL21

BUILD_DEPENDS=	meson:devel/meson \
		pkgconf:devel/pkgconf \
		vala:lang/vala \
		${RUN_DEPENDS}

LIB_DEPENDS=	libglib-2.0.so:devel/glib20 \
		libjson-glib-1.0.so:devel/json-glib \
		libgpgme.so:security/gpgme \
		libgnutls.so:security/gnutls \
		libsqlite3.so:databases/sqlite3 \
		libcurl.so:ftp/curl \
		libgcab-1.0.so:archivers/gcab \
		libarchive.so.13:archivers/libarchive \
		libgpg-error.so:security/libgpg-error

RUN_DEPENDS=	gobject-introspection>=1.36:devel/gobject-introspection \
		gtkdocize:textproc/gtk-doc

SHEBANG_REGEX=	'.*\.py$$'

MESON_ARGS+=	-Dplugin_uefi_capsule='false' \
		-Dplugin_dell='false' \
		-Dplugin_redfish='false' \
		-Dplugin_nvme='false' \
		-Dplugin_amt='false' \
		-Dplugin_emmc='false' \
		-Dplugin_altos='false' \
		-Dplugin_thunderbolt='false' \
		-Dplugin_synaptics_mst='false' \
		-Dpolkit='false' \
		-Dman='false' \
		-Dgudev='false' \
		-Dtests='false'\
		-Dplugin_tpm='false' \
		-Dsystemd='false' \
		-Dlibjcat:man='false' \
		-Dplugin_synaptics_rmi='false' \
		-Dgcab:docs='false'

USES=		gnome meson pkgconfig python:3.7+ shebangfix
USE_GNOME=	glib20 introspection:build
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	fwupd
GH_PROJECT=	fwupd

MAINTAINER=	norbert.kaminski@3mdeb.com

.include <bsd.port.mk>
