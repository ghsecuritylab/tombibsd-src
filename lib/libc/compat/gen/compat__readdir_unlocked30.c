/*	$NetBSD$	*/

#define __LIBC12_SOURCE__
#include "namespace.h"
#include <dirent.h>
#include <compat/include/dirent.h>

#ifdef __warn_references
__warn_references(___readdir_unlocked30,
    "warning: reference to compatibility _readdir_unlocked(); include <dirent.h> for correct reference")
#endif

/**     
 * Compat version of _readdir_unlocked which always skips directories
 */
struct dirent *
___readdir_unlocked30(DIR *dirp)
{
	return ___readdir_unlocked50(dirp, 1);
}
