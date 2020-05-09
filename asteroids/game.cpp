/*********************************************************************
 * File: game.cpp
 * Description: Contains the implementaiton of the game class
 *  methods.
 *
 *********************************************************************/

#include "game.h"
// These are needed for the getClosestDistance function...
#include <limits>
#include <algorithm>
using namespace std;



Game :: Game(Point tl, Point br) : topLeft(tl), bottomRight(br)
{
    score = 0;
    ship = NULL;
    ship = new Ship();
    
    for (int i = 0; i < 5; i++)
    {
        rocks.push_back(createBigRock());
    }
    
}


/*********************************************
 * Function: handleInput
 * Description: Takes actions according to whatever
 *  keys the user has pressed.
 *********************************************/
void Game :: handleInput(const Interface & ui)
{
    // Change the direction of the rifle
    if (ui.isUp())
    {
        ship -> applyThrust();
    }
    
    if (ui.isLeft())
    {
        ship -> rotateLeft();
    }
    
    if (ui.isRight())
    {
        ship -> rotateRight();
    }
    
    // Check for "Spacebar
    if (ui.isSpace() && ship -> isAlive())
    {
        Bullet* newBullet = new Bullet();
        newBullet -> fire(ship -> getPoint(), ship -> getRotation());
        Velocity bulletVelocity = newBullet -> getVelocity();
        Velocity shipVelocity = ship -> getVelocity();
        newBullet -> setVelocity(shipVelocity + bulletVelocity);
        bullets.push_back(newBullet);
    }
}

void Game :: handleCollisions()
{
    
    for (int i = 0; i < rocks.size(); i++)
    {
        if(getClosestDistance(*ship, *rocks[i]) < ship -> getSize())
            ship -> setAlive(false);
    }
    
    for (int i = 0; i < bullets.size(); i++)
    {
        for (int j = 0; j < rocks.size(); j++)
        {
            if (getClosestDistance(*bullets[i], *rocks[j]) < rocks[j] -> getSize())
            {
                bullets[i] -> kill();
                rocks[j] -> kill();
                spawnOtherAsteroids(j);
            }
        }
    }
}

void Game :: spawnOtherAsteroids(int j) // checks for dead asteroids and spawns smaller rocks
{
        if (rocks[j] -> isAlive() == false && rocks[j] -> getName() == 1)
        {
            Rock* mediumRock1 = new MediumRock(rocks[j] -> getPoint());
            Rock* mediumRock2 = new MediumRock(rocks[j] -> getPoint());
            Rock* smallRock = new SmallRock(rocks[j] -> getPoint());
            
            rocks.push_back(mediumRock1);
            rocks.push_back(mediumRock2);
            rocks.push_back(smallRock);
            
            score += 100;

        }
        
        else if (rocks[j] -> isAlive() == false && rocks[j] -> getName() == 2)
        {
            Rock* smallRock = new SmallRock(rocks[j] -> getPoint());
            Rock* smallRock2 = new SmallRock(rocks[j] -> getPoint());
            rocks.push_back(smallRock);
            rocks.push_back(smallRock2);
            
            score += 200;
        }
    
        else
            score += 300;
}

/*********************************************
 * Function: advance
 * Description: Move everything forward one
 *  step in time.
 *********************************************/
void Game :: advance()
{
    advanceRocks();
    advanceShip();
    advanceBullets();
    handleCollisions();
    cleanUpZombies();
}

/*********************************************
 * Function: draw
 * Description: draws everything for the game.
 *********************************************/
void Game :: draw(const Interface & ui)
{
    
    for (vector<Rock*>::iterator it = rocks.begin(); it != rocks.end(); it++)
    {
        if ((*it) -> isAlive())
            (*it) -> draw();
    }

    ship -> draw();
    
    if (!ship -> isAlive())
    {
        drawText(Point(), "GAME OVER!");
    }
    
    if (ship -> isAlive() && score >= 10000)
    {
        drawText(Point(), "YOU WIN!");
    }
    
    
    for (vector<Bullet*>::iterator it = bullets.begin(); it != bullets.end(); it++)
    {
        if ((*it) -> isAlive())
            (*it) -> draw();
    }
    
    // Put the score on the screen
    Point scoreLocation;
    scoreLocation.setX(topLeft.getX() + 5);
    scoreLocation.setY(topLeft.getY() - 5);
    
    drawNumber(scoreLocation, score);
    
}

Game :: ~Game()
{
    // Look for dead ship
    if (ship -> isAlive() == false)
    {
        delete ship;
        ship = NULL;
    }
}

void Game :: advanceRocks()
{
    for (vector<Rock*>::iterator it = rocks.begin(); it != rocks.end(); it++)
    {
        (*it) -> advance();
    }
}

void Game :: advanceShip()
{
    if (ship -> isAlive())
        ship -> advance();
}

void Game :: advanceBullets()
{
    for (vector<Bullet*>::iterator it = bullets.begin(); it != bullets.end(); it++)
    {
        if (getClosestDistance(*ship, *(*it)) >= 200)
            (*it) -> setAlive(false);
            
        (*it) -> advance();
    }
}

void Game :: cleanUpZombies()
{
   
    
    // Look for dead Rocks
    vector<Rock*>::iterator RockIt = rocks.begin();
    while (RockIt != rocks.end())
    {
        // Asteroids Hint:
        // If we had a list of pointers, we would need this line instead:
        Rock* pRock = *RockIt;
        
        if (pRock -> isAlive() == false)
        {
            // If we had a list of pointers, we would need to delete the memory here...
            delete pRock;
            pRock = NULL;
            
            // remove from list and advance
            RockIt = rocks.erase(RockIt);
        }
        else
        {
            RockIt++; // advance
        }
    }
   
    // Look for dead bullets
    vector<Bullet*>::iterator bulletIt = bullets.begin();
    while (bulletIt != bullets.end())
    {
        // Asteroids Hint:
        // If we had a list of pointers, we would need this line instead:
        Bullet* pBullet = *bulletIt;
        
        if (pBullet -> isAlive() == false)
        {
            // If we had a list of pointers, we would need to delete the memory here...
            delete pBullet;
            pBullet = NULL;
            
            // remove from list and advance
            bulletIt = bullets.erase(bulletIt);
        }
        else
        {
            bulletIt++; // advance
        }
    }
}

Rock* Game :: createBigRock()
{
    Rock* bigRock = new BigRock();
    return bigRock;
}

// You may find this function helpful...

/**********************************************************
 * Function: getClosestDistance
 * Description: Determine how close these two objects will
 *   get in between the frames.
 **********************************************************/

float Game :: getClosestDistance(FlyingObject &obj1, FlyingObject &obj2)
{
   // find the maximum distance traveled
   float dMax = max(abs(obj1.getVelocity().getDx()), abs(obj1.getVelocity().getDy()));
   dMax = max(dMax, abs(obj2.getVelocity().getDx()));
   dMax = max(dMax, abs(obj2.getVelocity().getDy()));
   dMax = max(dMax, 0.1f); // when dx and dy are 0.0. Go through the loop once.
   
   float distMin = std::numeric_limits<float>::max();
   for (float i = 0.0; i <= dMax; i++)
   {
      Point point1(obj1.getPoint().getX() + (obj1.getVelocity().getDx() * i / dMax),
                     obj1.getPoint().getY() + (obj1.getVelocity().getDy() * i / dMax));
      Point point2(obj2.getPoint().getX() + (obj2.getVelocity().getDx() * i / dMax),
                     obj2.getPoint().getY() + (obj2.getVelocity().getDy() * i / dMax));
      
      float xDiff = point1.getX() - point2.getX();
      float yDiff = point1.getY() - point2.getY();
      
      float distSquared = (xDiff * xDiff) + (yDiff * yDiff);
      
      distMin = min(distMin, distSquared);
   }
   
   return sqrt(distMin);
}

