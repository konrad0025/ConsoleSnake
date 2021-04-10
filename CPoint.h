class CPoint {

    public:

        int x,y;

        CPoint();
        CPoint(CPoint &point);
        CPoint(int x, int y);
        CPoint& operator=(const CPoint& point);
        bool operator==(const CPoint &point) const;
        CPoint& operator+=(const CPoint &point);
        friend CPoint operator+(const CPoint&,const CPoint&);

};
