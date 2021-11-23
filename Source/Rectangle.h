//This class is used to represent rectangle shapes

#include "Shape.h"

class Rectangle : private Shape
{
    private:
        int width;
        int height;

    public:
        Rectangle(int w, int h);
        bool contains(Point*);

};