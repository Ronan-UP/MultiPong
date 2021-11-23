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

    cout<<"Creating ball "<<endl;

    double angle1 = rand()/(double)RAND_MAX*2*M_PI;
    double dir = rand()/(double)RAND_MAX;

    if (dir<0.5)
        angle1 += M_PI;

    Ball* ball = new Ball(width/2, height/2, 10, angle1, 6, width, height);

    ball->bindPlayers(player1, player2);

    //Map of keys currently pressed, conveniently using sdl numbers.
    //Reference the up key with keys[SDLK_UP]
    map<int, bool> keys;

    bool turn = true;

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
                player1->moveUp(10);
            if (keys[SDLK_s])
                player1->moveDown(10);
        }

        if (keys[SDLK_p] != keys[SDLK_l])
        {
            if (keys[SDLK_p])
                player2->moveUp(10);
            if (keys[SDLK_l])
                player2->moveDown(10);
        }

        mainWindow->setShape(player1->getImage(), new Colour(255, 255, 255));
        mainWindow->setShape(player2->getImage(), new Colour(255, 255, 255));

        try
        {
            ball->update();
        }
        catch(int p)
        {
            cout<<p<<" got a point"<<endl;
            delete ball;
            double angle = (rand()/(double)RAND_MAX)*M_PI/2 - M_PI/4;

            if (turn)
                angle += M_PI;

            turn = !turn;

            ball = new Ball(width/2, height/2, 10, angle, 6, width, height);

            ball->bindPlayers(player1, player2);
        }
        

        mainWindow->setShape(ball->getImage(), new Colour(255, 255, 255));
        mainWindow->draw();
	}

    delete player1;
    delete ball;
    delete mainWindow;
    return 0;
}
