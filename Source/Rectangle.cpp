#include "Rectangle.h"

using namespace std;

bool SolidRectangle::contains(Point* p)
{
    return (p->x>=position->x && p->x<=position->x+width && p->y>=position->y && p->y<=position->y+height);
}

int SolidRectangle::getHeight()
{
    return height;
}

int SolidRectangle::getWidth()
{
    return width;
}

Point* SolidRectangle::getLBound()
{
    return new Point(position->x, position->y);
}

Point* SolidRectangle::getRBound()
{
    return new Point(position->x + width, position->y);
}

Point* SolidRectangle::getTBound()
{
    return new Point(position->x, position->y);
}

Point* SolidRectangle::getBBound()
{
   return new Point(position->x, position->y + height);
}

double SolidRectangle::getCentreY()
{
    return position->y + ((double)height)/2;
}

//Normal collision for a rectangle (non-player). Does not include left/right collision for normal rectangles.
//This is somewhat inefficient, can be improved.
double SolidRectangle::collide(SolidRectangle* ball, double angle)
{

    //Only accepts one collision at a time

    double retAngle = angle;
    Point* ballL = ball->getLBound();
    Point* ballR = ball->getRBound();
    Point* ballB = ball->getBBound();
    Point* ballT = ball->getTBound();

    Point* t = getTBound();
    Point* b = getBBound();
    Point* l = getLBound();
    Point* r = getRBound();

    if (ballT->y < b->y && ballB->y > b->y) //Top of ball collides with bottom of rect
    {
        retAngle = 2*M_PI - angle;
    }
    else if (ballB->y > t->y && ballT->y < t->y) //Bottom of ball collides with top of rect
    {
        retAngle = -1*angle;
    }


    delete t;
    delete b;
    delete l;
    delete r;
    delete ballB;
    delete ballR;
    delete ballL;
    delete ballT;

    return retAngle;

}
