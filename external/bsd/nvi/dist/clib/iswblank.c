#include "config.h"

#if defined(LIBC_SCCS) && !defined(lint)
static const char sccsid[] = "Id: iswblank.c,v 1.1 2001/10/11 19:22:29 skimo Exp ";
#endif /* LIBC_SCCS and not lint */
#else
__RCSID("$NetBSD$");
#endif

#include <wchar.h>
#include <wctype.h>

int
iswblank (wint_t wc)
{
    return iswctype(wc, wctype("blank"));
}
