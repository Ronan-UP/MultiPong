//This class is used to represent rectangle shapes
#ifndef RECT_H
#define RECT_H

#include "Shape.h"
#include <cmath>

//A rectangle with colission
class SolidRectangle : public Shape
{
    private:
        int width;
        int height;

    public:
        //The position corresponds to the top left corner
        SolidRectangle(int x, int y, int w, int h) : Shape(x, y)
        {
                width = w;
                height = h;
        };
        bool contains(Point*);

        //Collide the ball with the object
        virtual double collide(SolidRectangle* ball, double angle);

        int getWidth();
        int getHeight();

        double getCentreY();

        Point* getLBound();
        Point* getRBound();
        Point* getTBound();
        Point* getBBound();

};


#endif