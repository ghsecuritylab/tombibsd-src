#	$NetBSD$

LIB=	clangFormat

.include <bsd.init.mk>

.PATH: ${CLANG_SRCDIR}/lib/Format

SRCS+=	BreakableToken.cpp \
	ContinuationIndenter.cpp \
	Format.cpp \
	FormatToken.cpp \
	TokenAnnotator.cpp \
	UnwrappedLineFormatter.cpp \
	UnwrappedLineParser.cpp \
	WhitespaceManager.cpp

.if defined(HOSTLIB)
.include <bsd.hostlib.mk>
.else
.include <bsd.lib.mk>
.endif
