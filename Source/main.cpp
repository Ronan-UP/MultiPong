#include <iostream>
#include "Server.h"
#include "Client.h"
#include "LocalGame.h"
#include "ClientGame.h"
#include "ServerGame.h"

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

 Colour *white = new Colour(255, 255, 255);
 const int numObjects = 5;

Game* game;

switch (gt)
{
    case Local:
    {
        game = new LocalGame(width, height);
        break;
    }
    case LANHost:
    {
        game = new ServerGame(width, height, 5001);

        mainWindow->clear();
        mainWindow->showText("Waiting for connection......", 30, width / 6, 10);
        mainWindow->draw();
        while (!dynamic_cast<ServerGame*>(game)->tryConnection())
        { 
            while (SDL_PollEvent(&event))
            {
                switch (event.type)
                {
                    case SDL_QUIT:
                    {
                        return 0;
                        break;
                    }
                }
            }
        }

        break;
    }
    case LANClient:
    {
        game = new ClientGame(width, height, "localhost", 5001);
        break;
    }
}

SolidRectangle** objects = game->getObjects();

while (running)
{
    mainWindow->clear();

    //Draw the main objects
    for (int i = 0; i < numObjects; i++)
    {
        mainWindow->setShape(objects[i], white);
    }

    mainWindow->showText(to_string(game->getP1Score()), 50, width / 4, 10);
    mainWindow->showText(to_string(game->getP2Score()), 50, 3 * width / 4, 10);

    try
    {
        int res = game->update();
        if (res <0)
        {
            return 0;
        }
    }
    catch (const char* p)
    {
        cout << p <<endl;
        //Here
        mainWindow->clear();
        mainWindow->showText(p, 70, (width - 500) / 2, 300);
        mainWindow->draw();
        SDL_Delay(500);

        return 0;
    }

    mainWindow->draw();
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

    return -1; //Should not happen
}
