#	$NetBSD$

PROG=		ipnat
SRCS=		ipnat.c ipnat_y.c ipnat_l.c
MAN=		ipnat.8 ipnat.4 ipnat.5
MLINKS=		ipnat.5 ipnat.conf.5
CPPFLAGS+=	-I.

DPSRCS+=	ipnat_l.h ipnat_y.h

CLEANFILES+=	ipnat_y.c ipnat_y.h
CLEANFILES+=	ipnat_l.c ipnat_l.h

ipnat_y.c: ipnat_y.y
	${_MKTARGET_CREATE}
	${YACC} -d ${.ALLSRC}
	${TOOL_SED} -e 's/yy/ipnat_yy/g' \
	    -e 's/y.tab.c/ipnat_y.c/' \
	    -e s/\"ipnat_y.y\"/\"..\\/tools\\/ipnat_y.y\"/ \
	    y.tab.c > ${.TARGET}
	${TOOL_SED} -e 's/yy/ipnat_yy/g' \
	    -e 's/y.tab.h/ipnat_y.h/' \
	    y.tab.h > ${.TARGET:.c=.h}

ipnat_y.h: ipnat_y.c

ipnat_l.c: lexer.c
	${_MKTARGET_CREATE}
	${TOOL_SED} -e 's/yy/ipnat_yy/g' \
	    -e 's/y.tab.h/ipnat_y.h/' \
	    -e 's/lexer.h/ipnat_l.h/' \
	    ${.ALLSRC} > ${.TARGET}

ipnat_l.h: lexer.h
	${_MKTARGET_CREATE}
	${TOOL_SED} -e 's/yy/ipnat_yy/g' \
	    ${.ALLSRC} > ${.TARGET}

.include <bsd.prog.mk>
