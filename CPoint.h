class CPoint {

    public:

        int x,y;

        CPoint();
        CPoint(int x, int y);
        bool operator==(const CPoint &point) const;
        CPoint& operator+=(const CPoint &point);

};
