#include "ship.h"
#include <iostream>

using namespace std;

// Put your ship methods here
Ship :: Ship()
{
    setAlive(true);
    point.setX(0);
    point.setY(0);
    setRotation(0);
    setSize(SHIP_SIZE);
    
    draw();
}

void Ship :: applyThrust()
{
    float dx = getVelocity().getDx() + cos(M_PI / 180.0 * (getRotation() + 90));
    float dy = getVelocity().getDy() + sin(M_PI / 180.0 * (getRotation() + 90));

    velocity.setDx(dx / 1.1);
    velocity.setDy(dy / 1.1);
}

void Ship :: draw()
{
    if (isAlive() == true)
        drawShip(getPoint(), getRotation());
}

void Ship :: setRotation(int rotation)
{
    this -> rotation = rotation;
}

int Ship :: getRotation()
{
    return rotation;
}

void Ship :: setSize(int size)
{
    this -> size = size;
}

int Ship :: getSize()
{
    return size;
}

void Ship :: rotateLeft()
{
    setRotation(getRotation() + 6);
}

void Ship :: rotateRight()
{
    setRotation(getRotation() - 6);
}
