#ifndef SERV_G
#define SERV_G

#include "Game.h"
#include "Server.h"

using namespace std;

//This class represents the game from the perspective of a server

class ServerGame : public Game
{
    private:

    public:
        ServerGame(int width, int height, int port);
        int update();

};

#endif