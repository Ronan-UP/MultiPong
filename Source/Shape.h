#ifndef SHAPE_H
#define SHAPE_H

using namespace std;


struct Point
{
    Point(int nx, int ny)
    {
        x = nx;
        y = ny;
    }
    double x;
    double y;
};

class Shape
{

    protected:
        Point* position;

    public:
        Shape(int nx, int ny);
        ~Shape();

        void changePosition(double x, double y);
        void setX(double x);
        void setY(double y);
        Point* getPosition();
        virtual bool contains(Point*) =0;

        ///Get the bounds of the shape
        virtual Point* getLBound() =0;
        virtual Point* getRBound() =0;
        virtual Point* getTBound() =0;
        virtual Point* getBBound() =0;

};


#endif