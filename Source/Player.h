//This class represents a player


#ifndef PLAYER_H
#define PLAYER_H

#include "Rectangle.h"

using namespace std;

class Player
{
    private:
        Rectangle* image;
        int winWidth;
        int winHeight;

    public:
        Player(bool p1, int w, int h, int ww, int wh);

        ///Move up by a specified number
        void moveUp(int);
        ///Move down by a specified number
        void moveDown(int);
        ///Get the rectangle data associated with a player
        Rectangle* getImage();

        bool collides(Point* p)
        {
            return image->contains(p);
        }


};

#endif