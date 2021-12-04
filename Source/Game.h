#ifndef GAME_H
#define GAME_H

#include <cmath>
#include "Display.h"
#include <map>
#include <chrono>

#include "Player.h"
#include "Ball.h"
//#include <iostream>

using namespace std;

//The gamestate holds position data for the three main objects
struct GameState
{
    GameState(string data, int length) //Generate from text
    {
        double ballX;
        double ballY;

        string text = "";
        int i =0;
        for (i =0;i<length && data[i] != '$';i++) {}//Go to start of structure

        for (i++;i<length && data[i] != '#';i++)
        {
            text += data[i];
        }
        ballX = stod(text);

        for (i++, text = "";i<length && data[i] != '#';i++)
        {
            text += data[i];
        }
        ballY = stod(text);
        ballPos = new Point(ballX, ballY);

        for (i++, text = "";i<length && data[i] != '#';i++)
        {
            text += data[i];
        }
        p1Y = stod(text);

        for (i++, text = "";i<length && data[i] != '#';i++)
        {
            text += data[i];
        }
        p2Y = stod(text);
    }
    ~GameState()
    {
        delete ballPos;
    }
    Point* ballPos;
    double p1Y; //Only Y coords for the players, since the x is constant
    double p2Y;
};

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
        void setState(GameState* gs);

    public:
        Game(int width, int height);
        ~Game();
        virtual int update() = 0;
        SolidRectangle** getObjects();
        int getP1Score();
        int getP2Score();
        

};

#endif