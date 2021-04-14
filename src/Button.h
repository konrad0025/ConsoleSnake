#include <ncurses.h>
#include <string>
#include "CPoint.h"
using namespace std;
class Button {

    string text;
    CPoint upperLeftCorner;
    int buttonWidth,buttonHeight;
    bool isPointed;
    WINDOW *button;

    Button(string text,CPoint corner,int width,int height,bool isPointed);
    void paint();

};
