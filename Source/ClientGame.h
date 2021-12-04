#ifndef CLIENT_G
#define CLIENT_G

#include "Game.h"
#include "Client.h"

using namespace std;

//This class is used to model the game from the perspective of a client

class ClientGame : public Game
{
    private:
        Client* client;

    public:
        ClientGame(int width, int height, string host, int port);
        ~ClientGame();
        int update();
};

#endif