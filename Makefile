export CC=g++
export CFLAGS=-W


all:
	@(cd src && $(MAKE))

%.o:%.c
	@ $(CC) -o $@ -c $< $(CFLAGS)

test:all
	@ (cd test && $(MAKE))

clean:
	@(cd src && $(MAKE) clean)

meproper: clean
	@(cd lib && $(MAKE) mrproper)

