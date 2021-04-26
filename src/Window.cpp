#include "Window.h"

Window::Window(Window &win): upperLeftCorner(win.upperLeftCorner),iColorSide(true),iColor(0), widthWindow(win.widthWindow),heightWindow(win.heightWindow),button(CPoint(upperLeftCorner.x+(widthWindow/2)/2,upperLeftCorner.y+(heightWindow/2)),widthWindow/2,1){
    initscr();
    cbreak();
    noecho();
    curs_set(0);
    start_color();
    keypad(stdscr, TRUE);
    timeout(160);
    Color::colorInit();
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
    settingsColorButtons.push_back(pair<string,int>("Yellow",1));
    settingsColorButtons.push_back(pair<string,int>("Green",3));
    settingsColorButtons.push_back(pair<string,int>("Blue",5));
    settingsColorButtons.push_back(pair<string,int>("Back",7));
    whichOneInSettingsColorIsPointed=0;

}
Window::Window(CPoint& corner, int width, int height):iColorSide(true), iColor(0), upperLeftCorner(corner), widthWindow(width),heightWindow(height),button(CPoint(upperLeftCorner.x+(widthWindow/2)/2,upperLeftCorner.y+(heightWindow/2)),widthWindow/2,1) {
    initscr();
    cbreak();
    noecho();
    curs_set(0);
    start_color();
    keypad(stdscr, TRUE);
    timeout(160);
    Color::colorInit();
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
    settingsColorButtons.push_back(pair<string,int>("Yellow",1));
    settingsColorButtons.push_back(pair<string,int>("Green",3));
    settingsColorButtons.push_back(pair<string,int>("Blue",5));
    settingsColorButtons.push_back(pair<string,int>("Back",7));
    whichOneInSettingsColorIsPointed=0;
}

Window::~Window() {
    endwin();
}

int Window::getEvent() {
    return getch();
}

void Window::printBorder() {

    for(int i=0;i<widthWindow;i++)
    {
        for(int j=0;j<heightWindow;j++)
        {
            if(i==0 || j==0 || j==heightWindow-1 || i==widthWindow-1)
            {
                Color::colorOn(GREY,BLACK);
                mvaddch(upperLeftCorner.y+j,upperLeftCorner.x+i,' ');
                Color::colorOff(GREY,BLACK);
            }
            else
            {
                Color::colorOn(BLACK,WHITE);
                mvaddch(upperLeftCorner.y+j,upperLeftCorner.x+i,' ');
                Color::colorOff(BLACK,WHITE);
            }
        }
    }
}

void Window::printEntryWindow() {
    string line1="  _____             _        ";
    int y=heightWindow/4-3+upperLeftCorner.y;
    int x=upperLeftCorner.x+widthWindow/2-line1.size()/2;
    init_color(15,0,300+iColor,0);
    iColorSide ? iColor=iColor+50 : iColor=iColor-50;
    if(iColor>750){
        iColorSide=false;
    }
    else if(iColor<50)
    {
        iColorSide=true;
    }
    Color::colorOn(BLACK,15);
    mvprintw(++y,x,line1.c_str());
    mvprintw(++y,x," / ____|           | |       ");
    mvprintw(++y,x,"| (___  _ __   __ _| | _____ ");
    mvprintw(++y,x," \\___ \\| '_ \\ / _` | |/ / _ \\ ");
    mvprintw(++y,x," ____) | | | | (_| |   |  __/");
    mvprintw(++y,x,"|_____/|_| |_|\\__,_|_|\\_\\___|");
    Color::colorOff(BLACK,15);;
    button.printMap(menuButtons,whichOneInMenuIsPointed);
}

void Window::printSettings(){
    button.printMap(settingsButtons,whichOneInSettingsIsPointed);
}
void Window::printSettingsPosition() {
    button.printButton("Back",true,heightWindow/4);
}
void Window::printSettingsSize() {
    button.printButton("Back",true,heightWindow/4);
}
void Window::printSettingsColor() {
    button.printMap(settingsColorButtons,whichOneInSettingsColorIsPointed);
}
void Window::printEntryHelpInfo() {

    string line2="Press-'r' to restart the game";
    string line3="Press-'p' to pause the game";
    string line4="Press-'q' to quit the game";
    string line1="During the game";
    string line5="WASD- let you move";
    Color::colorOn(GREY,BLACK);
    int y=(upperLeftCorner.y+heightWindow/2)-6;
    printBackgroundForText(line2.size()+2,5+2,y);
    mvprintw(++y,(upperLeftCorner.x+widthWindow/2)-line1.size()/2,line1.c_str());
    mvprintw(++y,(upperLeftCorner.x+widthWindow/2)-line2.size()/2,line2.c_str());
    mvprintw(++y,(upperLeftCorner.x+widthWindow/2)-line3.size()/2,line3.c_str());
    mvprintw(++y,(upperLeftCorner.x+widthWindow/2)-line4.size()/2,line4.c_str());
    mvprintw(++y,(upperLeftCorner.x+widthWindow/2)-line5.size()/2,line5.c_str());
    Color::colorOff(GREY,BLACK);
    button.printButton("Back",true,heightWindow/4);
}
void Window::printPause() {
    string line1 ="Press-'p' to unpause";
    int y=upperLeftCorner.y+2,x=upperLeftCorner.x+widthWindow/2-line1.size()/2;
    Color::colorOn(GREY,BLACK);
    printBackgroundForText(line1.size()+2,1,y);
    mvprintw(y,x,line1.c_str());
    Color::colorOff(GREY,BLACK);
}
void Window::printAfterGame(int level)
{
    string line1="Your final score is ";
    line1+=to_string(level);
    int y=upperLeftCorner.y+heightWindow/4;
    clearWindow();
    printBorder();
    Color::colorOn(GREY,BLACK);
    printBackgroundForText(line1.size()+2,1+2,y);
    mvprintw(++y,upperLeftCorner.x+widthWindow/2-line1.size()/2,line1.c_str());
    Color::colorOff(GREY,BLACK);
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
        Color::colorOn(BLACK,WHITE);
        mvhline(i, 0, ' ', COLS);
        Color::colorOff(BLACK,WHITE);
    }
}

void Window::moveWindow(enum direction dir)
{
    switch(dir){
        case up:
            if(upperLeftCorner.y>0)
            {
                upperLeftCorner.y--;
                button.upperLeftCorner.y--;
            }
            break;
        case down:
            if(upperLeftCorner.y+heightWindow<LINES)
            {
                upperLeftCorner.y++;
                button.upperLeftCorner.y++;
            }
            break;
        case left:
            if(upperLeftCorner.x>0)
            {
                upperLeftCorner.x--;
                button.upperLeftCorner.x--;
            }
            break;
        case right:
            if(upperLeftCorner.x+widthWindow<COLS)
            {
                upperLeftCorner.x++;
                button.upperLeftCorner.x++;
            }
            break;
    };
    clearWindow();
}
void Window::changeWindowSize(enum direction dir) {
    switch (dir) {
        case up:
            if(heightWindow>19) heightWindow--;
            break;
        case down:
            if(heightWindow<45 && upperLeftCorner.y+heightWindow<LINES) heightWindow++;
            break;
        case left:
            if(widthWindow>34) widthWindow--;
            break;
        case right:
            if(widthWindow<100 && upperLeftCorner.x+widthWindow<COLS) widthWindow++;
            break;
    }
    clearWindow();
    button.setButtonVariables(CPoint(upperLeftCorner.x+(widthWindow/2)/2,upperLeftCorner.y+(heightWindow/2)),widthWindow/2,1);
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