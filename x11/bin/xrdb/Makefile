#	$NetBSD$

.include <bsd.own.mk>

PROG=	xrdb

CPPFLAGS+=-DCPP="\"cpp -traditional\"" -DHAS_MKSTEMP	# XXX

LDADD+=	-lXmuu -lXt -lSM -lICE -lXext -lX11
DPADD+=	${LIBXMUU} ${LIBXT} ${LIBSM} ${LIBICE} ${LIBXEXT} ${LIBX11}

.PATH:	${X11SRCDIR.xc}/programs/${PROG}

.include <bsd.x11.mk>
.include <bsd.prog.mk>
