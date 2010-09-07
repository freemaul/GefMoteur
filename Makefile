

all:
	@(cd src && $(MAKE))

%.o:%.c
	@ $(CC) -o $@ -c $< $(CFLAGS)

