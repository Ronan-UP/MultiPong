#include "Display.h"

using namespace std;


void Display::setPoint(int x, int y, Colour* c) 
{

	SDL_SetRenderDrawColor(renderer, c->r, c->g, c->b, 255);
	SDL_RenderDrawPoint(renderer, x, y);
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

