//This class represents the ball used in the game

#ifndef BALL_H
#define BALL_H

#include "Circle.h"
#include "Player.h"
#include <cmath>

using namespace std;

class Ball : public SolidRectangle
{
    private:
        double angle;
        double velocity;
        int winWidth;
        int winHeight;

        bool serving;
        SolidRectangle** objects;

    public:
        Ball(int x, int y, int r, int width, int height);
        ~Ball();

        void bindObject(SolidRectangle* r);

        ///Let the ball move in its current direction
        void update();
        double getAngle();
        void setAngle(double a);
        void setVelocity(double v);
        void reset();

};

#endif