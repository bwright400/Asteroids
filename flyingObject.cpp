#include "flyingObject.h"

/***********************************************************************
 * Wrap function. Mad this a member of the UFO class since all UFO's wrap
 * the same way. This will wrap an object to the other side of the screen.
 **********************************************************************/
void UFO:: wrap()
{
   Point temp = getVel().getPt();
   
   if (temp.getX() < -200)
      setX(199);

   if (temp.getX() > 200)
      setX(-199);
  
   if (temp.getY() < -200)
      setY(199);  
   
   if (temp.getY() > 200)
      setY(-199);
}



// Put your FlyingObject method bodies here
