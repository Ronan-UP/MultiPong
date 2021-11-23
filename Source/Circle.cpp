#include "Circle.h"


//Uses a square hitbox rather than a true circle
bool Circle::contains(Point* p)
{
    return (p->x>=(position->x-radius) && p->x<=(position->x+radius) && p->y>=(position->y-radius) && p->y<=(position->y+radius));
}

int Circle::getRadius()
{
    return radius;
}