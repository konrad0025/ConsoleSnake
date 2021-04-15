#include "Button.h"

Button::Button(string text, CPoint corner, int width, int height,bool isPointed): text(text),upperLeftCorner(corner),buttonWidth(width),buttonHeight(height),isPointed(isPointed) {}

void Button::print() {
    init_color(COLOR_WHITE,500,500,500);
    init_color(11,1000,1000,1000);
    init_pair(3, COLOR_BLACK, COLOR_WHITE);
    init_pair(7, COLOR_BLACK, 11);

    isPointed ? attron(COLOR_PAIR(7)) : attron(COLOR_PAIR(3));
    for(int i=0;i<buttonWidth;i++)
    {
        for(int j=0;j<buttonHeight;j++)
        {
            mvprintw(upperLeftCorner.y+j,upperLeftCorner.x+i," ");
        }
    }
    mvprintw(upperLeftCorner.y,upperLeftCorner.x+(buttonWidth/2)-(text.size()/2),text.c_str());
    isPointed ? attroff(COLOR_PAIR(7)) : attroff(COLOR_PAIR(3));
}
