#include <iostream>
#include "Display.h"

using namespace std;


int main()
{
    cout<<"Nothing implemented yet. See you soon though"<<endl;

    int width = 500;
    int height = 700;
    Display* mainWindow = new Display("MultiPong", height, width);

    bool running = true;
	SDL_Event event;
    while (running)
    {
		while( SDL_PollEvent( &event ) )
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
                    //keyboard[event.key.keysym.sym] = false;
                    cout<<"Key "<<event.key.keysym.sym<<" down"<<endl;
                    break;
                }
                case SDL_KEYUP:
                {
                    //keyboard[event.key.keysym.sym] = true;
                    cout<<"Key "<<event.key.keysym.sym<<" up"<<endl;
                    break;
                }
            }
		}

	}

    return 0;
}
