#	$NetBSD$

LIB=	lldbUtility

.include <bsd.init.mk>

.PATH: ${LLDB_SRCDIR}/source/Utility

SRCS+=	ARM_DWARF_Registers.cpp \
	ARM64_DWARF_Registers.cpp \
	KQueue.cpp \
	PseudoTerminal.cpp \
	Range.cpp \
	RegisterNumber.cpp \
	SharingPtr.cpp \
	StringExtractor.cpp \
	StringExtractorGDBRemote.cpp \
	StringLexer.cpp \
	TimeSpecTimeout.cpp \
	UriParser.cpp

.if defined(HOSTLIB)
.include <bsd.hostlib.mk>
.else
.include <bsd.lib.mk>
.endif
