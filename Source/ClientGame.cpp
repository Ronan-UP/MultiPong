#include "ClientGame.h"

using namespace std;

ClientGame::ClientGame(int width, int height, string host, int port) : Game(width, height)
{
    client = new Client(host, port);
    prevPos = 0;
    lastState = "$00#";

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
    string send = "$" + pu + (keys[SDLK_l]? "1" : "0") + "#";
    if (!(lastState != "$00#" && send != lastState)) //Only send data if necessary
    {
        client->writeD(send);
    }
    lastState = send;

    string dat = client->readD();

    if (dat != "")
    {
        int count = 0;
        for (int i=0;i<dat.length();i++)    
        {
            if (dat[i] == '$')
                count = i;
        }

        string s = "";
        for (int i =count;i<dat.length();i++)
        {
            s += dat[i];
        }

        try
        {
            GameState* gs = new GameState(s, 100);
            setState(gs);
            delete gs;
        }
        catch (string p)
        {
            throw p;
        }
    
    }

    return 0;
}