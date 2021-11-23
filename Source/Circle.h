#ifndef CIRCLE_H
#define CIRCLE_H

#include "Shape.h"

class Circle : public Shape
{
    private:
        int radius;
    public:
    Circle(int x, int y, int r) : Shape(x, y)
        {
                radius = r;
        };

    bool contains(Point* p);

    int getRadius();

    Point* getLBound();
    Point* getRBound();
    Point* getTBound();
    Point* getBBound();

};

#endif