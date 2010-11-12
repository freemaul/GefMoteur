CONFIG_CLEAN_FILES=

all:GefAppSfml.hpp

GefAppSfml.hpp: GefAppSfml.hpp.in
	rm -f $@-t $@
	{ echo '/* DO NOT EDIT! GENERATED AUTOMATICALLY! */' && \
	  sed -e 's|@''HAVE_SFML_GRAPHICS_HPP''@|$(HAVE_SFML_GRAPHICS_HPP)|g' \
	      < GefAppSfml.hpp.in; \
	} > $@-t
	mv $@-t $@
CONFIG_CLEAN_FILES+=GefAppSfml.hpp GefAppSfml.hpp-t

GefRenderSfml.hpp: GefRenderSfml.hpp.in
	rm -f $@-t $@
	{ echo '/* DO NOT EDIT! GENERATED AUTOMATICALLY! */' && \
	  sed -e 's|@''HAVE_SFML_GRAPHICS_HPP''@|$(HAVE_SFML_GRAPHICS_HPP)|g' \
	      < GefRenderSfml.hpp.in; \
	} > $@-t
	mv $@-t $@
CONFIG_CLEAN_FILES+=GefRenderSfml.hpp GefRenderSfml.hpp-t

GefSystemSfml.hpp: GefSystemSfml.hpp.in
	rm -f $@-t $@
	{ echo '/* DO NOT EDIT! GENERATED AUTOMATICALLY! */' && \
	  sed -e 's|@''HAVE_SFML_GRAPHICS_HPP''@|$(HAVE_SFML_GRAPHICS_HPP)|g' \
	  sed -e 's|@''HAVE_SFML_SYSTEM_HPP''@|$(HAVE_SFML_SYSTEM_HPP)|g' \
	      < GefSystemSfml.hpp.in; \
	} > $@-t
	mv $@-t $@
CONFIG_CLEAN_FILES+=GefSystemSfml.hpp GefRenderSfml.hpp-t

