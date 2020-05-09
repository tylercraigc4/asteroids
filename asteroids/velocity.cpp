#include "velocity.h"

Velocity :: Velocity()
{
    this -> Dx = 0;
    this -> Dy = 0;
}

Velocity :: Velocity(float Dx, float Dy)
{
    this -> Dx = Dx;
    this -> Dy = Dy;
}

void Velocity :: setDx(float Dx)
{
    this -> Dx = Dx;
}

void Velocity :: setDy(float Dy)
{
    this -> Dy = Dy;
}

float Velocity :: getDx()
{
    return Dx;
}

float Velocity :: getDy()
{
    return Dy;
}

Velocity Velocity :: operator+ (const Velocity rhs)
{
    Velocity newVelocity;
    newVelocity.setDy(this -> Dy + rhs.Dy);
    newVelocity.setDx(this -> Dx + rhs.Dx);
    return newVelocity;
}
