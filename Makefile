export CC=g++
export CFLAGS=-W
export INST_PATH=$(PWD)/lib
export INC_PATH=-I $(PWD)/include

all:
	@(cd src && $(MAKE))

install: all
	@(cp lib/*.a /usr/lib/)
	@(cp -R include/* /usr/include/)

uninstall:
	@(rm -f /usr/lib/libGefMoteur.a)
	@(rm -f -R /usr/include/GefMoteur)

testsfml:all
	@(cd test/testsfml && $(MAKE))

runtestsfml: testsfml
	@(cd test/testsfml && ./test)

testsystem:all
	@(cd test/testsystem && $(MAKE))

runtestsystem:testsystem
	@(cd test/testsystem && ./test)

clean:
	@(cd src && $(MAKE) clean)
	@(cd test/testsfml && $(MAKE) clean)
	@(cd test/testsystem && $(MAKE) clean)

mrproper: clean
	@(cd lib && $(MAKE) mrproper)
	@(cd test/testsfml && $(MAKE) mrproper)
	@(cd test/testsystem && $(MAKE) mrproper)
