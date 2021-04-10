#include "Window.h"
#include <ncurses.h>

Window::Window(CPoint& corner, int width, int height): upperLeftCorner(corner), widthWindow(width),heightWindow(height) {
    initscr();
    cbreak();
    noecho();
    curs_set(0);
    start_color();
    timeout(500);
}

Window::~Window() {
    endwin();
}

void Window::paint() {
    init_color(COLOR_WHITE,500,500,500);
    init_pair(1, COLOR_YELLOW, COLOR_WHITE);
    attron(COLOR_PAIR(1));
    for(int i=0;i<widthWindow;i++)
    {
        mvaddch(upperLeftCorner.y,upperLeftCorner.x+i,' ');
    }
    for(int i=0;i<widthWindow;i++)
    {
        mvaddch(upperLeftCorner.y+heightWindow-1,upperLeftCorner.x+i,' ');
    }
    for(int i=0;i<heightWindow;i++)
    {
        mvaddch(upperLeftCorner.y+i,upperLeftCorner.x,' ');
    }
    for(int i=0;i<heightWindow;i++)
    {
        mvaddch(upperLeftCorner.y+i,upperLeftCorner.x+widthWindow-1,' ');
    }
    attroff(COLOR_PAIR(1));
}