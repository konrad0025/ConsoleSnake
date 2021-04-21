#include "Window.h"

Window::Window(Window &win): upperLeftCorner(win.upperLeftCorner),iColorSide(true),iColor(0), widthWindow(win.widthWindow),heightWindow(win.heightWindow),button(CPoint(upperLeftCorner.x+(widthWindow/2)/2,upperLeftCorner.y+(heightWindow/2)),widthWindow/2,1){
    initscr();
    cbreak();
    noecho();
    curs_set(0);
    start_color();
    keypad(stdscr, TRUE);
    timeout(160);

    menuButtons.push_back(pair<string,int>("Start",1));
    menuButtons.push_back(pair<string,int>("Settings",3));
    menuButtons.push_back(pair<string,int>("Help",5));
    menuButtons.push_back(pair<string,int>("Exit",7));
    whichOneInMenuIsPointed=0;
    afterGameButtons.push_back(pair<string,int>("Restart",1));
    afterGameButtons.push_back(pair<string,int>("Menu",3));
    afterGameButtons.push_back(pair<string,int>("Exit",5));
    whichOneInAfterGameIsPointed=0;
    settingsButtons.push_back(pair<string,int>("Window position",1));
    settingsButtons.push_back(pair<string,int>("Window Size",3));
    settingsButtons.push_back(pair<string,int>("Snake Color",5));
    settingsButtons.push_back(pair<string,int>("Back",7));
    whichOneInSettingsIsPointed=0;

}

Window::Window(CPoint& corner, int width, int height):iColorSide(true), iColor(0), upperLeftCorner(corner), widthWindow(width),heightWindow(height),button(CPoint(upperLeftCorner.x+(widthWindow/2)/2,upperLeftCorner.y+(heightWindow/2)),widthWindow/2,1) {
    initscr();
    cbreak();
    noecho();
    curs_set(0);
    start_color();
    keypad(stdscr, TRUE);
    timeout(160);
    menuButtons.push_back(pair<string,int>("Start",1));
    menuButtons.push_back(pair<string,int>("Settings",3));
    menuButtons.push_back(pair<string,int>("Help",5));
    menuButtons.push_back(pair<string,int>("Exit",7));
    whichOneInMenuIsPointed=0;
    afterGameButtons.push_back(pair<string,int>("Restart",1));
    afterGameButtons.push_back(pair<string,int>("Menu",3));
    afterGameButtons.push_back(pair<string,int>("Exit",5));
    whichOneInAfterGameIsPointed=0;
    settingsButtons.push_back(pair<string,int>("Window position",1));
    settingsButtons.push_back(pair<string,int>("Window Size",3));
    settingsButtons.push_back(pair<string,int>("Snake Color",5));
    settingsButtons.push_back(pair<string,int>("Back",7));
    whichOneInSettingsIsPointed=0;
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
    init_color(15,0,300+iColor,0);
    init_pair(6, 15, COLOR_BLACK);
    iColorSide ? iColor=iColor+50 : iColor=iColor-50;
    if(iColor>750){
        iColorSide=false;
    }
    else if(iColor<50)
    {
        iColorSide=true;
    }
    attron(COLOR_PAIR(6));
    mvprintw(++y,x,line1.c_str());
    mvprintw(++y,x," / ____|           | |       ");
    mvprintw(++y,x,"| (___  _ __   __ _| | _____ ");
    mvprintw(++y,x," \\___ \\| '_ \\ / _` | |/ / _ \\ ");
    mvprintw(++y,x," ____) | | | | (_| |   |  __/");
    mvprintw(++y,x,"|_____/|_| |_|\\__,_|_|\\_\\___|");
    attroff(COLOR_PAIR(6));
    button.printMap(menuButtons,whichOneInMenuIsPointed);
}

void Window::printSettings(){
    button.printMap(settingsButtons,whichOneInSettingsIsPointed);
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
    printBackgroundForText(line2.size()+2,5+2,y);
    mvprintw(++y,(upperLeftCorner.x+widthWindow/2)-line1.size()/2,line1.c_str());
    mvprintw(++y,(upperLeftCorner.x+widthWindow/2)-line2.size()/2,line2.c_str());
    mvprintw(++y,(upperLeftCorner.x+widthWindow/2)-line3.size()/2,line3.c_str());
    mvprintw(++y,(upperLeftCorner.x+widthWindow/2)-line4.size()/2,line4.c_str());
    mvprintw(++y,(upperLeftCorner.x+widthWindow/2)-line5.size()/2,line5.c_str());
    attroff(COLOR_PAIR(3));
    button.printButton("Back",true,heightWindow/4);
}
void Window::printPause() {
    init_color(COLOR_WHITE,500,500,500);
    init_pair(3, COLOR_BLACK, COLOR_WHITE);
    string line1 ="Press-'p' to unpause";
    int y=upperLeftCorner.y+2,x=upperLeftCorner.x+widthWindow/2-line1.size()/2;
    attron(COLOR_PAIR(3));
    printBackgroundForText(line1.size()+2,1,y);
    mvprintw(y,x,line1.c_str());
    attroff(COLOR_PAIR(3));
}
void Window::printAfterGame(int level)
{
    init_color(COLOR_WHITE,500,500,500);
    init_pair(8, COLOR_BLACK, COLOR_WHITE);
    string line1="Your final score is ";
    line1+=to_string(level);
    int y=upperLeftCorner.y+heightWindow/4;
    clearWindow();
    printBorder();
    attron(COLOR_PAIR(8));
    printBackgroundForText(line1.size()+2,1+2,y);
    mvprintw(++y,upperLeftCorner.x+widthWindow/2-line1.size()/2,line1.c_str());
    attroff(COLOR_PAIR(8));
    button.printMap(afterGameButtons,whichOneInAfterGameIsPointed);
}
void Window::printBackgroundForText(int width, int height, int y) {
    for(int i=0;i<width;i++)
    {
        for(int j=0;j<height;j++)
        {
            mvprintw(y+j,upperLeftCorner.x+widthWindow/2-width/2+i," ");
        }
    }
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
            button.upperLeftCorner.y--;
            break;
        case down:
            upperLeftCorner.y++;
            button.upperLeftCorner.y++;
            break;
        case left:
            upperLeftCorner.x--;
            button.upperLeftCorner.x--;
            break;
        case right:
            upperLeftCorner.x++;
            button.upperLeftCorner.x++;
            break;
    };
    clearWindow();
}
void Window::changeWhichButtonIsPointed(enum direction dir,const vector<pair<string,int>> &mapButton , int &whichOneIsPointed)
{
    switch(dir){
        case down:
            (whichOneIsPointed>=mapButton.size()-1) ? (whichOneIsPointed=0):(whichOneIsPointed++);
            break;
        case up:
            (whichOneIsPointed<=0) ? (whichOneIsPointed=mapButton.size()-1):(whichOneIsPointed--) ;
            break;
    };
}