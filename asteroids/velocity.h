//
//  velocity.h
//  MilestoneMoonLander06
//
//  Created by Tyler Craig on 6/7/18.
//  Copyright © 2018 Tyler Craig. All rights reserved.
//

#ifndef velocity_h
#define velocity_h

class Velocity
{
private:
    
    float Dx;
    float Dy;
    
public:
    
    Velocity();
    Velocity(float Dx, float Dy);
    float getDx();
    float getDy();
    void setDx(float Dx);
    void setDy(float Dy);
    Velocity operator+ (const Velocity rhs);
    
};

#endif /* velocity_h */
