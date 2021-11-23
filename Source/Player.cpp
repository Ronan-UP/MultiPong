#include "Player.h"

using namespace std;

Player::Player(bool p1, int w, int h)
{
    winHeight = h;
    winWidth = w;
}

Rectangle* Player::getImage()
{
    return image;
}

void Player::moveUp(int d)
{

}

void Player::moveDown(int d)
{

}