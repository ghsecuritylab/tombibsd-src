#	$NetBSD$
#

.PATH:	${.CURDIR}/../../../../dev/dm

LIB=	rumpdev_dm

SRCS=   device-mapper.c dm_dev.c dm_ioctl.c dm_pdev.c dm_table.c dm_target.c \
        dm_target_linear.c dm_target_stripe.c

SRCS+=	dm_component.c

CPPFLAGS+=	-I${RUMPTOP}/librump/rumpvfs

.include <bsd.lib.mk>
.include <bsd.klinks.mk>
