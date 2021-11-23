#include <iostream>
#include "Display.h"
#include <map>

#include "Player.h"
#include "Ball.h"

using namespace std;


int main()
{
    cout<<"Creating window"<<endl;

    //Dimensions for window
    int width = 1200;
    int height = 1000;
    Display* mainWindow = new Display("MultiPong", width, height);

    bool running = true;
	SDL_Event event;



    cout<<"Creating players"<<endl;
    Player* player1 = new Player(true, 15, 100, width, height);
    Player* player2 = new Player(false, 15, 100, width, height);

    cout<<"Creating ball"<<endl;
    Ball* ball = new Ball(width/2, height/2, 10, 3.14/3, 2.15);

    //Map of keys currently pressed, conveniently using sdl numbers.
    //Reference the up key with keys[SDLK_UP]
    map<int, bool> keys;

    while (running)
    {
        mainWindow->clear();

		while(SDL_PollEvent(&event))
        {
			switch (event.type)
            {
                case SDL_QUIT:
                {
				    running = false;
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

        if (keys[SDLK_UP] != keys[SDLK_DOWN])
        {
            if (keys[SDLK_UP])
                player1->moveUp(1);
            if (keys[SDLK_DOWN])
                player1->moveDown(1);
        }

        mainWindow->setShape(player1->getImage(), new Colour(255, 255, 255));
        mainWindow->setShape(player2->getImage(), new Colour(255, 255, 255));
        ball->update();
        mainWindow->setShape(ball->getImage(), new Colour(255, 255, 255));
        mainWindow->draw();
	}

    delete player1;
    delete ball;
    delete mainWindow;
    return 0;
}
