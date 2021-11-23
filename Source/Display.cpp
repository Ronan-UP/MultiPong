#include "Display.h"

using namespace std;


void Display::setPoint(int x, int y, Colour* c) 
{

	SDL_SetRenderDrawColor(renderer, c->r, c->g, c->b, 255);
	SDL_RenderDrawPoint(renderer, x, y);
}

void Display::setShape(Rectangle* r, Colour* c)
{

	SDL_SetRenderDrawColor(renderer, c->r, c->g, c->b, 255);
	SDL_Rect* re = new SDL_Rect();

	Shape* temp = dynamic_cast<Shape*>(r);

	re->x = temp->getPosition()->x;
	re->y = temp->getPosition()->y;
	re->w = r->getWidth();
	re->h = r->getHeight();
	SDL_RenderDrawRect(renderer, re);
//	delete temp;
}

Display::Display(string title, int nx, int ny)
{
	width = nx;
	height = ny;
	screenTitle = title;

	window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, 0);
	windowSurface = SDL_GetWindowSurface(window);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	SDL_RenderClear(renderer);

}

void Display::clear() {

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
}

Display::~Display() {

	SDL_DestroyWindow(window);
}


void Display::draw() {

	SDL_RenderPresent(renderer);
}

