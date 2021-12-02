#include <iostream>
#include <cmath>
#include "Display.h"
#include <map>
#include <chrono>

#include "Player.h"
#include "Ball.h"

using namespace std;


int main()
{
    cout<<"Creating window"<<endl;

    //Dimensions for window
    int width = 600;
    int height = 600;
    Display* mainWindow = new Display("MultiPong", width, height);

    bool running = true;
	SDL_Event event;


    cout<<"Creating players"<<endl;
    Player* player1 = new Player(true, 15, 70, width, height);
    Player* player2 = new Player(false, 15, 70, width, height);

    cout<<"Creating ball "<<endl;

    double angle1 = 0;//rand()/(double)RAND_MAX*2*M_PI;
    double dir = rand()/(double)RAND_MAX;

    if (dir<0.5)
        angle1 += M_PI;

    Ball* ball = new Ball(width/2, height/2, 30, angle1, width, height);

    SolidRectangle* top = new SolidRectangle(0, 0, width, 10 );
    SolidRectangle* bottom = new SolidRectangle(0, height -10, width, 10 );


    Colour* white = new Colour(255, 255, 255);
    const int numObjects = 5;
    SolidRectangle* objects[numObjects];
    objects[0] = ball;
    objects[1] = top;
    objects[2] = bottom;
    objects[3] = player1;
    objects[4] = player2;

    //Have the ball check collision on these objects

    for (int i =1;i<numObjects;i++)
    {
        ball->bindObject(objects[i]);
    }


    int scores[2];
    scores[0] = scores[1] = 0;

    //Map of keys currently pressed, conveniently using sdl numbers.
    //Reference the up key with keys[SDLK_UP]
    map<int, bool> keys;

    bool turn = true;

    int playerMov = 8;

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

        if (keys[SDLK_w] != keys[SDLK_s])
        {
            if (keys[SDLK_w])
                player1->changeVertPos(-playerMov);
            if (keys[SDLK_s])
                player1->changeVertPos(playerMov);
        }

        if (keys[SDLK_p] != keys[SDLK_l])
        {
            if (keys[SDLK_p])
                player2->changeVertPos(-playerMov);
            if (keys[SDLK_l])
                player2->changeVertPos(playerMov);
        }

        //Draw the main objects
        for (int i =0;i<numObjects;i++)
        {
            mainWindow->setShape(objects[i], white);
        }

        mainWindow->showText(to_string(scores[0]), 50, width/4, 10);
        mainWindow->showText(to_string(scores[1]), 50, 3*width/4, 10);

        try
        {
            ball->update();
        }
        catch(int p)
        {
            cout<<p<<" got a point"<<endl;
            scores[p]++;
            ball->reset();
            SDL_Delay(200);
        }
        
        mainWindow->draw();
	}

    for (int i =0;i<numObjects;i++)
    {
        delete objects[i];
    }

    delete mainWindow;
    delete white;

    return 0;
}
