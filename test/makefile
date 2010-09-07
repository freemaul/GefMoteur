SRC=test.cpp
OBJ=$(SRC:.cpp=.o)

all:test

test: $(OBJ)
	@$(CC) -o test -L ../lib/ $(OBJ) -lGefMoteur

runtest: test
	@./test/test

%.o:%.cpp
	@$(CC) -o $@ -c $< $(CFLAGS) $(INC_PATH)

clean:
	@rm -f ./*.o

mrproper: clean
	@rm -f ./test

