//This class represents the ball used in the game

#include "Circle.h"
#include <cmath>

using namespace std;

class Ball
{
    private:
        Circle* image;
        double angle;
        double velocity;

    public:
        Ball(int x, int y, int r, double a, double vel);
        Circle* getImage();
        ///Let the ball move in its current direction
        void update();

};