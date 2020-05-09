//
//  flyingObject.h
//  asteroids
//
//  Created by Tyler Craig on 6/21/18.
//  Copyright © 2018 Tyler Craig. All rights reserved.
//

#ifndef flyingObject_h
#define flyingObject_h
#include "point.h"
#include "velocity.h"

class FlyingObject
{
protected:
    Point point;
    Velocity velocity;
    bool alive;
public:
    Point getPoint();
    void setPoint(Point);
    Velocity getVelocity();
    void setVelocity(Velocity);
    bool isAlive();
    void setAlive(bool);
    void kill();
    virtual void advance();
    virtual void draw();
};

#endif /* flyingObject_h */
