#include <ncurses.h>
#include <string>
#include "CPoint.h"
using namespace std;
class Button {
    public:
        string text;
        CPoint upperLeftCorner;
        int buttonWidth,buttonHeight;
        bool isPointed;

        Button(string text,CPoint corner,int width,int height,bool isPointed);
        void print();
        void newPrint(string textOnButton,bool isPointed1,int y);


};
