#include "flyingObject.h"
#include <cmath>

#define SHIP_SIZE 10

#define ROTATE_AMOUNT 6
#define THRUST_AMOUNT 0.5

/***********************************************************************
 * Draws the ship on the screen at the coordinates (0,0).
 **********************************************************************/
void Ship::draw()
{
   drawShip(getVel().getPt(), rotation, true);
}

/***********************************************************************
 * Turns the ship left when the user hits the left key.
 **********************************************************************/
int Ship::turnLeft()
{
   return rotation += ROTATE_AMOUNT;
}

/***********************************************************************
 * Turns the ship right when the user hits the right key.
 **********************************************************************/
int Ship::turnRight()
{
   return rotation -= ROTATE_AMOUNT;
}

/***********************************************************************
 * Increases the velocity of the ship when the user hits the up key.
 **********************************************************************/
void Ship::thrust()
{
   if (incr <= 8)
   {
      if (incr == 0)
         incr += 0.2;
      incr *= 2;
   }
   else
      incr = 10;
   
   float dx = (float)incr * (-cos((float)M_PI / 180.0 * (rotation - 90)));
   float dy = (float)incr * (sin((float)M_PI / 180.0 * (rotation + 90)));

   addVelDx(dx); 
   addVelDy(dy);
}

/***********************************************************************
 * Decreases the velocity of the ship when the user hits lets go
 * of the up key.
 **********************************************************************/
void Ship::de_thrust()
{

   if (incr > 0.f)
   {
      incr -= 0.2;
   }
   else
      incr = 0;
   
   float dx = (float)incr * (-cos((float)M_PI / 180.0 * (rotation - 90)));
   float dy = (float)incr * (sin((float)M_PI / 180.0 * (rotation + 90)));

   addVelDx(dx); 
   addVelDy(dy);
}


// Put your ship methods here
