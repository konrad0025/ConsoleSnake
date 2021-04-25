#include "Color.h"

void Color::colorInit() {
    init_color(RED,1000,0,0);
    init_color(DARK_GREEN,0,300,0);
    init_color(GREEN,0,1000,0);
    init_color(BRIGHT_BLUE,100,200,1000);
    init_color(BLUE,0,0,500);
    init_color(BLACK,0,0,0);
    init_color(GREY,500,500,500);
    init_color(WHITE,1000,1000,1000);
    init_color(OLIVE,300,300,0);
    init_color(YELLOW,900,900,0);
}
void Color::colorOn(int backGroundColor, int fontColor) {
    short pairNum=backGroundColor*fontColor+(backGroundColor-fontColor);
    init_pair(pairNum, fontColor, backGroundColor);
    attron(COLOR_PAIR(pairNum));
}
void Color::colorOff(int backGroundColor, int fontColor) {
    attroff(backGroundColor*fontColor+(backGroundColor-fontColor));
}
