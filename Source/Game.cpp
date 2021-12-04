#include "Game.h"

using namespace std;

Game::Game(int width, int height)
{
    objects = new SolidRectangle*[5];
    playerMov = 7;

    p1 = new Player(true, 15, 70, width, height);
    p2 = new Player(false, 15, 70, width, height);

    ball = new Ball(width / 2, height / 2, 30, width, height);

    SolidRectangle *top = new SolidRectangle(0, 0, width, 10);
    SolidRectangle *bottom = new SolidRectangle(0, height - 10, width, 10);

    numObjects = 5;
    objects = new SolidRectangle *[numObjects];
    objects[0] = ball;
    objects[1] = top;
    objects[2] = bottom;
    objects[3] = p1;
    objects[4] = p2;

    scores[0] = scores[1] = 0;

}

Game::~Game()
{
    for (int i =0;i<numObjects;i++)
        delete objects[i];
    delete [] objects;
}


SolidRectangle** Game::getObjects()
{
    return objects; 
}

int Game::getP1Score()
{
    return scores[0];
}

int Game::getP2Score()
{
    return scores[1];
}

void Game::setState(GameState* gs)
{
    objects[0]->setX(gs->ballPos->x);
    objects[0]->setY(gs->ballPos->y);
    objects[3]->setY(gs->p1Y);
    objects[4]->setY(gs->p2Y);
}