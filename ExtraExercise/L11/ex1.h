class Point{
    public: 
    Point(const double x, const double y, const double z);
    void mutateValue(const double x, const double y, const double z);
    double getX(){return x_;}
    double getY(){return y_;}
    double getZ(){return z_;}
    friend Point operator+(Point a, Point b);

    private: 
    double x_, y_, z_;
};

double distance(const Point a, const Point b);
double innerProduct(Point a, Point b);
Point operator + (Point a, Point b);