#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.65])
AC_INIT([GefMoteur], [0.B.3], [fege.guillaume@gmail.com])
AC_LANG(C++)
#AC_CONFIG_SRCDIR([include/GefMoteur/GefApp.hpp])
AC_CONFIG_MACRO_DIR([m4])
AC_CONFIG_HEADERS([config.h])
#AC_CONFIG_FILES([include/GefMoteur/GefAppSfml.hpp:include/GefMoteur/GefAppSfml.hpp.in])
AM_INIT_AUTOMAKE

# Checks for programs.
AC_PROG_CXX
AC_PROG_CC
AC_PROG_LIBTOOL

# Checks for libraries.
# FIXME: Replace `main' with a function in `-lGefMoteur':
#AC_CHECK_LIB([GefMoteur], [main])
# FIXME: Replace `main' with a function in `-lX11':
#AC_CHECK_LIB([X11], [main])
# FIXME: Replace `main' with a function in `-lXrandr':
#AC_CHECK_LIB([Xrandr], [main])
# FIXME: Replace `main' with a function in `-lfreetype':
#AC_CHECK_LIB([freetype], [main])
# FIXME: Replace `main' with a function in `-lglut':
#AC_CHECK_LIB([glut], [main])
# FIXME: Replace `main' with a function in `-lopenal':
#AC_CHECK_LIB([openal], [main])
# FIXME: Replace `main' with a function in `-lsndfile':
#AC_CHECK_LIB([sndfile], [main])

# Checks for header files.
#check SFML
HAVE_SFML=1
AC_CHECK_LIB([sfml-system], [main])
AC_CHECK_HEADERS([SFML/System.hpp], ,[HAVE_SFML=0])

AC_CHECK_LIB([sfml-window], [main])
AC_CHECK_HEADERS([SFML/Window.hpp], ,[HAVE_SFML=0])

AC_CHECK_LIB([sfml-graphics], [main])
AC_CHECK_HEADERS([SFML/Graphics.hpp], ,[HAVE_SFML=0])

AC_CHECK_LIB([sfml-network], [main])
AC_CHECK_HEADERS([SFML/Network.hpp])

AC_CHECK_LIB([sfml-audio], [main])
AC_CHECK_HEADERS([SFML/Audio.hpp])

AM_CONDITIONAL(HAVE_SFML,HAVE_SFML)

# Checks for typedefs, structures, and compiler characteristics.
AC_HEADER_STDBOOL
AC_C_INLINE
AC_TYPE_SIZE_T

# Checks for library functions.
AC_FUNC_MALLOC

AC_CONFIG_FILES([Makefile
	src/Makefile
	include/GefMoteur/Makefile
	test/testsfml/Makefile])

#AC_CONFIG_FILES([Makefile
#                 src/Makefile
#                 test/testsfml/Makefile
#                 test/testsystem/Makefile])

AC_OUTPUT
