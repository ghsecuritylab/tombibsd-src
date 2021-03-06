/* $NetBSD$ */

#ifndef _EWS4800MIPS_LOCORE_H_
#define _EWS4800MIPS_LOCORE_H_

#include <mips/locore.h>

#ifdef _KERNEL
#ifndef _LOCORE
void ews4800mips_nmi_vec(void);

void rom_putc(int, int, int);
int  rom_getc(void);
void rom_ipl(void);
void rom_poweroff(void);
#endif /* !_LOCORE */
#endif /* _KERNEL */

#endif /* !_EWS4800MIPS_LOCORE_H_ */

