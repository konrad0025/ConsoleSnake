#include "CPoint.h"

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
};
