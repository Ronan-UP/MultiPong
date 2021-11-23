#include "Player.h"

using namespace std;

Player::Player(bool p1, int w, int h)
{
    image = new Rectangle(0, 0, w, h);

    winHeight = h;
    winWidth = w;
}

Rectangle* Player::getImage()
{
    return image;
}

void Player::moveUp(int d)
{
    image->changePosition(0, -1*d);
}

void Player::moveDown(int d)
{
    image->changePosition(0, d);
}