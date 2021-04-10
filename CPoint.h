class CPoint {

    private:
        int x,y;

    public:
        CPoint(int x, int y);
        bool operator==(const CPoint &point) const;
        CPoint& operator+=(const CPoint &point);
        friend CPoint operator+(const CPoint &, const CPoint &);
};
