#include <iostream>
#include <cmath>
using namespace std;

class Point
{
    double x_, y_;

public:
    Point() : x_(0), y_(0) {}
    Point(double x, double y) : x_(x), y_(y) {}
    double getX() { return x_; }
    double getY() { return y_; }
    void movePoint(double x, double y)
    {
        x_ = x;
        y_ = y;
    }
    friend ostream &operator<<(ostream &out, Point point);
};

ostream &operator<<(ostream &out, Point point)
{
    out << point.x_ << " " << point.y_ << " ";
    return out;
}

class Shape {
    protected:
        Point centroid;

    public:
        Shape(double x, double y):centroid(x, y){}
        /** Move the centroid of this shape to (x, y) */
        void move(double x, double y){
            centroid.movePoint(x, y);
        }
        /** Return centroid of the shape */
        Point getCentroid(){return centroid;}
        /** Return area of the shape */
        virtual double getArea() = 0;
        virtual void Print() = 0;
};

class Circle : public Shape{
    double radius_;

    public:
        Circle(double x, double y, double r):Shape(x, y), radius_(r){}
        double getArea () override {return radius_ * radius_;}
        void Print() override
            {   
                cout<<"Circle :\n "<<
                "Centroid : " << getCentroid()
                 << "Area : "<< getArea() <<endl;
            }
};

class Triangle : public Shape{
    Point left, right, top;

    public:
        Triangle(double x1, double y1, double x2, double y2, double x3, double y3) : Shape((x1 + x2 + x3) / 3, (y1 + y2 + y3) / 3){
            left.movePoint(x1, y1);
            right.movePoint(x2, y2);
            top.movePoint(x3, y3);
        }

        double getArea() override {
            return  (1.0 / 2 ) * abs(
                (right.getX() - left.getX()) * (top.getY() - left.getY())
                 - (top.getX() - left.getX()) * (right.getY() - left.getY())
                );
        }

        void Print() override
        {
            cout << "Triangle :\n "
                 << "Centroid : " << getCentroid() << "Area : " << getArea() << endl;
        }
};

class Square : public Shape {
    Point left_down, right_up;

    public:
        Square(double x1, double y1, double x2, double y2) : Shape((x1 + x2) / 2, (y1 + y2) / 2){
            left_down.movePoint(x1, y1);
            right_up.movePoint(x2, y2);
        }

        double getArea() override {
            return ( 
                (
                    (right_up.getX() - left_down.getX()) * (right_up.getX() - left_down.getX()) 
                )
                 + ( 
                     right_up.getY() - left_down.getY()) * (right_up.getY() - left_down.getY() 
                    ) 
                 ) / 2;
        }

        void Print() override
        {
            cout << "Square :\n "
                 << "Centroid : " << getCentroid() << "Area : " << getArea() << endl;
        }
};
