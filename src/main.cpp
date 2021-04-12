#include <stdlib.h>
#include "Snake.h"
using namespace std;

int main() {
    srand(time(0));
    CPoint p(5,2);
    Window t(p,40,20);
    Snake test(t);
    test.gameLoop();
    return 0;
}
