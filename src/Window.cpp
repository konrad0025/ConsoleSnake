#include "Window.h"
#include <string>

Window::Window(Window &win): upperLeftCorner(win.upperLeftCorner), widthWindow(win.widthWindow),heightWindow(win.heightWindow),buttonStart("Start",CPoint(upperLeftCorner.x+(widthWindow/2)/2,upperLeftCorner.y+(heightWindow/2)),widthWindow/2,1,true), buttonHelp("Help",CPoint(upperLeftCorner.x+(widthWindow/2)/2,upperLeftCorner.y+(heightWindow/2)+2),widthWindow/2,1,false),buttonExit("Exit",CPoint(upperLeftCorner.x+(widthWindow/2)/2,upperLeftCorner.y+(heightWindow/2)+4),widthWindow/2,1,false){
    initscr();
    cbreak();
    noecho();
    curs_set(0);
    start_color();

    timeout(160);

}

Window::Window(CPoint& corner, int width, int height): upperLeftCorner(corner), widthWindow(width),heightWindow(height),buttonStart("Start",CPoint(upperLeftCorner.x+(widthWindow/2)/2,upperLeftCorner.y+(heightWindow/2)),widthWindow/2,3,true), buttonHelp("Help",CPoint(upperLeftCorner.x+(widthWindow/2)/2,upperLeftCorner.y+(heightWindow/2)-3),widthWindow/2,3,true),buttonExit("Exit",CPoint(upperLeftCorner.x+(widthWindow/2)/2,upperLeftCorner.y+(heightWindow/2)-6),widthWindow/2,3,true) {
    initscr();
    cbreak();
    noecho();
    curs_set(0);
    start_color();
    timeout(160);
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
    int y=2+upperLeftCorner.y,x=upperLeftCorner.x+5;
    mvprintw(++y,x,"  _____             _        ");
    mvprintw(++y,x," / ____|           | |       ");
    mvprintw(++y,x,"| (___  _ __   __ _| | _____ ");
    mvprintw(++y,x," \\___ \\| '_ \\ / _` | |/ / _ \\ ");
    mvprintw(++y,x," ____) | | | | (_| |   |  __/");
    mvprintw(++y,x,"|_____/|_| |_|\\__,_|_|\\_\\___|");
    buttonStart.paint();
    buttonHelp.paint();
    buttonExit.paint();
}
void Window::printAfterGame(int level)
{
    int y=5+upperLeftCorner.y,x=upperLeftCorner.x+3;
    clearWindow();
    printBorder();
    mvprintw(++y,x,"Your final score is %d",level);
    mvprintw(++y,x,"Press-'r' to restart the game");
    mvprintw(++y,x,"Press-'q' to quit the game");
}

void Window::clearWindow()
{
    for(int i=0;i<LINES;i++)
    {
        mvhline(i, 0, ' ', COLS);
    }
}

void Window::moveWindow(enum direction dir)
{
    switch(dir){
        case up:
            upperLeftCorner.y--;
            buttonStart.upperLeftCorner.y--;
            buttonHelp.upperLeftCorner.y--;
            buttonExit.upperLeftCorner.y--;
            break;
        case down:
            upperLeftCorner.y++;
            buttonStart.upperLeftCorner.y++;
            buttonHelp.upperLeftCorner.y++;
            buttonExit.upperLeftCorner.y++;
            break;
        case left:
            upperLeftCorner.x--;
            buttonStart.upperLeftCorner.x--;
            buttonHelp.upperLeftCorner.x--;
            buttonExit.upperLeftCorner.x--;
            break;
        case right:
            upperLeftCorner.x++;
            buttonStart.upperLeftCorner.x++;
            buttonHelp.upperLeftCorner.x++;
            buttonExit.upperLeftCorner.x++;
            break;
    };
    clearWindow();
}