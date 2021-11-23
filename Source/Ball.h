//This class represents the ball used in the game

#ifndef BALL_H
#define BALL_H

#include "Circle.h"
#include "Player.h"
#include <cmath>

using namespace std;

class Ball
{
    private:
        Circle* image;
        double angle;
        double velocity;
        int winWidth;
        int winHeight;

        Player* p1;
        Player* p2;

    public:
        Ball(int x, int y, int r, double a, double vel, int width, int height);
        Circle* getImage();

        void bindPlayers(Player* pl1, Player* pl2);

        ///Let the ball move in its current direction
        void update();

};

#endif