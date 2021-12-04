#include "LocalGame.h"

using namespace std;

//Enable collision on the ball
LocalGame::LocalGame(int width, int height) : Game(width, height)
{
    for (int i = 1; i < numObjects; i++)
    {
        ball->bindObject(objects[i]);
    }
}

int LocalGame::update()
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

    if (keys[SDLK_p])
            p2->changeVertPos(-playerMov);
    if (keys[SDLK_l])
            p2->changeVertPos(playerMov);

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

    return 0;
}