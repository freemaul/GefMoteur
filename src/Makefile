
all:$(INST_PATH)/libGefMoteur.a

$(INST_PATH)/libGefMoteur.a: ./*.o
	ar r (INST_PATH)/libGefMoteur.a ./*.o

%.o:%.c
	@ $(CC) -o $@ -c $< $(CFLAGS)