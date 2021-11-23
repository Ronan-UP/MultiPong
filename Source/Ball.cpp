#include "Ball.h"

using namespace std;

Ball::Ball(int x, int y, int r, double a, double vel)
{
    image = new Circle(x, y, r);
    angle = a;
    velocity = vel;
}

Circle* Ball::getImage()
{
    return image;
}