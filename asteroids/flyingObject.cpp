//
//  flyingObject.cpp
//  asteroids
//
//  Created by Tyler Craig on 6/21/18.
//  Copyright © 2018 Tyler Craig. All rights reserved.
//
#include "flyingObject.h"

Point FlyingObject :: getPoint()
{
    return point;
}

void FlyingObject :: setPoint(Point point)
{
    this -> point = point;
}

Velocity FlyingObject :: getVelocity()
{
    return velocity;
}

void FlyingObject :: setVelocity(Velocity velocity)
{
    this -> velocity = velocity;
}

bool FlyingObject :: isAlive()
{
    return alive;
}

void FlyingObject :: kill()
{
    setAlive(false);
}

void FlyingObject :: advance()
{
    point.setX(getPoint().getX() + velocity.getDx());
    point.setY(getPoint().getY() + velocity.getDy());
    
    if (point.getX() > 220)
    {
        point.setX(point.getX() - 430);
    }
    
    if (point.getX() < -220)
    {
        point.setX(point.getX() + 430);
    }
    
    if (point.getY() > 220)
    {
        point.setY(point.getY() - 430);
    }
    
    if (point.getY() < -220)
    {
        point.setY(point.getY() + 430);
    }
}

void FlyingObject :: draw()
{
    
}

void FlyingObject :: setAlive(bool alive)
{
    this -> alive = alive;
}
