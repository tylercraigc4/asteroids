#include "rocks.h"

// Put your Rock methods here
void Rock :: draw()
{
    
}

int Rock :: getRotation()
{
    return rotation;
}

void Rock :: setRotation(int rotation)
{
    this -> rotation = rotation;
}

int Rock :: getSize()
{
    return size;
}

void Rock :: setSize(int size)
{
    this -> size = size;
}

void Rock :: setAngle(int angle)
{
    this -> angle = angle;
}
int Rock :: getAngle()
{
    return angle;
}


// BigRock methods here
BigRock :: BigRock()
{
    setSize(BIG_ROCK_SIZE);
    setAngle(random(-180, 180));
    setRotation(random(0, 361));
    
    point.setX(random(-200, 200));
    point.setY(random(-200, 200));
    
    int randx = random(0, 2);
    int randy = random(0, 2);
    
    if (randx == 0)
        velocity.setDx(-1);
    else
        velocity.setDx(1);
    
    if (randy == 0)
        velocity.setDy(-1);
    else
        velocity.setDy(1);

    setAlive(true);
}

void BigRock :: draw()
{
    drawLargeAsteroid(getPoint(), getRotation());
    setRotation(getRotation() + 2);
}


// MediumRock methods here
MediumRock :: MediumRock()
{
    setSize(MEDIUM_ROCK_SIZE);
    setAngle(random(-180, 180));
    
    int randx = random(0, 2);
    int randy = random(0, 2);
    
    if (randx == 0)
        this -> velocity.setDx(-1);
    else
        this -> velocity.setDx(1);
    
    if (randy == 0)
        this -> velocity.setDy(-1);
    else
        this -> velocity.setDy(1);
    
    setAlive(true);
}

MediumRock :: MediumRock(Point point)
{
    setPoint(point);
    setSize(MEDIUM_ROCK_SIZE);
    setAngle(random(-180, 180));
    
    int randx = random(0, 2);
    int randy = random(0, 2);
    
    if (randx == 0)
        velocity.setDx(-1);
    else
        velocity.setDx(1);
    
    if (randy == 0)
        velocity.setDy(-1);
    else
        velocity.setDy(1);
    
    setAlive(true);
    
}

void MediumRock :: draw()
{
    drawMediumAsteroid(getPoint(), getRotation());
    setRotation(getRotation() + 5);
}

// SmallRock methods here
SmallRock :: SmallRock()
{
    setSize(SMALL_ROCK_SIZE);
    setAngle(random(-180, 180));
    
    int randx = random(0, 2);
    int randy = random(0, 2);
    
    if (randx == 0)
        velocity.setDx(-1);
    else
        velocity.setDx(1);
    
    if (randy == 0)
        velocity.setDy(-1);
    else
        velocity.setDy(1);
    
    setAlive(true);
}

SmallRock :: SmallRock(Point point)
{
    setPoint(point);
    setSize(SMALL_ROCK_SIZE);
    setAngle(random(-180, 180));
    
    int randx = random(0, 2);
    int randy = random(0, 2);
    
    if (randx == 0)
        velocity.setDx(-1.5);
    else
        velocity.setDx(1.5);
    
    if (randy == 0)
        velocity.setDy(-1.5);
    else
        velocity.setDy(1.5);
    
    setAlive(true);
}

void SmallRock :: draw()
{
    drawSmallAsteroid(getPoint(), getRotation());
    setRotation(getRotation() + 10);
}
