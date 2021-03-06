/*	$NetBSD$	*/

/*-
 * Copyright (c) 1999 The NetBSD Foundation, Inc.
 * All rights reserved.
 *
 * This code is derived from software contributed to The NetBSD Foundation
 * by Lonhyn T. Jasinskyj.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE NETBSD FOUNDATION, INC. AND CONTRIBUTORS
 * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED
 * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE FOUNDATION OR CONTRIBUTORS
 * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef CHRPICON_H
#define CHRPICON_H

#define MAX_LINE_LENGTH 8192

#define ICON_TAG     "<ICON"
#define BITMAP_TAG   "<BITMAP>"

#define PLAIN_PPM 1


typedef unsigned char chrpi_pixel;

typedef
struct chrpi_spec_s {
    int width;
    int height;
    int rbits;
    int gbits;
    int bbits;
    chrpi_pixel **pixels;
} CHRPI_spec_rec;

typedef CHRPI_spec_rec *CHRPI_spec;

int CHRPI_getheader(FILE *, CHRPI_spec);
int CHRPI_getbitmap(FILE *, CHRPI_spec);

void CHRPI_writeicon(FILE *fp, pixel **pixels, CHRPI_spec img);

void CHRPI_putbitmap(FILE *, pixel** pixels, CHRPI_spec img);
void CHRPI_putheader(FILE *, CHRPI_spec img);
void CHRPI_putfooter(FILE *, CHRPI_spec img);


#endif /* CHRPICON_H */
