#ifndef VELOCITY_H
#define VELOCITY_H

#include "point.h"
/*********************************************
 * VELOCITY
 *     Direction and speed for the points.
 *********************************************/
class Velocity
{
  public:
  Velocity() : pt(pt), dx(0), dy(0) {} ;                    //constructors

   Point & getPt() {return pt;}

   void addDx(float dx) { pt.addX(dx); }
   void addDy(float dy) { pt.addY(dy); }

   void setDx(float x) {pt.setX(x);}                       
   void setDy(float y) {pt.setY(y);}                       

   float getDx() const { pt.getX(); };                    //copy x to a new x
   float getDy() const { pt.getY(); };                    //copy y to a new y

  private:
   Point pt;
   float dx;
   float dy;

};
// Put your velocity class here, or overwrite this file with your own
// velocity class from the previous project


#endif /* velocity_h */
