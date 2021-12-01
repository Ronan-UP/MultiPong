//This class represents a player


#ifndef PLAYER_H
#define PLAYER_H

#include "Rectangle.h"

using namespace std;

class Player : public SolidRectangle
{
    private:
        int winWidth;
        int winHeight;

    public:

        //Should change height/width to be in range [0,1]
        Player(bool p1, double w, double h, int ww, int wh);

        void changeVertPos(double d);
        double collide(SolidRectangle* ball, double angle);


};

#endif