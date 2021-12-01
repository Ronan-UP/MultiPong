#include "Ball.h"

using namespace std;

Ball::Ball(int x, int y, int r, double a, double vel, int width, int height) : SolidRectangle(x, y, r/2, r/2)
{
    angle = a;
    velocity = vel;

    winWidth = width;
    winHeight = height;
    objects = new SolidRectangle*[4];
    for (int i =0;i<4;i++)
    {
        objects[i] = nullptr;
    }
}

void Ball::bindObject(SolidRectangle* r)
{
    for (int i =0;i<4;i++)
    {
        if (!objects[i])
        {
            objects[i] = r;
            break;
        }
    }
}

double Ball::getAngle()
{
    return angle;
}

void Ball::setAngle(double a)
{
    angle = a;
}

void Ball::update()
{

    //Collision detection
    //Works on the assumption that p1 is left, p2 is right


    for (int i =0;i<4 && objects[i];i++)
    {
        angle = objects[i]->collide(this, angle);
    }
  
  /*  Point* pos = image->getPosition();

    Point* left = image->getLBound();

    if (p1->collides(left)) //Hit left paddle
    {
        angle = 3*M_PI - angle;
    }
    else
    {
        Point* right = image->getRBound();
        if (p2->collides(right)) //Hit right paddle
        {
            angle = M_PI - angle;
        }
        else
        {
            Point* b = image->getBBound();
            Point* t = image->getTBound();
            if (b->y > winHeight) //Hit bottom of screen
            {
                angle = -1*angle;
            }
            else if (t->y < 0) //Hit top of screen
            {
                angle = 2*M_PI - angle;
            }

            delete b;
            delete t;
        }
        delete right;
    }
    delete left; */

    //Player2 gets a point
    if (getPosition()->x<0)
        throw 2;
    //Player1 gets a point
    if (getPosition()->x>winWidth)
        throw 1;


    changePosition(velocity*cos(angle), velocity*sin(angle));
}
