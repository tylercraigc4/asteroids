//
//  bullet.cpp
//  asteroids
//
//  Created by Tyler Craig on 6/21/18.
//  Copyright © 2018 Tyler Craig. All rights reserved.
//

#include "bullet.h"

Bullet :: Bullet()
{
    velocity.setDx(0);
    velocity.setDy(0);
    setAlive(true);
    Point();
}

void Bullet:: draw()
{
    drawDot(getPoint());
}

void Bullet :: fire(Point point, float angle)
{
    float dx = BULLET_SPEED * cos(M_PI / 180.0 * (angle + 90));
    float dy = BULLET_SPEED * sin(M_PI / 180.0 * (angle + 90));
    setPoint(point);
    velocity.setDx(dx);
    velocity.setDy(dy);
    
}
