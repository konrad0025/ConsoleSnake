#include "Window.h"
#include <string>

Window::Window(Window &win): upperLeftCorner(win.upperLeftCorner), widthWindow(win.widthWindow),heightWindow(win.heightWindow),buttonStart("Start",CPoint(upperLeftCorner.x+(widthWindow/2)/2,upperLeftCorner.y+(heightWindow/2)),widthWindow/2,1,true), buttonHelp("Help",CPoint(upperLeftCorner.x+(widthWindow/2)/2,upperLeftCorner.y+(heightWindow/2)+2),widthWindow/2,1,false),buttonExit("Exit",CPoint(upperLeftCorner.x+(widthWindow/2)/2,upperLeftCorner.y+(heightWindow/2)+4),widthWindow/2,1,false){
    initscr();

    cbreak();
    noecho();
    curs_set(0);
    start_color();
    keypad(stdscr, TRUE);
    timeout(160);

}

Window::Window(CPoint& corner, int width, int height): upperLeftCorner(corner), widthWindow(width),heightWindow(height),buttonStart("Start",CPoint(upperLeftCorner.x+(widthWindow/2)/2,upperLeftCorner.y+(heightWindow/2)),widthWindow/2,3,true), buttonHelp("Help",CPoint(upperLeftCorner.x+(widthWindow/2)/2,upperLeftCorner.y+(heightWindow/2)-3),widthWindow/2,3,true),buttonExit("Exit",CPoint(upperLeftCorner.x+(widthWindow/2)/2,upperLeftCorner.y+(heightWindow/2)-6),widthWindow/2,3,true) {
    initscr();
    cbreak();
    noecho();
    curs_set(0);
    start_color();
    keypad(stdscr, TRUE);
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
    string line1="  _____             _        ";
    int y=2+upperLeftCorner.y;
    int x=upperLeftCorner.x+widthWindow/2-line1.size()/2;
    mvprintw(++y,x,line1.c_str());
    mvprintw(++y,x," / ____|           | |       ");
    mvprintw(++y,x,"| (___  _ __   __ _| | _____ ");
    mvprintw(++y,x," \\___ \\| '_ \\ / _` | |/ / _ \\ ");
    mvprintw(++y,x," ____) | | | | (_| |   |  __/");
    mvprintw(++y,x,"|_____/|_| |_|\\__,_|_|\\_\\___|");
    buttonStart.print();
    buttonHelp.print();
    buttonExit.print();
}

void Window::printEntryHelpInfo() {

    init_color(COLOR_WHITE,500,500,500);
    init_pair(3, COLOR_BLACK, COLOR_WHITE);
    string line2="Press-'r' to restart the game";
    string line3="Press-'p' to pause the game";
    string line4="Press-'q' to quit the game";
    string line1="During the game";
    string line5="WASD- let you move";
    attron(COLOR_PAIR(3));
    int y=(upperLeftCorner.y+heightWindow/2)-6;
    for(int i=0;i<line2.size()+2;i++)
    {
        for(int j=0;j<5+2;j++)
        {
            mvprintw(y+j,upperLeftCorner.x+widthWindow/2-line2.size()/2+i-1," ");
        }
    }

    mvprintw(++y,(upperLeftCorner.x+widthWindow/2)-line1.size()/2,line1.c_str());
    mvprintw(++y,(upperLeftCorner.x+widthWindow/2)-line2.size()/2,line2.c_str());
    mvprintw(++y,(upperLeftCorner.x+widthWindow/2)-line3.size()/2,line3.c_str());
    mvprintw(++y,(upperLeftCorner.x+widthWindow/2)-line4.size()/2,line4.c_str());
    mvprintw(++y,(upperLeftCorner.x+widthWindow/2)-line5.size()/2,line5.c_str());
    attroff(COLOR_PAIR(3));
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

void Window::changePointedButton(enum direction dir) {
    switch(dir){
        case down:
            if(buttonStart.isPointed)
            {
                buttonStart.isPointed=false;
                buttonHelp.isPointed=true;
            }
            else if(buttonHelp.isPointed)
            {
                buttonHelp.isPointed=false;
                buttonExit.isPointed=true;
            }
            else if(buttonExit.isPointed)
            {
                buttonExit.isPointed=false;
                buttonStart.isPointed=true;
            }
            break;
        case up:
            if(buttonStart.isPointed)
            {
                buttonStart.isPointed=false;
                buttonExit.isPointed=true;
            }
            else if(buttonHelp.isPointed)
            {
                buttonHelp.isPointed=false;
                buttonStart.isPointed=true;
            }
            else if(buttonExit.isPointed)
            {
                buttonExit.isPointed=false;
                buttonHelp.isPointed=true;
            }
            break;
    };
}