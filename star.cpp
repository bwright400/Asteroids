#include "flyingObject.h"
#include <cmath>

/***********************************************************************
 * Default Constructor for Star. Initalizes a random degree for star to
 * travel in.
 **********************************************************************/
Star::Star(): rand(rand)
{
   rand = random(-360,360);
}

/***********************************************************************
 * Non-Default constructor. passes in a point for where the stars will
 * start at.
 **********************************************************************/
Star::Star(Point p1): rand(rand)
{
   setX(p1.getX());
   setY(p1.getY());
}

/***********************************************************************
 * Generates the direction in which the star in pointing to.
 **********************************************************************/
void Star::angle()
{
   float dx = (float)incr * (-cos((float)M_PI / rand * (rotation - 90)));
   float dy = (float)incr * (sin((float)M_PI / rand * (rotation + 90)));

   addVelDx(dx); 
   addVelDy(dy);   
} 

/***********************************************************************
 * Advances the stars with a velocity, and then calls the angle function.
 **********************************************************************/
void Star::advance()
{
   if (incr <= 20)
   {
      if (incr == 0)
         incr += 1;
      incr *= 2;
   }
   angle();
}

/***********************************************************************
 * Draws the stars on the OpenGL screen.
 **********************************************************************/
void Star::draw()
{
   drawPolygon(getVel().getPt(), 3, 3, 10);
}
