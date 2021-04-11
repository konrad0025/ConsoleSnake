#include "Window.h"
#include <ncurses.h>

Window::Window(Window &win): upperLeftCorner(win.upperLeftCorner), widthWindow(win.widthWindow),heightWindow(win.heightWindow) {
    initscr();
    cbreak();
    noecho();
    curs_set(0);
    start_color();
    timeout(160);
}

Window::Window(CPoint& corner, int width, int height): upperLeftCorner(corner), widthWindow(width),heightWindow(height) {
    initscr();
    cbreak();
    noecho();
    curs_set(0);
    start_color();
    timeout(200);
}

Window::~Window() {
    endwin();
}

int Window::getEvent() {
    return getch();
}

void Window::printBorder() {
    init_color(COLOR_WHITE,500,500,500);
    init_pair(3, COLOR_YELLOW, COLOR_WHITE);
    init_pair(4,COLOR_YELLOW,COLOR_BLACK);
    for(int i=0;i<widthWindow;i++)
    {
        for(int j=0;j<heightWindow;j++)
        {
            if(i==0 || j==0 || j==heightWindow-1 || i==widthWindow-1)
            {
                attron(COLOR_PAIR(3));
                mvaddch(upperLeftCorner.y+j,upperLeftCorner.x+i,' ');
                attroff(COLOR_PAIR(3));
            }
            else
            {
                attron(COLOR_PAIR(4));
                mvaddch(upperLeftCorner.y+j,upperLeftCorner.x+i,' ');
                attroff(COLOR_PAIR(4));
            }
        }
    }
}

void Window::printEntryWindow() {
    int y=3+upperLeftCorner.y,x=upperLeftCorner.x+5;
    mvprintw(++y,x,"  _____             _        ");
    mvprintw(++y,x," / ____|           | |       ");
    mvprintw(++y,x,"| (___  _ __   __ _| | _____ ");
    mvprintw(++y,x," \\___ \\| '_ \\ / _` | |/ / _ \\ ");
    mvprintw(++y,x," ____) | | | | (_| |   |  __/");
    mvprintw(++y,x,"|_____/|_| |_|\\__,_|_|\\_\\___|");
    mvprintw(++y,x,"Press-'r' to start the game");
    mvprintw(++y,x,"Press-'h' to get help");
    mvprintw(++y,x,"Press-'p' to pause the game");
    mvprintw(++y,x,"WASD- let you move");
}
void Window::printAfterGame(int level)
{
    int y=5+upperLeftCorner.y,x=upperLeftCorner.x+3;
    mvprintw(++y,x,"Your final score is %d",level);
    mvprintw(++y,x,"If you want play again press 'r'");
}