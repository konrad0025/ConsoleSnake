#include "Button.h"

Button::Button(string text, CPoint corner, int width, int height,bool isPointed): text(text),upperLeftCorner(corner),buttonWidth(width),buttonHeight(height),isPointed(isPointed) {}

void Button::paint() {
    init_color(COLOR_GREEN,0,300,0);
    init_pair(1, COLOR_BLACK, COLOR_GREEN);
    init_pair(2, COLOR_BLACK, 10);

    isPointed ? attron(COLOR_PAIR(1)) : attron(COLOR_PAIR(2));
    for(int i=0;i<buttonWidth;i++)
    {
        mvprintw(upperLeftCorner.y,upperLeftCorner.x+i," ");
    }
    mvprintw(upperLeftCorner.y,upperLeftCorner.x+(buttonWidth/2)-(text.size()/2),text.c_str());
    isPointed ? attroff(COLOR_PAIR(1)) : attroff(COLOR_PAIR(2));
}
