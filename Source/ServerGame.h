#ifndef SERV_G
#define SERV_G

#include "Game.h"
#include "Server.h"

using namespace std;

//This class represents the game from the perspective of a server

class ServerGame : public Game
{
    private:
        Server* server;
        SDL_Event event;
        map<int, bool> keys;
        bool p2up, p2down;

    public:
        ServerGame(int width, int height, int port);
        ~ServerGame();
        int update();
        bool tryConnection();

};

#endif