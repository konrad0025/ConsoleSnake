#include "CPoint.h"

enum direction{up,down,right,left};

class Window {

        public:
        CPoint upperLeftCorner;
        int widthWindow,heightWindow;

        Window(Window &win);
        Window(CPoint& corner, int width,int height);
        ~Window();
        int getEvent();
        void printBorder();
        void printEntryWindow();
        void printAfterGame(int level);
        void clearWindow();
        void moveWindow(enum direction dir);
};
