#include "CPoint.h"

CPoint::CPoint() {x=0; y=0;}

CPoint::CPoint(int x, int y ): x(x), y(y) {}

CPoint::CPoint(CPoint &point) {
    x=point.x;
    y=point.y;
}

CPoint & CPoint::operator=(const CPoint& point)
{
    x=point.x;
    y=point.y;
    return *this;
}

bool CPoint::operator==(const CPoint &point) const {
    return (x == point.x && y == point.y);
}

CPoint& CPoint::operator+=(const CPoint &point) {
    x+=point.x;
    y+=point.y;
    return *this;
}

CPoint operator+(const CPoint& point1, const CPoint& point2) {
    CPoint point(point1.x+point2.x,point1.y+point2.y);
    return point;
}