#include "Display.h"
#include <iostream>

using namespace std;

void Display::setPoint(int x, int y, Colour* c) 
{

	SDL_SetRenderDrawColor(renderer, c->r, c->g, c->b, 255);
	SDL_RenderDrawPoint(renderer, x, y);
}

void Display::setShape(SolidRectangle* r, Colour* c)
{

	SDL_SetRenderDrawColor(renderer, c->r, c->g, c->b, 255);
	SDL_Rect* re = new SDL_Rect();

	Shape* temp = dynamic_cast<Shape*>(r);

	re->x = temp->getPosition()->x;
	re->y = temp->getPosition()->y;
	re->w = r->getWidth();
	re->h = r->getHeight();
	SDL_RenderFillRect(renderer, re);

    delete re;
}

void Display::setShape(Circle* ci, Colour* co)
{
	SDL_SetRenderDrawColor(renderer, co->r, co->g, co->b, 255);
	SDL_RenderDrawCircle(ci->getPosition()->x, ci->getPosition()->y, ci->getRadius());
}

Display::Display(string title, int nx, int ny)
{
	width = nx;
	height = ny;
	screenTitle = title;

	window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, 0);
	windowSurface = SDL_GetWindowSurface(window);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	SDL_RenderClear(renderer);

    if (TTF_Init() >= 0)
        Sans = TTF_OpenFont("./Fonts/OpenSans-Regular.ttf", 100);
    else 
        Sans = 0;

}

void Display::clear() {

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
}

Display::~Display() {

	SDL_DestroyWindow(window);
    //delete windowSurface;
}


void Display::draw() {

	SDL_RenderPresent(renderer);
}

void Display::showText(string t, double size, double x, double y)
{
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

    if (!Sans)
    {
        cout<<TTF_GetError()<<endl;
        TTF_Init();
        return;
    }

    SDL_Surface* surfaceMessage = TTF_RenderText_Solid(Sans, t.c_str(), {255, 255, 255});
    SDL_Texture* Message = SDL_CreateTextureFromSurface(renderer, surfaceMessage);

    SDL_Rect Message_rect;
    Message_rect.x = x;
    Message_rect.y = y;
    Message_rect.w = (t.length())*size/2;
    Message_rect.h = size;

    SDL_RenderCopy(renderer, Message, NULL, &Message_rect);

    SDL_DestroyTexture(Message);
	SDL_FreeSurface(surfaceMessage);
 
}

//External method obtained from Github, Gumichan01.
void Display::SDL_RenderDrawCircle( int x, int y, int radius)
{
    int offsetx, offsety, d;
    int status;

    //CHECK_RENDERER_MAGIC(renderer, -1);

    offsetx = 0;
    offsety = radius;
    d = radius -1;
    status = 0;

    while (offsety >= offsetx) {
        status += SDL_RenderDrawPoint(renderer, x + offsetx, y + offsety);
        status += SDL_RenderDrawPoint(renderer, x + offsety, y + offsetx);
        status += SDL_RenderDrawPoint(renderer, x - offsetx, y + offsety);
        status += SDL_RenderDrawPoint(renderer, x - offsety, y + offsetx);
        status += SDL_RenderDrawPoint(renderer, x + offsetx, y - offsety);
        status += SDL_RenderDrawPoint(renderer, x + offsety, y - offsetx);
        status += SDL_RenderDrawPoint(renderer, x - offsetx, y - offsety);
        status += SDL_RenderDrawPoint(renderer, x - offsety, y - offsetx);

        if (status < 0) {
            status = -1;
            break;
        }

        if (d >= 2*offsetx) {
            d -= 2*offsetx + 1;
            offsetx +=1;
        }
        else if (d < 2 * (radius - offsety)) {
            d += 2 * offsety - 1;
            offsety -= 1;
        }
        else {
            d += 2 * (offsety - offsetx - 1);
            offsety -= 1;
            offsetx += 1;
        }
    }

}

// void Display::showText(string mess, int x, int y)
// {
// 	// TTF_Font * font = TTF_OpenFont("arial.ttf", 25)
// 	// SDL_Color color = { 255, 255, 255 };
// 	// SDL_Surface * surface = TTF_RenderText_Solid(font, mess, color);
// }
