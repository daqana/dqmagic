#                                               -*- Autoconf -*-
# Copyright (C) 2017 Ralf Stubner (R Institute GmbH)
#
# This file is part of dqmagic.
#
# dqmagic is free software: you can redistribute it and/or modify it
# under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 2 of the License, or
# (at your option) any later version.
#
# dqmagic is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with dqmagic.  If not, see <http://www.gnu.org/licenses/>.
#
# Process this file with autoconf to produce a configure script.
AC_PREREQ([2.69])
AC_INIT([dqmagic], [0.0.0])

: ${R_HOME=`R RHOME`}
if test -z "${R_HOME}" ; then
    echo "could not determin R_HOME"
    exit 1
fi

# use deprecated CXX1X* to support R versions 3.1.0 to 3.3.3
CXX=`"${R_HOME}/bin/R" CMD config CXX`
CXXFLAGS=`"${R_HOME}/bin/R" CMD config CXXFLAGS`
AC_LANG(C++)
AC_REQUIRE_CPP
AC_PROG_CXX

# set path to root of arrayfire
AC_ARG_WITH([magic],
            AC_HELP_STRING([--with-magic=PREFIX],
                           [path to where libmagic is installed]),
            [],
            [])

AC_SUBST([MAGIC_INCLUDE], "")
AC_SUBST([MAGIC_LIBS], "-lmagic")

AS_IF([test -e "${with_magic}"],
            [
             MAGIC_INCLUDE="-I${with_magic}/include ${MAGIC_INCLUDE}"
             MAGIC_LIBS="-L${with_magic}/lib ${MAGIC_LIBS}"
            ])

CXX_FLAGS="${CXX_FLAGS} ${MAGIC_INCLUDE}"
LDFLAGS="${LDFLAGS} ${MAGIC_LIBS}"

# check for arrayfire header
AC_CHECK_HEADER([magic.h],
    [],
    [AC_MSG_ERROR([unable to find magic.h])])

AC_MSG_CHECKING([for libaf.so])
        AC_COMPILE_IFELSE([AC_LANG_PROGRAM([[
#include <magic.h>
struct magic_set *magic = magic_open(MAGIC_NONE);]])],
                [AC_MSG_RESULT(yes)],
                [
                 AC_MSG_RESULT(no)
                 AC_MSG_ERROR([unable to find libmagic.so])
                ])


AC_CONFIG_FILES([src/Makevars])
AC_OUTPUT
