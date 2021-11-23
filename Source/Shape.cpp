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

void Shape::changePosition(double x, double y)
{
    position->x += x;
    position->y += y;
}

void Shape::setX(double x)
{
    position->x = x;
}
void Shape::setY(double y)
{
    position->y = y;
}
