export CC=g++
export CFLAGS=-W


all:
	@(cd src && $(MAKE))

test:all
	@ (cd test && $(MAKE))

clean:
	@(cd src && $(MAKE) clean)

meproper: clean
	@(cd lib && $(MAKE) mrproper)

