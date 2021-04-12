CC=g++
SRC=./src
OBJ=./obj

all: $(OBJ) SnakeGame

$(OBJ):
	mkdir -p $(OBJ)

SnakeGame: $(OBJ)/main.o $(OBJ)/CPoint.o $(OBJ)/Window.o $(OBJ)/Snake.o
	$(CC) $^ -o $@ -lncurses
$(OBJ)/main.o: $(SRC)/main.cpp $(SRC)/Snake.h $(SRC)/Snake.cpp $(SRC)/Window.h $(SRC)/Window.cpp $(SRC)/CPoint.cpp $(SRC)/CPoint.h
	$(CC) -c $< -o $@
$(OBJ)/Snake.o: $(SRC)/Snake.cpp $(SRC)/Snake.h $(SRC)/Window.h $(SRC)/Window.cpp $(SRC)/CPoint.cpp $(SRC)/CPoint.h
	$(CC) -c $< -o $@
$(OBJ)/Window.o: $(SRC)/Window.cpp $(SRC)/Window.h $(SRC)/CPoint.cpp $(SRC)/CPoint.h
	$(CC) -c $< -o $@
$(OBJ)/CPoint.o: $(SRC)/CPoint.cpp $(SRC)/CPoint.h
	$(CC) -c $< -o $@

.PHONY: clean

clean:
	-rm *.o SnakeGame
