#include <ncurses.h>
#include "Button.h"
enum direction{up,down,right,left};

class Window {

        public:
        CPoint upperLeftCorner;
        int widthWindow,heightWindow;
        Button buttonHelp,buttonStart,buttonExit;

        Window(Window &win);
        Window(CPoint& corner, int width,int height);
        ~Window();
        int getEvent();
        void printBorder();
        void printEntryWindow();
        void printAfterGame(int level);
        void printEntryHelpInfo();
        void clearWindow();
        void moveWindow(enum direction dir);
        void changePointedButton(enum direction dir);


};
