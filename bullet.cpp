#include "flyingObject.h"
#include <cmath>

/***********************************************************************
 * Constructor for Bullet. Intializes the point of where the bullet
 * starts, equal to whatever point the ship is at.
 **********************************************************************/
Bullet::Bullet(Ship & pShip) : UFO(pShip)
{
}

/***********************************************************************
 * Extra Credit opportunity if we want to shoot a laser instead of a
 * bullet. This will kill the laser wants it reaches to a max coordinate. 
 **********************************************************************/
void Bullet::destroyLaser()
{
   Point temp = getVel().getPt();
   
   if (temp.getX() < -200)
      kill();

   if (temp.getX() > 200)
      kill();
  
   if (temp.getY() < -200)
      kill();  
   
   if (temp.getY() > 200)
      kill();  
}

/***********************************************************************
 * Draws a bullet on the screen. If we want to draw a laser instead of
 * a bullet then uncomment the draw line function and comment out the
 * draw dot function.
 **********************************************************************/
void Bullet::draw()
{
   drawDot(getVel().getPt());

   // for the laser.
   //drawLine(getVel().getPt(), (getVel().getDx(), getVel().getDy()),  1, 0, 0);
}

/***********************************************************************
 * Advances the bullets 5 pixels more then the velocity of the ship. Fires
 * them in the direction the ship is pointing in.
 **********************************************************************/
void Bullet::advance()
{
   if (incr <= 10)
   {
      if (incr == 0)
         incr += 0.5;
      incr *= BULLET_SPEED;
   }
   float dx = (float)incr * (-cos((float)M_PI / 180.0 * (rotation - 90)));
   float dy = (float)incr * (sin((float)M_PI / 180.0 * (rotation + 90)));

   addVelDx(dx); 
   addVelDy(dy);
}

// Put your bullet methods here
