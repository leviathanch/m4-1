/* GNU m4 -- A simple macro processor
   Copyright 2000 Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA
   02111-1307  USA
*/

/**
 * @configure_generated@
 *
 * This file is installed, so cannot rely on the contents of config.h.
 * It works best if included _after_ system headers.
 **/

#ifndef M4_SYSTEM_H
#define M4_SYSTEM_H 1

#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
@INCLUDE_ERROR_H@
@INCLUDE_OBSTACK_H@
@INCLUDE_STDBOOL_H@
#include <m4/xalloc.h>
#include <m4/xstrndup.h>

/* This is okay in an installed file, because it will not change the
   behaviour of the including program whether ENABLE_NLS is defined
   or not.  */
#ifndef _
#  ifdef ENABLE_NLS
#    include <libintl.h>
#    define _(Text) gettext ((Text))
#  else
#    define _(Text) (Text)
#  endif
#endif


/* All header files should be inside BEGIN_C_DECLS ... END_C_DECLS, so
   that the library can be linked into a C++ program.  The multi-include
   guard macros must be outside, as should any #includes -- for simplicity
   everything else should go inside.  */

#ifndef BEGIN_C_DECLS
#  ifdef __cplusplus
#    define BEGIN_C_DECLS	extern "C" {
#    define END_C_DECLS		}
#  else /* !__cplusplus */
#    define BEGIN_C_DECLS	/* empty */
#    define END_C_DECLS		/* empty */
#  endif /* __cplusplus */
#endif /* !BEGIN_C_DECLS */

BEGIN_C_DECLS



/* Canonicalise Windows and Cygwin recognition macros.  */
#if defined __CYGWIN32__ && !defined __CYGWIN__
#  define __CYGWIN__ __CYGWIN32__
#endif
#if defined _WIN32 && !defined WIN32
#  define WIN32 _WIN32
#endif

#if defined WIN32 && !defined __CYGWIN__
/* M4_DIRSEP_CHAR is accepted *in addition* to '/' as a directory
   separator when it is set. */
#  define M4_DIRSEP_CHAR	'\\'
#  define M4_PATHSEP_CHAR	';'
#endif
#ifndef M4_PATHSEP_CHAR
#  define M4_PATHSEP_CHAR	':'
#endif



/* M4_STMT_START/END are used to create macros which expand to a
   a single compound statement in a portable way, but crucially in
   a way sympathetic to the compiler to maximise optimisation.  */
#undef M4_STMT_START
#undef M4_STMT_END
#if defined (__GNUC__) && !defined (__STRICT_ANSI__) && !defined (__cplusplus)
#  define M4_STMT_START        (void)(
#  define M4_STMT_END          )
#else
#  if (defined (sun) || defined (__sun__))
#    define M4_STMT_START      if (1)
#    define M4_STMT_END        else (void)0
#  else
#    define M4_STMT_START      do
#    define M4_STMT_END        while (0)
#  endif
#endif



/* Take advantage of GNU C compiler source level optimisation hints,
   using portable macros.  */
#if __GNUC__ > 2 || (__GNUC__ == 2 && __GNUC_MINOR__ > 4)
#  define M4_GNUC_ATTRIBUTE(args)	__attribute__(args)
#else
#  define M4_GNUC_ATTRIBUTE(args)
#endif  /* __GNUC__ */

#define M4_GNUC_PRINTF(fmt, arg) M4_GNUC_ATTRIBUTE((format (printf, fmt, arg)))
#define M4_GNUC_SCANF(fmt, arg)	M4_GNUC_ATTRIBUTE((format (scanf, fmt, arg)))
#define M4_GNUC_FORMAT(arg_idx)	M4_GNUC_ATTRIBUTE((format_arg (arg_idx)))
#define M4_GNUC_NORETURN	M4_GNUC_ATTRIBUTE((noreturn))
#define M4_GNUC_CONST		M4_GNUC_ATTRIBUTE((const))
#define M4_GNUC_UNUSED		M4_GNUC_ATTRIBUTE((unused))



#if !defined __PRETTY_FUNCTION__
#  define __PRETTY_FUNCTION__	"<unknown>"
#endif


/* Preprocessor token manipulation.  */

/* The extra indirection to the _STR and _CONC macros is required so that
   if the arguments to STR() (or CONC()) are themselves macros, they will
   be expanded before being quoted.   */
#ifndef STR
#  define _STR(arg)	#arg
#  define STR(arg)	_STR(arg)
#endif

#ifndef CONC
#  define _CONC(a, b)	a##b
#  define CONC(a, b)	_CONC(a, b)
#endif



/* Make sure these are defined.  */
#ifndef EXIT_FAILURE
#  define EXIT_SUCCESS	0
#  define EXIT_FAILURE	1
#endif


#define DELETE(Expr)	((Expr) = (xfree (Expr), (void *) 0))

extern char *xstrzdup (const char *string, size_t len);

END_C_DECLS

#endif /* !M4_SYSTEM_H */