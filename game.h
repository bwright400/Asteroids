/*********************************************************************
 * File: game.h
 * Author: Br. Burton
 *
 * This file is provided as the instructor's "half" of the project.
 *
 * Please DO NOT provide, share, or distribute this file to students
 * of other sections or semesters.
 *********************************************************************/

#ifndef game_h
#define game_h


/****************************************
 * The game of Asteroids
 ****************************************/
#include <list>
#include "uiDraw.h"
#include "uiInteract.h"
#include "point.h"

#include "flyingObject.h"

using namespace std;

#define INITIAL_ROCK_COUNT 5


/*****************************************
 * GAME
 * The main game class containing all the state
 *****************************************/
class Game
{
public:
   
   // create the game
   Game(Point tl, Point br)
   {
      topLeft = tl;
      bottomRight = br;
      
      pShip = new Ship;
      
      for (int i = 0; i < 10; i++)
      {
         Rock *pRock = new BigRock(getRandomPoint());
         rocks.push_back(pRock);
      }
      
      for (int i = 0; i < 20; i++)
      {
        Star *pStar = new Star(getRandomPoint());
        shootingStars.push_back(pStar);
      }
   }
   ~Game() {}
   
   // handle user input
   void handleInput(const Interface & ui);
   
   // advance the game
   void advance();
   
   // draw stuff
   void draw(const Interface & ui);

   Point getRandomPoint() const;
   
   static int getXMin() { return topLeft.getX(); }
   static int getXMax() { return bottomRight.getX(); }
   static int getYMin() { return bottomRight.getY(); }
   static int getYMax() { return topLeft.getY(); }
   
private:
   static Point topLeft;
   static Point bottomRight;
   
   Ship * pShip;
   
   list<Bullet*> bullets;
   list<Rock*> rocks;
   list<Star*> shootingStars;
   
   void checkForCollisions();
   void cleanUpZombies();
   
   bool isCollision(const UFO &obj1, const UFO &obj2) const;
   float getClosestDistance(const UFO &obj1, const UFO &obj2) const;
   
};


#endif /* game_h */
