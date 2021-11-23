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
    int x;
    int y;
};

class Shape
{

    protected:
        Point* position;

    public:
        Shape(int nx, int ny);
        ~Shape();

        void changePosition(int x, int y);
        void setX(int x);
        void setY(int y);
        Point* getPosition();
        virtual bool contains(Point*) =0;
};


#endif