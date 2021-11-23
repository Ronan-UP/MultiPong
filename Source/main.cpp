#include <iostream>
#include "Display.h"
#include <map>

#include "Player.h"

using namespace std;


int main()
{
    cout<<"Nothing implemented yet. See you soon though"<<endl;

    //Dimensions for window
    int height = 1200;
    int width = 1000;
    Display* mainWindow = new Display("MultiPong", height, width);

    bool running = true;
	SDL_Event event;




    Player* player1 = new Player(true, 15, 100);

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
        mainWindow->draw();
	}

    delete mainWindow;
    return 0;
}
