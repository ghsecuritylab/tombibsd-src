#	$NetBSD$

SRCS+=		rtld_start.S mdreloc.c

# XXX Should not be in CPPFLAGS!
CPPFLAGS+=	-fpic

CPPFLAGS+=	-DELFSIZE=64

LDFLAGS+=	-Wl,-e,_rtld_start
