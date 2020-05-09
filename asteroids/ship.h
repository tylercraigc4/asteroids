#ifndef ship_h
#define ship_h

#define SHIP_SIZE 20

#define ROTATE_AMOUNT 6
#define THRUST_AMOUNT 0.5

#include "flyingObject.h"
#include "uiDraw.h"


// Put your Ship class here
class Ship : public FlyingObject
{
    
private:
    int rotation;
    int size;
    int angle;
    
public:
    Ship();
    void applyThrust();
    virtual void draw();
    void setRotation(int);
    int getRotation();
    void setSize(int);
    int getSize();
    void rotateLeft();
    void rotateRight();
    
};

#endif /* ship_h */

