
all:GefAppSfml.hpp

GefAppSfml.hpp: GefAppSfml.hpp.in
	rm -f $@-t $@
	{ echo '/* DO NOT EDIT! GENERATED AUTOMATICALLY! */' && \
	  sed -e 's|@''HAVE_SFML_GRAPHICS_HPP''@|$(HAVE_SFML_GRAPHICS_HPP)|g' \
	      < GefAppSfml.hpp.in; \
	} > $@-t
	mv $@-t $@
MOSTLYCLEANDIRS+=GefAppSfml.hpp GefAppSfml.hpp-t

clean:
	@for dir in '' $(MOSTLYCLEANDIRS); do \
	  if test -n "$$dir" && test -d $$dir; then \
	    echo "rmdir $$dir"; rmdir $$dir; \
	  fi; \
	done; \
