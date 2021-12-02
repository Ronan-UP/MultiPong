#include "Player.h"
#include <iostream>

using namespace std;


//The margin between the player rectangle and the edge of the screen
const int margin = 20;
Player::Player(bool p1, double w, double h, int ww, int wh) : SolidRectangle(p1 ? (margin) : (ww-margin - w), wh/2, w, h)
{
    int x = 0;
    int y = wh/2;

    winHeight = wh;
    winWidth = ww;
}

//Move the player up or down, no farther than the boundaries of the screen
void Player::changeVertPos(double d)
{ 
  if (position->y + d<0)
    changePosition(0, (-position->y));
  else if (position->y + d + getHeight() > winHeight)
    changePosition(0, winHeight - getHeight() - position->y);
  else
    changePosition(0, (d));

}

double Player::collide(SolidRectangle* ball, double angle)
{

    double retAngle = angle;
    Point* ballL = ball->getLBound();
    Point* ballR = ball->getRBound();
    Point* ballB = ball->getBBound();
    Point* ballT = ball->getTBound();

    Point* t = getTBound();
    Point* b = getBBound();
    Point* l = getLBound();
    Point* r = getRBound();

    //Relative vertical distance

   if (ballL->x < r->x && ballR->x > r->x && ((ballB->y > t->y && ballT->y < b->y) || (ballT->y < b->y && ballB->y > b->y)) ) //Collision on the right
    {
        double rel = (ball->getCentreY() - getCentreY())/(double)getHeight();
        retAngle = rel*M_PI/3;
    }
   else if (ballR->x >= l->x && ballL->x < l->x && ((ballB->y > t->y && ballT->y < b->y) || (ballT->y < b->y && ballB->y > b->y)) ) //Collision on the left
    {
      double rel = -(ball->getCentreY() - getCentreY())/(double)getHeight();
        retAngle = rel*M_PI/3+ M_PI;
    }

  return retAngle;

}
