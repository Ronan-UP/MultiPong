#include "Ball.h"

using namespace std;

Ball::Ball(int x, int y, int r, double a, int width, int height) : SolidRectangle(x, y, r/2, r/2)
{
    angle = a;

    winWidth = width;
    winHeight = height;
    objects = new SolidRectangle*[4];
    for (int i =0;i<4;i++)
    {
        objects[i] = nullptr;
    }

    reset();
}

Ball::~Ball()
{
    delete [] objects;
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

//Reset the ball to a serving state
void Ball::reset()
{
    serving = true;
    double dir = rand()/(double)RAND_MAX;
    angle = 0;

    if (dir<0.5)
        angle = M_PI;

    setX(winWidth/2);
    setY(winHeight/2);
    velocity = 3;
    
}

void Ball::setVelocity(double v)
{  
    velocity = v;
}

void Ball::update()
{

    //Collision detection
    //Works on the assumption that p1 is left, p2 is right


    double aB = angle;
    for (int i =0;i<4 && objects[i];i++)
    {
        angle = objects[i]->collide(this, angle);
    }
  
    if (serving && aB != angle) //Hit a paddle, since it can't hit a wall. First hit, change velocity
    {
        velocity = 9;
        serving = false;
    }

    //Player2 gets a point
    if (position->x<0)
        throw 1;
    //Player1 gets a point
    if (position->x>winWidth)
        throw 0;


    changePosition(velocity*cos(angle), velocity*sin(angle));
}


