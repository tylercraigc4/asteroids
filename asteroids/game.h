/*********************************************************************
 * File: game.h
 * Description: Defines the game class for Asteroids
 *
 *********************************************************************/

#ifndef GAME_H
#define GAME_H
#include <vector>
#include "flyingObject.h"
#include "rocks.h"
#include "uiInteract.h"
#include "point.h"
#include "velocity.h"
#include "bullet.h"
#include "ship.h"
using namespace std;


class Game
{
private:
    
    // The coordinates of the screen
    Point topLeft;
    Point bottomRight;
    vector<Rock*> rocks;
    Ship* ship;
    vector<Bullet*> bullets;
    int score;
public:
    
    Game(Point tl, Point br);
    ~Game();
    void handleInput(const Interface & ui);
    void handleCollisions();
    void spawnOtherAsteroids(int);
    void advance();
    void draw(const Interface & ui);
    float getClosestDistance(FlyingObject &obj1, FlyingObject &obj2);
    void advanceRocks();
    void advanceShip();
    void advanceBullets();
    Rock* createBigRock();
    void cleanUpZombies();
    
};


#endif /* GAME_H */
