#include "Button.h"

Button::Button(CPoint corner, int width, int height): upperLeftCorner(corner),buttonWidth(width),buttonHeight(height) {}

void Button::printButton(string textOnButton, bool isPointed, int y) {
    init_color(COLOR_WHITE,500,500,500);
    init_color(11,1000,1000,1000);
    init_pair(3, COLOR_BLACK, COLOR_WHITE);
    init_pair(7, COLOR_BLACK, 11);

    isPointed ? attron(COLOR_PAIR(7)) : attron(COLOR_PAIR(3));
    for(int i=0;i<buttonWidth;i++)
    {
        for(int j=0;j<buttonHeight;j++)
        {
            mvprintw(upperLeftCorner.y+j+y,upperLeftCorner.x+i," ");
        }
    }
    mvprintw(upperLeftCorner.y+y,upperLeftCorner.x+(buttonWidth/2)-(textOnButton.size()/2),textOnButton.c_str());
    isPointed ? attroff(COLOR_PAIR(7)) : attroff(COLOR_PAIR(3));
}

void Button::printMap(map<string, int> buttonMap, int whichOneIsPointed) {
    for(auto& x: buttonMap)
    {
        (x.second==(whichOneIsPointed*2+1))? printButton(x.first,true,x.second):printButton(x.first,false,x.second);
    }
}