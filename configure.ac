#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.65])
AC_INIT([GefMoteur], [0.B.3], [fege.guillaume@gmail.com])
#AC_CONFIG_SRCDIR([include/GefMoteur/GefApp.hpp])
AC_CONFIG_MACRO_DIR([m4])
AC_CONFIG_HEADERS([config.h])
AC_LANG(C++)
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
AC_CHECK_LIB([sfml-system], [main], ,
AC_MSG_ERROR([ *** Unable to find SFML library (http://www.sfml-dev.org/)]))
AC_CHECK_HEADERS([SFML/System.hpp], ,
AC_MSG_ERROR([ *** SFML library found but cannot find headers (http://www.sfml-dev.org/)]))

AC_CHECK_LIB([sfml-window], [main], ,
AC_MSG_ERROR([ *** Unable to find SFML Window library (http://www.sfml-dev.org/)]))
AC_CHECK_HEADERS([SFML/Window.hpp], ,
AC_MSG_ERROR([ *** SFML Window library found but cannot find headers (http://www.sfml-dev.org/)]))

AC_CHECK_LIB([sfml-graphics], [main], ,
AC_MSG_ERROR([ *** Unable to find SFML Graphics library (http://www.sfml-dev.org/)]))
AC_CHECK_HEADERS([SFML/Graphics.hpp], ,
AC_MSG_ERROR([ *** SFML Graphics library found but cannot find headers (http://www.sfml-dev.org/)]))

AC_CHECK_LIB([sfml-network], [main], ,
AC_MSG_ERROR([ *** Unable to find SFML Network library (http://www.sfml-dev.org/)]))
AC_CHECK_HEADERS([SFML/Network.hpp], ,
AC_MSG_ERROR([ *** SFML Network library found but cannot find headers (http://www.sfml-dev.org/)]))

AC_CHECK_LIB([sfml-audio], [main], ,
AC_MSG_ERROR([ *** Unable to find SFML Audio library (http://www.sfml-dev.org/)]))
AC_CHECK_HEADERS([SFML/Audio.hpp], ,
AC_MSG_ERROR([ *** SFML Audio library found but cannot find headers (http://www.sfml-dev.org/)]))


# Checks for typedefs, structures, and compiler characteristics.
AC_HEADER_STDBOOL
AC_C_INLINE
AC_TYPE_SIZE_T

# Checks for library functions.
AC_FUNC_MALLOC

AC_CONFIG_FILES([Makefile
	src/Makefile
	test/testsfml/Makefile])

#AC_CONFIG_FILES([Makefile
#                 src/Makefile
#                 test/testsfml/Makefile
#                 test/testsystem/Makefile])

AC_OUTPUT
