export USE_EXTLIBS= YES

export CC=g++
export CFLAGS=-Wall
export INST_PATH=$(PWD)/lib
export INC_PATH=-I $(PWD)/include -I $(PWD)/SFML/include
export LIB_PATH=-L $(INST_PATH) -L $(PWD)/lib/SFML

ifeq ($(USE_EXTLIBS),YES)
	export LIB_PATH=-L $(INST_PATH) -L $(PWD)/lib/SFML -L $(PWD)/extlibs
else
	export LIB_PATH=-L $(INST_PATH) -L $(PWD)/lib/SFML
endif

lib/libGefMoteur.a:
	git submodule init
	git submodule update
	@(cd src && $(MAKE))

install: lib/libGefMoteur.a
	@(cp lib/*.a /usr/lib/)
	@(cp -R include/* /usr/include/)

uninstall:
	@(rm -f /usr/lib/libGefMoteur.a)
	@(rm -f -R /usr/include/GefMoteur)

_SFML:
	@(git submodule init)
	@(git submodule update)
	-@(patch -p0 -N -i ./SFML.patch)
	@(cd SFML && $(MAKE))

testsfml:lib/libGefMoteur.a _SFML
	@(cd test/testsfml && $(MAKE))

runtestsfml: testsfml
	@(cd test/testsfml && ./test)

testsystem:lib/libGefMoteur.a _SFML
	@(cd test/testsystem && $(MAKE))

runtestsystem:testsystem
	@(cd test/testsystem && ./test)

clean:
	@(cd src && $(MAKE) clean)
	@(cd test/testsfml && $(MAKE) clean)
	@(cd test/testsystem && $(MAKE) clean)
	@(cd SFML && $(MAKE) clean)

mrproper: clean
	@(cd lib && $(MAKE) mrproper)
	@(cd test/testsfml && $(MAKE) mrproper)
	@(cd test/testsystem && $(MAKE) mrproper)
	@(cd SFML && $(MAKE) mrproper)
