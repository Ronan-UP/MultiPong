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
