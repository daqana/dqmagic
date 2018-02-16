/* Copyright (C) 1995-2015 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */

#ifndef _GNURX_INTERNAL_H
#define _GNURX_INTERNAL_H 1

#define _GNU_SOURCE
#define IS_IN(x) 1

/* GNURX: from glibc-2.22/misc/sys/param.h */
/* Macros for min/max.  */
#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))

/* GNURX: from glibc-2.22/include/features.h */
/* Convenience macros to test the versions of glibc and gcc.
   Use them like this:
   #if __GNUC_PREREQ (2,8)
   ... code requiring gcc 2.8 or later ...
   #endif
   Note - they won't work for gcc1 or glibc1, since the _MINOR macros
   were not defined then.  */
#if defined __GNUC__ && defined __GNUC_MINOR__
# define __GNUC_PREREQ(maj, min) \
	((__GNUC__ << 16) + __GNUC_MINOR__ >= ((maj) << 16) + (min))
#else
# define __GNUC_PREREQ(maj, min) 0
#endif

/* GNURX: from glibc-2.22/misc/sys/cdefs.h */
/* If fortification mode, we warn about unused results of certain
   function calls which can lead to problems.  */
#if __GNUC_PREREQ (3,4)
# define __attribute_warn_unused_result__ \
   __attribute__ ((__warn_unused_result__))
# if __USE_FORTIFY_LEVEL > 0
#  define __wur __attribute_warn_unused_result__
# endif
#else
# define __attribute_warn_unused_result__ /* empty */
#endif
#ifndef __wur
# define __wur /* Ignore */
#endif

#endif /* gnurx_internal.h */
