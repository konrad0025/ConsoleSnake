#include "Snake.h"

Snake::Snake(Window &win): gameWindow(win),dir(left),level(0),gameMode(beforeGame) {

    snakePosition.push_back(CPoint(gameWindow.widthWindow/2,gameWindow.heightWindow/4-1));
    snakePosition.push_back(CPoint(gameWindow.widthWindow/2+1,gameWindow.heightWindow/4-1));
    snakePosition.push_back(CPoint(gameWindow.widthWindow/2+2,gameWindow.heightWindow/4-1));
    while(!makeFood()){}
    color=COLOR_GREEN;
}

void Snake::print() {
    printLevelInfo();
    printFood();
    printSnake();
}

void Snake::printSnake()
{
    init_color(COLOR_GREEN,0,300,0);
    init_pair(1, COLOR_YELLOW, COLOR_GREEN);
    init_pair(2, COLOR_YELLOW, 10);
    init_color(20,900,900,0);
    init_color(22,300,300,0);
    init_pair(30, COLOR_YELLOW, 22);
    init_pair(40, COLOR_YELLOW, 20);
    init_color(21,100,200,1000);
    init_pair(50, COLOR_YELLOW, COLOR_BLUE);
    init_pair(60, COLOR_YELLOW, 21);
    for(unsigned int i=0; i<snakePosition.size();i++)
    {
        if(i==0)
        {
            if(color==COLOR_YELLOW) attron(COLOR_PAIR(30));
            else if(color==COLOR_GREEN) attron(COLOR_PAIR(1));
            else if(color==COLOR_BLUE) attron(COLOR_PAIR(50));
            mvaddch(gameWindow.upperLeftCorner.y+snakePosition[i].y,gameWindow.upperLeftCorner.x+snakePosition[i].x,' ');
            if(color==COLOR_YELLOW) attroff(COLOR_PAIR(30));
            else if(color==COLOR_GREEN) attroff(COLOR_PAIR(1));
            else if(color==COLOR_BLUE) attroff(COLOR_PAIR(50));
        }
        else
        {
            if(color==COLOR_YELLOW) attron(COLOR_PAIR(40));
            else if(color==COLOR_GREEN) attron(COLOR_PAIR(2));
            else if(color==COLOR_BLUE) attron(COLOR_PAIR(60));
            mvaddch(gameWindow.upperLeftCorner.y+snakePosition[i].y,gameWindow.upperLeftCorner.x+snakePosition[i].x,' ');
            if(color==COLOR_YELLOW) attroff(COLOR_PAIR(40));
            else if(color==COLOR_GREEN) attroff(COLOR_PAIR(2));
            else if(color==COLOR_BLUE) attroff(COLOR_PAIR(60));
        }
    }
}

void Snake::printFood() {
    init_pair(5, COLOR_YELLOW, COLOR_RED);
    attron(COLOR_PAIR(5));
    mvaddch(gameWindow.upperLeftCorner.y+food.y,gameWindow.upperLeftCorner.x+food.x,' ');
    attroff(COLOR_PAIR(5));
}

void Snake::printLevelInfo() {
    int textSize=strlen("|Your Score = %d|");
    init_color(COLOR_WHITE,500,500,500);
    init_pair(3, COLOR_BLACK, COLOR_WHITE);
    attron(COLOR_PAIR(3));
    mvprintw(gameWindow.upperLeftCorner.y-1,gameWindow.upperLeftCorner.x+(gameWindow.widthWindow/2)-(textSize/2),"|Your Score = %d|",level);
    attroff(COLOR_PAIR(3));
}

bool Snake::handleEvent(int key) {

    switch (gameMode){
        case beforeGame:
            return handleEventDuringBeforeGameMode(key);
        case settings:
            return handleEventDuringSettingsMode(key);
        case settingsPosition:
            return handleEventDuringSettingsPositionMode(key);
        case settingsSize:
            return handleEventDuringSettingsSizeMode(key);
        case settingsColor:
            return handleEventDuringSettingsColorMode(key);
        case helpBeforeGame:
            return handleEventDuringHelpBeforeGameMode(key);
        case game:
            return handleEventDuringGameMode(key);
        case afterGame:
            return handleEventDuringAfterGameMode(key);
        case pause:
            return handleEventDuringPauseMode(key);
        case help:
            return handleEventDuringHelpMode(key);
    };
    return true;
}

bool Snake::handleEventDuringGameMode(int key)
{
    switch (key)
    {
        case 'w':
            if(dir==down)
            {
                break;
            }
            dir=up;
            return true;
        case 's':
            if(dir==up)
            {
                break;
            }
            dir=down;
            return true;
        case 'd':
            if(dir==left)
            {
                break;
            }
            dir=right;
            return true;
        case 'a':
            if(dir==right)
            {
                break;
            }
            dir=left;
            return true;
        case KEY_UP:
            if(dir==down)
            {
                break;
            }
            dir=up;
            return true;
        case KEY_DOWN:
            if(dir==up)
            {
                break;
            }
            dir=down;
            return true;
        case KEY_RIGHT:
            if(dir==left)
            {
                break;
            }
            dir=right;
            return true;
        case KEY_LEFT:
            if(dir==right)
            {
                break;
            }
            dir=left;
            return true;
        case 'r':
            gameMode=game;
            restartGame();
            return true;
        case 'p':
            gameMode=pause;
            return true;
        case 'h':
            gameMode=help;
            return true;
        case 'q':
            return false;
    };
    return true;
}

bool Snake::handleEventDuringBeforeGameMode(int key) {
    switch(key){
        case 'q':
            return false;
        case KEY_UP:
            gameWindow.changeWhichButtonIsPointed(up,gameWindow.menuButtons,gameWindow.whichOneInMenuIsPointed);
            return true;
        case KEY_DOWN:
            gameWindow.changeWhichButtonIsPointed(down,gameWindow.menuButtons,gameWindow.whichOneInMenuIsPointed);
            return true;
        case '\n':
            if(gameWindow.whichOneInMenuIsPointed==0) {
                restartGame();
                gameMode=game;
            }
            else if(gameWindow.whichOneInMenuIsPointed==1) {
                gameMode=settings;
                gameWindow.whichOneInSettingsIsPointed=0;
            }
            else if(gameWindow.whichOneInMenuIsPointed==2) gameMode=helpBeforeGame;
            else if(gameWindow.whichOneInMenuIsPointed==3)
            {
                return false;
            }
            return true;
    };
    return true;
}

bool Snake::handleEventDuringSettingsMode(int key) {
    switch(key){
        case '\n':
            if(gameWindow.whichOneInSettingsIsPointed==0) gameMode=settingsPosition;
            else if(gameWindow.whichOneInSettingsIsPointed==1) gameMode=settingsSize;
            else if(gameWindow.whichOneInSettingsIsPointed==2) {
                gameMode=settingsColor;
                restartGame();
            }
            else if(gameWindow.whichOneInSettingsIsPointed==3) gameMode=beforeGame;
            return true;
        case KEY_UP:
            gameWindow.changeWhichButtonIsPointed(up,gameWindow.settingsButtons,gameWindow.whichOneInSettingsIsPointed);
            return true;
        case KEY_DOWN:
            gameWindow.changeWhichButtonIsPointed(down,gameWindow.settingsButtons,gameWindow.whichOneInSettingsIsPointed);
            return true;
        case 'q':
            return false;
    }
    return true;
}

bool Snake::handleEventDuringSettingsPositionMode(int key) {
    switch(key){
        case KEY_UP:
            gameWindow.moveWindow(up);
            return true;
        case KEY_DOWN:
            gameWindow.moveWindow(down);
            return true;
        case KEY_LEFT:
            gameWindow.moveWindow(left);
            return true;
        case KEY_RIGHT:
            gameWindow.moveWindow(right);
            return true;
        case '\n':
            gameMode=settings;
            return true;
        case 'q':
            return false;
    }
    return true;
}

bool Snake::handleEventDuringSettingsSizeMode(int key) {
    switch(key){
        case KEY_UP:
            gameWindow.changeWindowSize(up);
            return true;
        case KEY_DOWN:
            gameWindow.changeWindowSize(down);
            return true;
        case KEY_LEFT:
            gameWindow.changeWindowSize(left);
            return true;
        case KEY_RIGHT:
            gameWindow.changeWindowSize(right);
            return true;
        case '\n':
            gameMode=settings;
            return true;
        case 'q':
            return false;
    }
    return true;
}
bool Snake::handleEventDuringSettingsColorMode(int key) {
    moveSnake();
    switch(key){
        case '\n':
            if(gameWindow.whichOneInSettingsColorIsPointed==0) color=COLOR_YELLOW;
            else if(gameWindow.whichOneInSettingsColorIsPointed==1) color=COLOR_GREEN;
            else if(gameWindow.whichOneInSettingsColorIsPointed==2) color=COLOR_BLUE;
            else if(gameWindow.whichOneInSettingsColorIsPointed==3) {
                gameWindow.whichOneInSettingsColorIsPointed=0;
                gameMode=settings;
            }
            return true;
        case KEY_UP:
            gameWindow.changeWhichButtonIsPointed(up,gameWindow.settingsColorButtons,gameWindow.whichOneInSettingsColorIsPointed);
            return true;
        case KEY_DOWN:
            gameWindow.changeWhichButtonIsPointed(down,gameWindow.settingsColorButtons,gameWindow.whichOneInSettingsColorIsPointed);
            return true;
        case 'q':
            return false;
    }
    return true;
}
bool Snake::handleEventDuringHelpBeforeGameMode(int key) {
    switch(key){
        case '\n':
            gameMode=beforeGame;
            return true;
        case 'q':
            return false;
    }
    return true;

}

bool Snake::handleEventDuringAfterGameMode(int key) {
    switch(key){
        case KEY_UP:
            gameWindow.changeWhichButtonIsPointed(up,gameWindow.afterGameButtons,gameWindow.whichOneInAfterGameIsPointed);
            return true;
        case KEY_DOWN:
            gameWindow.changeWhichButtonIsPointed(down,gameWindow.afterGameButtons,gameWindow.whichOneInAfterGameIsPointed);
            return true;
        case '\n':
            if(gameWindow.whichOneInAfterGameIsPointed==0) {
                restartGame();
                gameMode=game;
            }
            else if(gameWindow.whichOneInAfterGameIsPointed==1) {
                restartGame();
                gameMode=beforeGame;
            }
            else if(gameWindow.whichOneInAfterGameIsPointed==2)
            {
                return false;
            }
            return true;
        case 'q':
            return false;
    };
    return true;
}

bool Snake::handleEventDuringPauseMode(int key) {
    switch(key){
        case 'p':
            gameMode=game;
            return true;
        case 'r':
            gameMode=game;
            restartGame();
            return true;
        case 'q':
            return false;
    };
    return true;
}

bool Snake::handleEventDuringHelpMode(int key) {
    switch(key){
        case 'h':
            gameMode=game;
            return true;
        case 'r':
            gameMode=game;
            restartGame();
            return true;
        case '\n':
            gameMode=game;
            return true;
        case 'q':
            return false;
    };
    return true;
}

void Snake::moveSnake() {
    auto headIndex=snakePosition.begin();
    switch(dir)
    {
        case up:
            if(snakePosition[0].y==1)
            {
                snakePosition.insert(headIndex,CPoint(snakePosition[0].x,gameWindow.heightWindow-2));
            }
            else
            {
                snakePosition.insert(headIndex,CPoint(snakePosition[0].x,snakePosition[0].y-1));
            }
            break;
        case down:
            if(snakePosition[0].y==gameWindow.heightWindow-2)
            {
                snakePosition.insert(headIndex,CPoint(snakePosition[0].x,1));
            }
            else
            {
                snakePosition.insert(headIndex,CPoint(snakePosition[0].x,snakePosition[0].y+1));
            }
            break;
        case right:
            if(snakePosition[0].x==gameWindow.widthWindow-2)
            {
                snakePosition.insert(headIndex,CPoint(1,snakePosition[0].y));
            }
            else
            {
                snakePosition.insert(headIndex,CPoint(snakePosition[0].x+1,snakePosition[0].y));
            }
            break;
        case left:
            if(snakePosition[0].x==1)
            {
                snakePosition.insert(headIndex,CPoint(gameWindow.widthWindow-2,snakePosition[0].y));
            }
            else
            {
                snakePosition.insert(headIndex,CPoint(snakePosition[0].x-1,snakePosition[0].y));
            }
            break;

    }
    snakePosition.pop_back();
}

bool Snake::makeFood()
{
    food.x=(rand()%(gameWindow.widthWindow-2))+1;
    food.y=(rand()%(gameWindow.heightWindow-2))+1;
    for(unsigned int i=0; i<snakePosition.size();i++)
    {
        if(snakePosition[i]==food)
        {
            return false;
        }
    }
    return true;
}

void Snake::afterEat()
{
    auto headIndex=snakePosition.begin();
    if(snakePosition[0]==food)
    {
        snakePosition.insert(headIndex,CPoint(food.x,food.y));
        level++;
        while(!makeFood()){}
        if(level%5==0)
        {
            if(level<65)
            {
                timeout(160-level*2);
            }

        }
    }

}

bool Snake::afterCollision()
{
    for(unsigned i=1;i<snakePosition.size();i++)
    {
        if(snakePosition[0]==snakePosition[i])
        {
            return true;
        }
    }
    return false;
}

void Snake::restartGame()
{
    gameWindow.clearWindow();
    snakePosition.clear();
    snakePosition.push_back(CPoint(gameWindow.widthWindow/2,gameWindow.heightWindow/4-1));
    snakePosition.push_back(CPoint(gameWindow.widthWindow/2+1,gameWindow.heightWindow/4-1));
    snakePosition.push_back(CPoint(gameWindow.widthWindow/2+2,gameWindow.heightWindow/4-1));
    if(gameMode==settings || gameMode==settingsColor || gameMode==settingsSize || gameMode==settingsPosition)
    {
        for(int i=3;i<gameWindow.widthWindow/4;i++)
        {
            snakePosition.push_back(CPoint(gameWindow.widthWindow/2+i,gameWindow.heightWindow/4-1));
        }
    }
    level=0;
    dir=left;
    timeout(160);
    while(!makeFood()){}
}

void Snake::gameLoop() {

    do
    {
        gameWindow.printBorder();
        switch (gameMode) {
            case beforeGame:
                gameWindow.printEntryWindow();
                break;
            case settings:
                gameWindow.printSettings();
                break;
            case settingsPosition:
                gameWindow.printSettingsPosition();
                break;
            case settingsSize:
                gameWindow.printSettingsSize();
                break;
            case settingsColor:
                printSnake();
                gameWindow.printSettingsColor();
                break;
            case helpBeforeGame:
                gameWindow.printEntryHelpInfo();
                break;
            case game:
                moveSnake();
                if(afterCollision())
                {
                    gameMode=afterGame;
                }
                afterEat();
                print();
                break;
            case pause:
                print();
                gameWindow.printPause();
                break;
            case help:
                print();
                gameWindow.printEntryHelpInfo();
                break;
            case afterGame:
                gameWindow.printAfterGame(level);
                break;
        }
        refresh();

    }while(handleEvent(gameWindow.getEvent()));
}