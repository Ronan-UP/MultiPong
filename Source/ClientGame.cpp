#include "ClientGame.h"

using namespace std;

ClientGame::ClientGame(int width, int height, string host, int port) : Game(width, height)
{
    client = new Client(host, port);

}

ClientGame::~ClientGame()
{
    delete client;
}

//Get data from server and draw the result
//Data for three objects needs to be retrieved
int ClientGame::update()
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


    //Point* p2Pos = objects[4]->getPosition();
    string pu = (keys[SDLK_p]? "1" : "0");
    client->writeD("$" + pu + (keys[SDLK_l]? "1" : "0") + "#");
    //delete p2Pos;

    string dat = client->readD();

    if (dat != "")
    {
        GameState* gs = new GameState(dat, 1000);
        setState(gs);
        delete gs;
    }

    return 0;
}