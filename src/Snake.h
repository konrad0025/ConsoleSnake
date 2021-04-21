#include <ncurses.h>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "Window.h"
#include <cstring>

using namespace std;

enum mode{beforeGame,helpBeforeGame,settings,game,afterGame,help,pause};

class Snake {
    private:
        vector<CPoint> snakePosition;
        Window gameWindow;
        enum direction dir;
        CPoint food;
        int level;
        enum mode gameMode;
    public:
        Snake(Window &win);

        void print();
        void printSnake();
        void printFood();
        void printLevelInfo();
        void moveSnake();
        bool handleEvent(int key);
        bool handleEventDuringGameMode(int key);
        bool handleEventDuringBeforeGameMode(int key);
        bool handleEventDuringSettingsMode(int key);
        bool handleEventDuringHelpBeforeGameMode(int key);
        bool handleEventDuringAfterGameMode(int key);
        bool handleEventDuringPauseMode(int key);
        bool handleEventDuringHelpMode(int key);
        bool makeFood();
        void afterEat();
        bool afterCollision();
        void restartGame();
        void gameLoop();


};