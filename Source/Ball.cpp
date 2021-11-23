#include "Ball.h"

using namespace std;

Ball::Ball(int x, int y, int r, double a, double vel, int width, int height)
{
    image = new Circle(x, y, r);
    angle = a;
    velocity = vel;

    winWidth = width;
    winHeight = height;
    p1 = p2 = 0;
}

void Ball::bindPlayers(Player* pl1, Player* pl2)
{
    p1 = pl1;
    p2 = pl2;
}

Circle* Ball::getImage()
{
    return image;
}

void Ball::update()
{

    //Collision detection
    //Works on the assumption that p1 is left, p2 is right
    Point* pos = image->getPosition();

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
    delete left;

    //Player2 gets a point
    if (image->getPosition()->x<0)
        throw 2;
    //Player1 gets a point
    if (image->getPosition()->x>winWidth)
        throw 1;


    image->changePosition(velocity*cos(angle), velocity*sin(angle));
}
