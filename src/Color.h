#include <ncurses.h>
#define RED 1
#define GREEN 2
#define BLUE 3
#define YELLOW 4
#define BLACK 5
#define GREY 6
#define WHITE 7
#define BRIGHT_BLUE 8
#define DARK_GREEN 9
#define OLIVE 10

class Color {
    public:
        void static colorInit();
        void static colorOn(int backGroundColor,int fontColor);
        void static colorOff(int backGroundColor,int fontColor);
};
