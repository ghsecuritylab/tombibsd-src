#	$NetBSD$

PROG	= loadbsd.ttp

OBJS	= loadbsd.o
HEADERS	= ../libtos/kparamb.h ../libtos/tosdefs.h

#
# Define COMPRESSED_READ when you want to load gzipped kernels
#
DEFS	= -DCOMPRESSED_READ
LDADD	= -lz

include ../Makefile.inc

${PROG}: ${OBJS} ${LDADD}
	${CC} ${LDFLAGS} -o $@ ${OBJS} ${LDADD} ${LIBS}
