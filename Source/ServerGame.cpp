#include "ServerGame.h"

using namespace std;

ServerGame::ServerGame(int width, int height, int port) : Game(width, height)
{
   server = new Server(port);

    for (int i = 1; i < numObjects; i++)
    {
        ball->bindObject(objects[i]);
    }

    p2up = p2down = false;
    server->startListen();
}

ServerGame::~ServerGame()
{
    delete server;
}

//Update game objects, get, send data and draw
int ServerGame::update()
{
    while (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
            case SDL_QUIT:
            {
                return -1;
                break;
            }
            case SDL_KEYDOWN:
            {
                keys[event.key.keysym.sym] = true;
                break;
            }
            case SDL_KEYUP:
            {
                keys[event.key.keysym.sym] = false;
                break;
            }
        }
    }

    if (keys[SDLK_w])
            p1->changeVertPos(-playerMov);
    if (keys[SDLK_s])
            p1->changeVertPos(playerMov);



    string dat = server->readData();
    if (dat != "")
    {
            int i =0;
            for (i=0;i<5 && dat[i] != '$';i++) //Get to start of data
            {}
            p2up = (dat[1] == '1');
            p2down = (dat[2] == '1');
    }


    if (p2up)
            p2->changeVertPos(-playerMov);
    if (p2down)
    {
            p2->changeVertPos(playerMov);
    }

    try
    {
        ball->update();
    }
    catch (int s)
    {
        scores[s]++;
        ball->reset();

        if (scores[0] >=10)
            throw "Player 1 wins!";
        
        if (scores[1] >=10)
            throw "Player 2 wins!";
    }

    Point* bPos = objects[0]->getPosition();
    Point* p1Pos = objects[3]->getPosition();
    Point* p2Pos = objects[4]->getPosition();
    string state = "$" + to_string(bPos->x) + "#" + to_string(bPos->y) + "#" + to_string(p1Pos->y) + "#" + to_string(p2Pos->y) + "#";
    server->writeData(state);

    return 0;
}