#include <ncurses.h>
#include "Button.h"
enum direction{up,down,right,left};

class Window {

        public:
        CPoint upperLeftCorner;
        int widthWindow,heightWindow;
        Button buttonHelp,buttonStart,buttonBack,buttonExit;
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
        void clearWindow();
        void moveWindow(enum direction dir);
        void changePointedButton(enum direction dir);


};
