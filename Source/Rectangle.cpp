#include "Rectangle.h"

using namespace std;

bool Rectangle::contains(Point* p)
{
    return (p->x>=position->x && p->x<=position->x+width && p->y>=position->y && p->y<=position->y+height);
}

int Rectangle::getHeight()
{
    return height;
}

int Rectangle::getWidth()
{
    return width;
}
