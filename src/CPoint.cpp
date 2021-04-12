#include "CPoint.h"

CPoint::CPoint() {x=0; y=0;}

CPoint::CPoint(int x, int y ): x(x), y(y) {}

bool CPoint::operator==(const CPoint &point) const {
    return (x == point.x && y == point.y);
}

CPoint& CPoint::operator+=(const CPoint &point) {
    x+=point.x;
    y+=point.y;
    return *this;
}