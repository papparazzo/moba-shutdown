#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])
AC_INIT([moba-shutdown], [0.1.0-0000], [pappi-@gmx.de])
AC_CONFIG_SRCDIR([src])
AC_CONFIG_HEADERS([config.h])

AM_INIT_AUTOMAKE([foreign])
AC_CONFIG_MACRO_DIR([m4])

# Checks for programs.
AC_PROG_CXX
AC_PROG_CC

# Checks for libraries.
AC_CHECK_LIB([wiringPi], [main])

# Checks for header files.
AC_CHECK_HEADERS([unistd.h])

# Checks for typedefs, structures, and compiler characteristics.
AC_CHECK_HEADER_STDBOOL

# Checks for library functions.

AC_CONFIG_FILES([Makefile])
AC_OUTPUT
