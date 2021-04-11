#include "Snake.h"
Snake::Snake(Window &win): gameWindow(win),dir(left),level(0),gameMode(beforeGame) {

    snakePosition.push_back(CPoint(10,10));
    snakePosition.push_back(CPoint(11,10));
    snakePosition.push_back(CPoint(12,10));
    while(!makeFood()){}
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
    for(unsigned int i=0; i<snakePosition.size();i++)
    {
        if(i==0)
        {
            attron(COLOR_PAIR(1));
            mvaddch(gameWindow.upperLeftCorner.y+snakePosition[i].y,gameWindow.upperLeftCorner.x+snakePosition[i].x,' ');
            attroff(COLOR_PAIR(1));
        }
        else
        {
            attron(COLOR_PAIR(2));
            mvaddch(gameWindow.upperLeftCorner.y+snakePosition[i].y,gameWindow.upperLeftCorner.x+snakePosition[i].x,' ');
            attroff(COLOR_PAIR(2));
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
void Snake::printPause() {
    int y=5+gameWindow.upperLeftCorner.y,x=gameWindow.upperLeftCorner.x+3;
    mvprintw(++y,x,"Press-'p' to get back to the game");
    mvprintw(++y,x,"Press-'r' to start the game");
}


bool Snake::handleEvent(int key) {

    switch (gameMode){
        case beforeGame:
            return handleEventDuringBeforeGameMode(key);
        case game:
            return handleEventDuringGameMode(key);
        case afterGame:
            return handleEventDuringAfterGameMode(key);
        case pause:
            return handleEventDuringPauseMode(key);
    };
    return false;
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
        case 'p':
            gameMode=pause;
            return true;
    };
    return false;
}

bool Snake::handleEventDuringBeforeGameMode(int key) {
    switch(key){
        case 'r':
            gameMode=game;
            return true;
    };
    return false;
}

bool Snake::handleEventDuringAfterGameMode(int key) {
    switch(key){
        case 'r':
            gameMode=game;
            restartGame();
            return true;
    };
    return false;
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
    };
    return false;
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
            if(level<75)
            {
                timeout(200-level*2);
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
    snakePosition.clear();
    snakePosition.push_back(CPoint(10,10));
    snakePosition.push_back(CPoint(11,10));
    snakePosition.push_back(CPoint(12,10));
    level=0;
    dir=left;
    timeout(200);
    while(!makeFood()){}
}

void Snake::gameLoop() {

    while(true)
    {
        handleEvent(gameWindow.getEvent());
        gameWindow.printBorder();
        switch (gameMode) {
            case beforeGame:
                gameWindow.printEntryWindow();
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
                printPause();
                break;
            case afterGame:
                gameWindow.printAfterGame(level);
                break;
            default:
                goto label;
        }

        refresh();
    }
    label:
    return;
}