/*	$NetBSD$	*/

/*
 * Fake libkern.h for the few files we borrow from sys/lib/libsa
 */
#ifndef _LIB_LIBKERN_LIBKERN_H_
#define _LIB_LIBKERN_LIBKERN_H_

#include <sys/types.h>

size_t strlen(const char *string);

#endif /* !_LIB_LIBKERN_LIBKERN_H_ */
