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

Point* Rectangle::getLBound()
{
    return new Point(position->x, position->y);
}

Point* Rectangle::getRBound()
{
    return new Point(position->x + width, position->y);
}

Point* Rectangle::getTBound()
{
    return new Point(position->x, position->y);
}

Point* Rectangle::getBBound()
{
   return new Point(position->x, position->y + height);
}
