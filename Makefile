export CC=g++
export CFLAGS=-W
export INST_PATH=$(PWD)/lib
export INC_PATH=-I $(PWD)/include

all:
	@(cd src && $(MAKE))

install: all
	@(cp lib/*.a /usr/lib/)
	@(cp -R include/* /usr/include/)

testsfml:all
	@(cd test/testsfml && $(MAKE))

runtestsfml: testsfml
	@(cd test/testsfml && ./test)

clean:
	@(cd src && $(MAKE) clean)
	@(cd test/testsfml && $(MAKE) clean)

mrproper: clean
	@(cd lib && $(MAKE) mrproper)
	@(cd test/testsfml && $(MAKE) mrproper)

