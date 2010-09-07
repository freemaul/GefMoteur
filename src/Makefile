SRC= GefMoteur.cpp
OBJ= $(SRC:.cpp=.o)

all:$(INST_PATH)/libGefMoteur.a

$(INST_PATH)/libGefMoteur.a: $(OBJ)
	@mkdir -p $(INST_PATH)
	@ar r $(INST_PATH)/libGefMoteur.a $(OBJ)

%.o:%.cpp
	@$(CC) -o $@ -c $< $(CFLAGS) $(INC_PATH)

clean:
	@rm -f ./*.o

