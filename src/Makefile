OBJ=$(SRC:.c=.o)

all:$(INST_PATH)/libGefMoteur.a

$(INST_PATH)/libGefMoteur.a: $(OBJ)
	mkdir -p $(INST_PATH)
	ar r $(INST_PATH)/libGefMoteur.a ./*.o

%.o:%.c
	@ $(CC) -o $@ -c $< $(CFLAGS) $(INC_PATH)
