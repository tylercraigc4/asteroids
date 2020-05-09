#ifndef bullet_h
#define bullet_h

#define BULLET_SPEED 5
#define BULLET_LIFE 40

// Put your Bullet class here
#include "flyingObject.h"
#include "uiDraw.h"
#include "velocity.h"
#include "point.h"
#include "ship.h"
#include <cmath>

class Bullet : public FlyingObject
{
private:
    
public:
    Bullet();
    virtual void draw();
    void fire(Point point, float angle);
    
};

#endif /* bullet_h */
