#ifndef LGAME_H
#define LGAME_H

#include "Game.h"

using namespace std;

class LocalGame : public Game
{
    private:
        SDL_Event event;
        map<int, bool> keys;

    public:
        LocalGame(int width, int height);
        int update();
};

#endif