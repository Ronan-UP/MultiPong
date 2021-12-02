//This class is used as an interaction with the window

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <string>
#include "Rectangle.h"
#include "Circle.h"
#include <string>

using namespace std;

struct Colour {

	int r;
	int g;
	int b;
    Colour(int nr, int ng, int nb) {
        r = nr;
        g = ng;
        b = nb;
    }
};

class Display {

	public:
		Display(string t, int w, int h);
		~Display();
		void setPoint(int, int, Colour*);
		void setShape(SolidRectangle*, Colour*);
		void setShape(Circle*, Colour*);
		void clear();
		void draw();
		void showText(string text, double size, double x, double y);

	private:

		SDL_Renderer* renderer;
		SDL_Window* window;
		string screenTitle;
		SDL_Surface* windowSurface;
		int height;
		int width;
		TTF_Font* Sans;
		void SDL_RenderDrawCircle( int x, int y, int radius);
};
