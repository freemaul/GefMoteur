lib_LIBRARIES = libGefMoteur.a

libGefMoteur_a_SOURCES = GefMoteurH.cpp \
			GefApp.cpp \
			GefDebug.cpp \
			GefRender.cpp \
			GefMoteur.cpp

if HAVE_SFML
libGefMoteur_a_SOURCES +=GefRenderSfml.cpp \
			GefSystemSfml.cpp \
			GefAppSfml.cpp
endif

AM_CPPFLAGS=-I../include
