#include <ncurses.h>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "Window.h"
#include <string.h>

using namespace std;

enum direction{up,down,right,left};
enum mode{beforeGame,game,afterGame,help,pause};
class Snake {
    public:
        vector<CPoint> snakePosition;
        Window gameWindow;
        enum direction dir;
        CPoint food;
        int level;
        enum mode gameMode;

        Snake(Window &win);

        void print();
        void printSnake();
        void printFood();
        void printLevelInfo();
        void moveSnake();
        bool handleEvent(int key);
        bool handleEventDuringGameMode(int key);
        bool handleEventDuringBeforeGameMode(int key);
        bool handleEventDuringAfterGameMode(int key);
        bool handleEventDuringPauseMode(int key);
        bool makeFood();
        void afterEat();
        bool afterCollision();
        void restartGame();
        void gameLoop();


};