# $NetBSD$

CPPFLAGS+=	-I${ARCHDIR}
CPPFLAGS+=	-DHAVE_INITFINI_ARRAY
CPPFLAGS+=	-DELF_NOTE_MARCH_DESC=\"${CSU_MACHINE_ARCH}\"
