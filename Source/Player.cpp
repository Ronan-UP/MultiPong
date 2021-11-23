#include "Player.h"

using namespace std;

Player::Player(bool p1, int w, int h, int ww, int wh)
{
    int x = 0;
    int y = wh/2;

    if (!p1)
    {
        x = ww-w;
    }

    image = new Rectangle(x, y, w, h);

    winHeight = wh;
    winWidth = ww;
}

Rectangle* Player::getImage()
{
    return image;
}

void Player::moveUp(int d)
{
    image->changePosition(0, -1*d);

    Point* p = image->getPosition();

    if (p->y<0)
    {
        image->setY(0);
    }

}

void Player::moveDown(int d)
{
    image->changePosition(0, d);

    int mY = winHeight - image->getHeight();
    if (image->getPosition()->y > mY)
    {
        image->setY(mY);
    }

}