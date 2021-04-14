#include "Button.h"

Button::Button(string text, CPoint corner, int width, int height,bool isPointed): text(text),upperLeftCorner(corner),buttonWidth(width),buttonHeight(height),isPointed(isPointed) {
    button=newwin(height,width,corner.y,corner.x);
}

void Button::paint() {
    init_color(COLOR_GREEN,0,300,0);
    init_pair(1, COLOR_YELLOW, COLOR_GREEN);
    init_pair(2, COLOR_YELLOW, 10);
    box(button,0,0);
    isPointed ? attron(COLOR_PAIR(1)) : attron(COLOR_PAIR(2));
    mvwprintw(button,buttonHeight/2,(buttonWidth/2)-(text.size()/2),text.c_str());
    isPointed ? attroff(COLOR_PAIR(1)) : attroff(COLOR_PAIR(2));
}
