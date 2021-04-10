#include "CPoint.h"

class Window {

    private:
        CPoint upperLeftCorner;
        int widthWindow,heightWindow;

    public:
        Window(CPoint& corner, int width,int height);
        ~Window();
        void paint();
};
