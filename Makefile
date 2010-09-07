export CC=g++
export CFLAGS=-W
export INST_PATH=$(PWD)/lib
export INC_PATH=$(PWD)/include

all:
	@(cd src && $(MAKE))

test:all
	@ (cd test && $(MAKE))

clean:
	@(cd src && $(MAKE) clean)

meproper: clean
	@(cd lib && $(MAKE) mrproper)

