#	$NetBSD$

.include <bsd.own.mk>

CFDIR=		commands
CFFILES=	@List ListContexts ListGenericCommands
CFSED=		-e 's,ENVPREFIX,RSTART,g'

CONFIGSYMLINKS=	x11r6 ${FILESDIR}/x \
		x11r6 ${FILESDIR}/x11 \

SUBDIR=		x11r6

.include "../Makefile.rstart"

.include <bsd.x11.mk>
.include <bsd.prog.mk>
.include <bsd.subdir.mk>
