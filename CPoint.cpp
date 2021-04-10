#include "CPoint.h"

CPoint::CPoint(int x, int y): x(x), y(y) {}

bool CPoint::operator==(const CPoint &point) const {
    return (x == point.x && y == point.y);
}

CPoint& CPoint::operator+=(const CPoint &point) {
    x+=point.x;
    y+=point.y;
    return *this;
}

CPoint operator+(const CPoint &point1, const CPoint &point2) {
    return CPoint(point1.x+point2.x, point1.y+point2.y);
}
