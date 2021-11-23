#include "Shape.h"

using namespace std;

Shape::Shape(int nx, int ny)
{
    position = new Point(nx, ny);
}

Shape::~Shape()
{
    delete position;
}

Point* Shape::getPosition()
{
    return position;
}

void Shape::changePosition(int x, int y)
{
    position->x += x;
    position->y += y;
}

void Shape::setX(int x)
{
    position->x = x;
}
void Shape::setY(int y)
{
    position->y = y;
}
