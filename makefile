CC=g++

all: SnakeGame

SnakeGame: main.o CPoint.o Window.o Snake.o
	$(CC) $^ -o $@ -lncurses
main.o: main.cpp Snake.h Snake.cpp Window.h Window.cpp CPoint.cpp CPoint.h
	$(CC) -c $< -o $@
Snake.o: Snake.cpp Snake.h Window.h Window.cpp CPoint.cpp CPoint.h
	$(CC) -c $< -o $@
Window.o: Window.cpp Window.h CPoint.cpp CPoint.h
	$(CC) -c $< -o $@
CPoint.o: CPoint.cpp CPoint.h
	$(CC) -c $< -o $@

.PHONY: clean

clean:
	-rm *.o SnakeGame
