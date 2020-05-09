#ifndef rocks_h
#define rocks_h

#define BIG_ROCK_SIZE 16
#define MEDIUM_ROCK_SIZE 8
#define SMALL_ROCK_SIZE 4

#define BIG_ROCK_SPIN 2
#define MEDIUM_ROCK_SPIN 5
#define SMALL_ROCK_SPIN 10

#include "flyingObject.h"
#include "velocity.h"
#include "uiDraw.h"


// Define the following classes here:
//   Rock
class Rock : public FlyingObject
{
protected:
    int rotation;
    int size;
    int angle;
    
public:
    virtual int getName() = 0;
    virtual void draw();
    int getRotation();
    void setRotation(int);
    void setSize(int size);
    int getSize();
    void setAngle(int angle);
    int getAngle();
    
};

//   BigRock
class BigRock : public Rock
{
private:
    
public:
    virtual int getName() {return 1;}
    BigRock();
    virtual void draw();
    
};

//   MediumRock
class MediumRock : public Rock
{
private:
    
public:
    virtual int getName() {return 2;}
    MediumRock();
    MediumRock(Point);
    virtual void draw();
    
    
};
//   SmallRock
class SmallRock : public Rock
{
private:
    
public:
    virtual int getName() {return 3;}
    SmallRock();
    SmallRock(Point);
    virtual void draw();

};

#endif /* rocks_h */
