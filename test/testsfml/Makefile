SRC=test.cpp
OBJ=$(SRC:.cpp=.o)

all:test

test: $(OBJ)
	@$(CC) -o test $(INC_PATH) $(LIB_PATH) $(OBJ) -lGefMoteur -lsfml-graphics-s -lsfml-window-s -lsfml-system-s -lfreetype -lglut -lopenal -lsndfile -lX11 -lXrandr

%.o:%.cpp
	@$(CC) -o $@ -c $< $(CFLAGS) $(INC_PATH)

clean:
	@rm -f ./*.o

mrproper: clean
	@rm -f ./test

