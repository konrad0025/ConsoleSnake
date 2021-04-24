#include <ncurses.h>
#define RED 0
#define GREEN 1
#define BLUE 2
#define YELLOW 3
#define BLACK 4
#define GREY 5
#define WHITE 6
#define BRIGHT_BLUE 7
#define DARK_GREEN 8
#define OLIVE 9

class Color {
    void static colorInit();
    void static colorOn(int backGroundColor,int fontColor);
    void static colorOff(int backGroundColor,int fontColor);

};
