export CC=g++
export CFLAGS=-W
export INST_PATH=$(PWD)/lib
export INC_PATH=-I $(PWD)/include

all:
	@(cd src && $(MAKE))

install: all
	@(cp lib/*.a /usr/lib/)
	@(cp -R include/* /usr/include/)

test:all
	@(cd test && $(MAKE))

runtest: test
	@(cd test && ./test)

clean:
	@(cd src && $(MAKE) clean)
	@(cd test && $(MAKE) clean)

mrproper: clean
	@(cd lib && $(MAKE) mrproper)
	@(cd test && $(MAKE) mrproper)

