#include <ncurses.h>
#include <string>
#include <map>
#include <vector>
#include "CPoint.h"
using namespace std;
class Button {
    public:
        CPoint upperLeftCorner;
        int buttonWidth,buttonHeight;


        Button(CPoint corner,int width,int height);
        void printButton(string textOnButton, bool isPointed, int y);
        void printMap(vector<pair<string,int>> buttonMap, int whichOneIsPointed);
};
