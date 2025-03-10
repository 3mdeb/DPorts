# Created by: Kubilay Kocak <koobs@FreeBSD.org>
# $FreeBSD$

PORTNAME=		spidermonkey185
PORTVERSION=		1.8.5
PORTREVISION=	5
CATEGORIES=		lang
MASTER_SITES=		MOZILLA/js
DISTNAME=		js185-1.0.0

MAINTAINER=		koobs@FreeBSD.org
COMMENT=		Standalone JavaScript (1.8.5) interpreter from Mozilla

BUILD_DEPENDS=		zip:archivers/zip \
			autoconf-2.13:devel/autoconf213
LIB_DEPENDS=		libnspr4.so:devel/nspr

USES=			gmake pathfix perl5 pkgconfig python:2.7,build
GNU_CONFIGURE=		yes
USE_LDCONFIG=		yes
USE_PERL5=		build

WRKSRC=			${WRKDIR}/js-${PORTVERSION}/js/src

BROKEN_aarch64=		Does not compile: error: cacheFlush support is missing on this platform
BROKEN_mips64=		Does not compile: error: const union jsval_layout has no member named word
BROKEN_riscv64=		Does not compile: jsiter.cpp:270:16: cannot initialize return object of type 'bool' with an rvalue of type 'nullptr_t'
BROKEN_sparc64=		Does not build: fails to link

NOT_FOR_ARCHS=		powerpc powerpc64
NOT_FOR_ARCHS_REASON=	PowerPC is not supported

CONFIGURE_ARGS=		--with-pthreads \
			--with-system-nspr

# This comes from bsd.gecko.mk, fixes linking issues on 9.0 and higher.
post-configure:
	${ECHO_CMD} "fenv.h" >> ${WRKSRC}/config/system-headers
	${ECHO_CMD} "pthread_np.h" >> ${WRKSRC}/config/system-headers

OPTIONS_DEFINE=		DEBUG GCZEAL JEMALLOC METHODJIT OPTIMIZE READLINE \
			THREADSAFE TRACEJIT UTF8 \

OPTIONS_DEFAULT=	METHODJIT OPTIMIZE READLINE THREADSAFE TRACEJIT

GCZEAL_DESC=		Enable Zealous garbage collecting
JEMALLOC_DESC=		Use jemalloc as memory allocator
METHODJIT_DESC=		Enable method JIT support
OPTIMIZE_DESC=		Enable compiler optimizations
READLINE_DESC=		Link js shell to system readline library
THREADSAFE_DESC=	Enable multiple thread support
TRACEJIT_DESC=		Enable tracing JIT support
UTF8_DESC=		Treat strings as UTF8 instead of ISO-8859-1

DEBUG_CONFIGURE_ENABLE=	debug
DEBUG_CONFIGURE_ON=	--enable-debug-sumbols
GCZEAL_CONFIGURE_ENABLE=	gczeal
JEMALLOC_CONFIGURE_ENABLE=	jemalloc
METHODJIT_CONFIGURE_ENABLE=	methodjit
OPTIMIZE_CONFIGURE_ENABLE=	optimize
READLINE_CONFIGURE_ENABLE=	readline
READLINE_USES=	readline
THREADSAFE_CONFIGURE_ENABLE=	threadsafe
TRACEJIT_CONFIGURE_ENABLE=	tracejit
UTF8_CFLAGS=			-DJS_C_STRINGS_ARE_UTF8

.include <bsd.port.options.mk>

.if ${ARCH} == x86_64
CONFIGURE_TARGET=	x86_64-portbld-freebsd${OSREL}
.endif

.if ${ARCH} == "x86_64"
PLIST_SUB+=	AMD64=""
.else
PLIST_SUB+=	AMD64="@comment "
.endif

.if ${ARCH} == "i386"
PLIST_SUB+=	I386=""
.else
PLIST_SUB+=	I386="@comment "
.endif

.if ${ARCH} == "arm"
PLIST_SUB+=	ARM=""
.else
PLIST_SUB+=	ARM="@comment "
.endif

.if ${ARCH} == "mips"
PLIST_SUB+=	MIPS=""
.else
PLIST_SUB+=	MIPS="@comment "
.endif

.if ${ARCH} == "powerpc" || ${ARCH} == "powerpc64"
PLIST_SUB+=	PPC=""
.else
PLIST_SUB+=	PPC="@comment "
.endif

.if ${ARCH} == "sparc64"
PLIST_SUB+=	SPARC=""
.else
PLIST_SUB+=	SPARC="@comment "
.endif

pre-configure:
	(cd ${WRKSRC} && ${LOCALBASE}/bin/autoconf-2.13)

do-test:
	@${ECHO_MSG} -n "===> Running jstests.py: "
	@cd ${WRKSRC} && ${SETENV} TZ=PST8PDT ${PYTHON_CMD} tests/jstests.py \
	--no-progress --worker-count=${MAKE_JOBS_NUMBER} ./js
.if ${PORT_OPTIONS:MMETHODJIT} || ${PORT_OPTIONS:MTRACEJIT}
	@${ECHO_MSG} -n "===> Running jit_test.py: "
	@cd ${WRKSRC} && ${SETENV} TZ=PST8PDT ${PYTHON_CMD} jit-test/jit_test.py \
	--no-progress --jitflags=,m,j,mj,mjp,am,amj,amjp,amd ./js
.endif

post-install:
	${LN} -sf libmozjs185.so.1.0.0 ${STAGEDIR}${PREFIX}/lib/libmozjs185.so
	${LN} -sf libmozjs185.so.1.0.0 ${STAGEDIR}${PREFIX}/lib/libmozjs185.so.1
	${LN} -sf libmozjs185.so.1.0.0 ${STAGEDIR}${PREFIX}/lib/libmozjs185.so.1.0
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libmozjs185.so.1.0.0

.include <bsd.port.mk>
