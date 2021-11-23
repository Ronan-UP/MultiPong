//This class is used to represent rectangle shapes
#ifndef RECT_H
#define RECT_H

#include "Shape.h"

class Rectangle : public Shape
{
    private:
        int width;
        int height;

    public:
        //The position corresponds to the top left corner
        Rectangle(int x, int y, int w, int h) : Shape(x, y)
        {
                width = w;
                height = h;
        };
        bool contains(Point*);

        int getWidth();
        int getHeight();

        Point* getLBound();
        Point* getRBound();
        Point* getTBound();
        Point* getBBound();

};


#endif