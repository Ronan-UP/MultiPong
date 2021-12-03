#include <iostream>
#include <cmath>
#include "Display.h"
#include <map>
#include <chrono>

#include "Player.h"
#include "Ball.h"

using namespace std;

enum GameType
{
    Local,
    LANHost,
    LANClient
} gt;

int getMenuOption(int options[], int numOp);

int main()
{
    cout << "Creating window" << endl;

    //Dimensions for window
    int width = 600;
    int height = 600;
    Display *mainWindow = new Display("MultiPong", width, height);


    //Show initial menu

    mainWindow->showText("Welcome to MultiPong!", 50, (width - 570) / 2, 1);
    mainWindow->showText("Select an option using the number keys", 30, (width - 570) / 2, 80);
    mainWindow->showText("Local Play (1)", 50, (width - 500) / 2, 300);
    mainWindow->showText("LAN Play (2)", 50, (width - 500) / 2, 350);
    mainWindow->draw();

    bool menu = true;
    while (menu)
    {

        int options[] = {SDLK_1, SDLK_2};
        int res = getMenuOption(options, 2);

        if (res < 0)
            return 0;

        if (res == 0)
        {
            cout << "Local Game" << endl;
            gt = Local;
            menu = false;
        }
        else if (res == 1)
        {
            cout << "LAN Game" << endl; //Second menu

            mainWindow->clear();
            mainWindow->showText("Host a game (1)", 50, (width - 500) / 2, 300);
            mainWindow->showText("Join a game (2)", 50, (width - 500) / 2, 350);
            mainWindow->draw();

            res = getMenuOption(options, 2);
            if (res < 0)
                return 0;

            if (res == 0)
            {
                cout << "Host Game" << endl;
                gt = LANHost;
                menu = false;
            }
            else if (res == 1)
            {
                cout << "Find Game" << endl;
                gt = LANClient;
                menu = false;
            }
        }
    }

bool running = true;

SDL_Event event;

cout << "Creating players" << endl;
Player *player1 = new Player(true, 15, 70, width, height);
Player *player2 = new Player(false, 15, 70, width, height);

cout << "Creating ball " << endl;

Ball *ball = new Ball(width / 2, height / 2, 30, width, height);

SolidRectangle *top = new SolidRectangle(0, 0, width, 10);
SolidRectangle *bottom = new SolidRectangle(0, height - 10, width, 10);

Colour *white = new Colour(255, 255, 255);
const int numObjects = 5;
SolidRectangle *objects[numObjects];
objects[0] = ball;
objects[1] = top;
objects[2] = bottom;
objects[3] = player1;
objects[4] = player2;

//Have the ball check collision on these objects

for (int i = 1; i < numObjects; i++)
{
    ball->bindObject(objects[i]);
}

int scores[2];
scores[0] = scores[1] = 0;

//Map of keys currently pressed, conveniently using sdl numbers.
//Reference the up key with keys[SDLK_UP]
map<int, bool> keys;

bool turn = true;

int playerMov = 7;

while (running)
{

    mainWindow->clear();

    while (SDL_PollEvent(&event))
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
    for (int i = 0; i < numObjects; i++)
    {
        mainWindow->setShape(objects[i], white);
    }

    mainWindow->showText(to_string(scores[0]), 50, width / 4, 10);
    mainWindow->showText(to_string(scores[1]), 50, 3 * width / 4, 10);

    try
    {
        ball->update();
    }
    catch (int p)
    {
        cout << p << " got a point" << endl;
        scores[p]++;
        ball->reset();
        SDL_Delay(200);

        if (scores[0] >= 10 || scores[1] >= 10)
        {
            string win = "1";
            if (scores[1] >= 10)
                win = "2";

            mainWindow->clear();
            mainWindow->showText("Player " + win + " wins!", 70, (width - 500) / 2, 300);
            mainWindow->draw();
            SDL_Delay(2000);
            return 0;
        }
    }

    mainWindow->draw();
}

for (int i = 0; i < numObjects; i++)
{
    delete objects[i];
}

delete mainWindow;
delete white;

return 0;
}

//Get an option for a menu. Reads SDL keys until a valid option is found
int getMenuOption(int options[], int numOp)
{
    SDL_Event event;
    while (true)
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
                    for (int i = 0; i < numOp; i++)
                    {
                        if (options[i] == event.key.keysym.sym)
                            return i;
                    }
                    break;
                }
            }
        }
    }
    cout<<"No longer polling"<<endl;
    return -1;
}
