/*	$NetBSD$	*/

#ifndef _MACHINE_ELF_MACHDEP_H_
#define _MACHINE_ELF_MACHDEP_H_

#include <m68k/elf_machdep.h>

/*
 * The 68010 can't execute binaries for 68020-and-up.
 */
#define	ELF32_EHDR_FLAGS_OK(eh)						\
	(((eh)->e_flags & EF_M68000) != 0)

#endif
