CC=g++
SRC=./src
OBJ=./obj

all: $(OBJ) ConsoleSnake

$(OBJ):
	mkdir -p $(OBJ)

ConsoleSnake: $(OBJ)/main.o $(OBJ)/CPoint.o $(OBJ)/Window.o $(OBJ)/Snake.o $(OBJ)/Button.o
	$(CC) $^ -o $@ -lncurses
$(OBJ)/main.o: $(SRC)/main.cpp $(SRC)/Snake.h $(SRC)/Snake.cpp $(SRC)/Window.h $(SRC)/Window.cpp $(SRC)/Button.cpp $(SRC)/Button.h $(SRC)/CPoint.cpp $(SRC)/CPoint.h
	$(CC) -c $< -o $@
$(OBJ)/Snake.o: $(SRC)/Snake.cpp $(SRC)/Snake.h $(SRC)/Window.h $(SRC)/Window.cpp $(SRC)/Button.cpp $(SRC)/Button.h $(SRC)/CPoint.cpp $(SRC)/CPoint.h
	$(CC) -c $< -o $@
$(OBJ)/Window.o: $(SRC)/Window.cpp $(SRC)/Window.h $(SRC)/Button.cpp $(SRC)/Button.h $(SRC)/CPoint.cpp $(SRC)/CPoint.h
	$(CC) -c $< -o $@
$(OBJ)/Button.o: $(SRC)/Button.cpp $(SRC)/Button.h
	$(CC) -c $< -o $@
$(OBJ)/CPoint.o: $(SRC)/CPoint.cpp $(SRC)/CPoint.h
	$(CC) -c $< -o $@

.PHONY: clean

clean:
	-rm -r $(OBJ)/*.o ConsoleSnake obj
install:
	sudo apt-get install g++ libncurses5-dev
