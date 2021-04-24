#include "Color.h"

void Color::colorInit() {
    init_extended_color(RED,1000,0,0);
    init_extended_color(DARK_GREEN,0,300,0);
    init_extended_color(GREEN,0,1000,0);
    init_extended_color(BRIGHT_BLUE,100,200,1000);
    init_extended_color(BLUE,0,500,0);
    init_extended_color(BRIGHT_BLUE,100,200,1000);
    init_extended_color(GREY,500,500,500);
    init_extended_color(WHITE,1000,1000,1000);
    init_extended_color(OLIVE,300,300,0);
    init_extended_color(YELLOW,900,900,0);
}
void Color::colorOn(int backGroundColor,int fontColor) {
    int colorNum=(0 | (1<<backGroundColor))|(1<<(31-fontColor));
    init_extended_pair(colorNum, fontColor, backGroundColor);
    attron(colorNum);
}
void Color::colorOff(int backGroundColor, int fontColor) {
    attroff((0 | (1<<backGroundColor))|(1<<(31-fontColor)));
}