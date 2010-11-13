lib_LIBRARIES = libGefMoteur.a

libGefMoteur_a_SOURCES = GefMoteurH.cpp \
			GefApp.cpp \
			GefDebug.cpp \
			GefRender.cpp \
			GefMoteur.cpp \
			GefMoteurH.cpp

if HAVE_SFML
libGefMoteur_a_SOURCES +=GefRenderSfml.cpp \
			GefSystemSfml.cpp \
			GefAppSfml.cpp
endif


libGefMoteur_a_includedir=$(includedir)/GefMoteur/

libGefMoteur_a_include_HEADERS = ../include/GefMoteur/GefApp.hpp \
				../include/GefMoteur/GefDebug.hpp \
				../include/GefMoteur/GefMoteurH.hpp \
				../include/GefMoteur/GefMoteur.hpp \
				../include/GefMoteur/GefRender.hpp \
				../include/GefMoteur/GefSystem.hpp

if HAVE_SFML
libGefMoteur_a_include_HEADERS += ../include/GefMoteur/GefAppSfml.hpp \
				../include/GefMoteur/GefRenderSfml.hpp \
				../include/GefMoteur/GefSystemSfml.hpp 
endif

AM_CPPFLAGS=-I../include
