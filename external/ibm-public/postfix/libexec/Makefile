#	$NetBSD$

.include <bsd.own.mk>

SUBDIR=	anvil bounce cleanup discard dnsblog error flush local master oqmgr \
	pickup pipe postfix-script proxymap qmgr scache sendmail \
	showq smtp smtpd spawn trivial-rewrite verify virtual

.if ${MKCRYPTO} != "no"
SUBDIR+=	postscreen tlsmgr tlsproxy
.endif

# Not built: fsstone (unneeded), smtpstone (unneeded), qmqpd (unneeded)

.include <bsd.subdir.mk>
