#include <ncurses.h>
#include <string>
#include "Button.h"
using namespace std;
enum direction{up,down,right,left};

class Window {

        public:
        CPoint upperLeftCorner;
        int widthWindow,heightWindow;
        Button buttonHelp,buttonStart,buttonBack,buttonExit,buttonRestartAfterGame,buttonMenuAfterGame,buttonExitAfterGame;
        int iColor;
        bool iColorSide;

        Window(Window &win);
        Window(CPoint& corner, int width,int height);
        ~Window();
        int getEvent();
        void printBorder();
        void printEntryWindow();
        void printAfterGame(int level);
        void printEntryHelpInfo();
        void printPause();
        void printBackgroundForText(int width, int height, int y);
        void clearWindow();
        void moveWindow(enum direction dir);
        void changePointedButtonBeforeGame(enum direction dir);
        void changePointedButtonAfterGame(enum direction dir);

};
