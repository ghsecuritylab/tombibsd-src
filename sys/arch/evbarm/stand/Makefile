#	$NetBSD$

.include <bsd.endian.mk>

SUBDIR+= gzboot
SUBDIR+= boot2440
.if ${MACHINE_CPU} == "arm" && ${TARGET_ENDIANNESS} == "1234"
# According to the i.MX23 Reference Manual section 3.1, Page 3-3:
# "The i.MX23 always operates in litle-endian mode."
SUBDIR+= bootimx23
.endif

.include <bsd.subdir.mk>
