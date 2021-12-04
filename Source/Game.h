#ifndef GAME_H
#define GAME_H

#include <cmath>
#include "Display.h"
#include <map>
#include <chrono>

#include "Player.h"
#include "Ball.h"

using namespace std;

//This class represents a running game
class Game
{
    protected:
        SolidRectangle** objects;
        int numObjects;
        Player* p1;
        Player* p2;
        Ball* ball;
        int scores[2];
        double playerMov;

    public:
        Game(int width, int height);
        ~Game();
        virtual int update() = 0;
        SolidRectangle** getObjects();
        int getP1Score();
        int getP2Score();
        

};

#endif