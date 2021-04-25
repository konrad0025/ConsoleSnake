#include "Button.h"

Button::Button(CPoint corner, int width, int height): upperLeftCorner(corner),buttonWidth(width),buttonHeight(height) {}

void Button::printButton(string textOnButton, bool isPointed, int y) {
    isPointed ? Color::colorOn(WHITE,BLACK) : Color::colorOn(GREY,BLACK);
    for(int i=0;i<buttonWidth;i++)
    {
        for(int j=0;j<buttonHeight;j++)
        {
            mvprintw(upperLeftCorner.y+j+y,upperLeftCorner.x+i," ");
        }
    }
    mvprintw(upperLeftCorner.y+y,upperLeftCorner.x+(buttonWidth/2)-(textOnButton.size()/2),textOnButton.c_str());
    isPointed ? Color::colorOff(WHITE,BLACK) : Color::colorOff(GREY,BLACK);
}

void Button::printMap(vector<pair<string,int>> vector, int whichOneIsPointed) {
    int i=0;
    for(auto& x: vector)
    {
        (whichOneIsPointed==i)? printButton(x.first,true,x.second):printButton(x.first,false,x.second);
        i++;
    }
}
void Button::setButtonVariables(CPoint corner, int buttonWidth, int buttonHeight) {
    this->upperLeftCorner=corner;
    this->buttonHeight=buttonHeight;
    this->buttonWidth=buttonWidth;
}