#include <iostream>
#include "Display.h"
#include <map>

#include "Rectangle.h"

using namespace std;


int main()
{
    cout<<"Nothing implemented yet. See you soon though"<<endl;

    //Dimensions for window
    int width = 500;
    int height = 700;
    Display* mainWindow = new Display("MultiPong", height, width);

    bool running = true;
	SDL_Event event;


    Rectangle* player1 = new Rectangle(0, 0, 50, 100);
    mainWindow->setShape(player1, new Colour(255, 255, 255));
    mainWindow->draw();

    //Map of keys currently pressed, conveniently using sdl numbers.
    //Reference the up key with keys[SDLK_UP]
    map<int, bool> keys;

    while (running)
    {
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

	}

    delete mainWindow;
    return 0;
}
