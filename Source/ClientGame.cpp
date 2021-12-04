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
    Point* p2Pos = objects[4]->getPosition();
    client->writeD("$" + to_string(p2Pos->y) + "#");
    delete p2Pos;

    char* dat = client->readD();
    if (dat)
    {
        GameState* gs = new GameState(dat, 100);
        setState(gs);
        delete gs;
    }
}