# $FreeBSD$

PORTNAME=	pyside2
DISTVERSION=	5.15.2
CATEGORIES=	devel
MASTER_SITES=	QT/official_releases/QtForPython/shiboken2/PySide2-${DISTVERSION}-src
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	pyside-setup-opensource-src-${DISTVERSION}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Python Qt bindings for Qt 5.12+

LICENSE=	LGPL3

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools_scm>0:devel/py-setuptools_scm@${PY_FLAVOR} \
		git>0:devel/git
LIB_DEPENDS=	libshiboken2.cpython-${PYTHON_SUFFIX}${PYTHON_ABIVER}.so:devel/shiboken2@${PY_FLAVOR}

USES=		cmake gl python:3.5+ qt:5 tar:xz
USE_GL=		gl
USE_LDCONFIG=	yes
USE_PYTHON=	flavors
USE_QT=		3d buildtools_build charts concurrent core datavis3d declarative \
		designer gamepad gui help location multimedia network opengl \
		printsupport qmake_build quickcontrols2 remoteobjects serialport \
		script scripttools scxml sensors speech sql svg testlib uitools \
		webchannel websockets widgets x11extras xml xmlpatterns

CMAKE_ARGS+=	"-DUSE_PYTHON_VERSION=${PYTHON_VER}" \
		"-DPYTHON_EXECUTABLE=${PYTHON_CMD}"

.include <bsd.port.pre.mk>

PLIST_SUB+=	PYVERSTR=.cpython-${PYTHON_SUFFIX}${PYTHON_ABIVER}
PLIST_SUB+=	DISTVERSION=${DISTVERSION}

WRKSRC=		${WRKDIR}/pyside-setup-opensource-src-${DISTVERSION:C/^([0-9].[0-9]+.[0-9])(.[0-9])?/\1/}/sources/pyside2

.if ${ARCH} == x86_64 || ${ARCH} == i386
PLIST_SUB+=	WEBENGINE=""
USE_QT+=	webengine
.else
PLIST_SUB+=	WEBENGINE="@comment "
.endif

# AVOID a build_fs_violation with poudriere
post-build:
	${RM} -r ${PYTHON_SITELIBDIR}/shiboken2/files.dir/shibokensupport/__pycache__
	${RM} -r ${PYTHON_SITELIBDIR}/shiboken2/files.dir/shibokensupport/signature/__pycache__
	${RM} -r ${PYTHON_SITELIBDIR}/shiboken2/files.dir/shibokensupport/signature/lib/__pycache__
post-stage:
	${RM} -r ${PYTHON_SITELIBDIR}/shiboken2/files.dir/shibokensupport/__pycache__
	${RM} -r ${PYTHON_SITELIBDIR}/shiboken2/files.dir/shibokensupport/signature/__pycache__
	${RM} -r ${PYTHON_SITELIBDIR}/shiboken2/files.dir/shibokensupport/signature/lib/__pycache__

.include <bsd.port.post.mk>
