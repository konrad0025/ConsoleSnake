#include <ncurses.h>
#include <string>
#include <map>
#include <vector>
#include "Button.h"
using namespace std;
enum direction{up,down,right,left};

class Window {

        public:
        CPoint upperLeftCorner;
        int widthWindow,heightWindow;
        int iColor;
        bool iColorSide;
        Button button;
        vector<pair<string,int>> menuButtons;
        vector<pair<string,int>> afterGameButtons;
        vector<pair<string,int>> settingsButtons;
        int whichOneInMenuIsPointed,whichOneInAfterGameIsPointed,whichOneInSettingsIsPointed;

        Window(Window &win);
        Window(CPoint& corner, int width,int height);
        ~Window();
        int getEvent();
        void printBorder();
        void printEntryWindow();
        void printSettings();
        void printAfterGame(int level);
        void printEntryHelpInfo();
        void printPause();
        void printBackgroundForText(int width, int height, int y);
        void clearWindow();
        void moveWindow(enum direction dir);
        void changeWhichButtonIsPointed(enum direction dir, const vector<pair<string,int>> &mapButton, int &whichOneIsPointed);

};
