#ifndef flyingObject_h
#define flyingObject_h

#include <list>

#include "velocity.h"
#include "point.h"
#include "uiInteract.h"
#include "uiDraw.h"
using namespace std;


/***********************************************************************
 * The base class in our flying object file. Everything that is drawn and
 * that advances are all a UFO's.
 **********************************************************************/
class UFO
{
  public:
   //constructors & destructors
  UFO(): rotation(5), alive(true), incr(0.f) {}
  UFO(Point pt): pt(0), alive(true) {}
   ~UFO() {}

   virtual void advance() = 0;
   virtual void draw() = 0;
   void wrap();
   
   // getters
   Interface getUI() const {return ui;}
   Point getPoint() const {return pt;} 
   bool isAlive() const {return alive;}
   Velocity getVel() const {return vel;}
   float getSize() const { return size;}


   //setters
   void kill(){ alive = false; }
   Velocity addVelDx(float dx) {vel.addDx(dx);}
   Velocity addVelDy(float dy) {vel.addDy(dy);}
   void setX(float x) {vel.setDx(x);}
   void setY(float y) {vel.setDy(y);}
   
  protected:
   Point pt;
   int rotation;
   float incr;
   int size;
   bool alive;
    
  private:
   bool dead;
   Velocity vel;
   Interface ui;
};

/***********************************************************************
 * Ship Class. A derived class of UFO that controls all the physic
 * properties of the ship
 **********************************************************************/
#define SHIP_SIZE 10

#define ROTATE_AMOUNT 6
#define THRUST_AMOUNT 0.5

class Ship : public UFO
{
  public:
  Ship(): UFO(incr) {size = SHIP_SIZE;}
  Ship(Point pt): UFO(incr) {}
   ~Ship() {}
   void draw();
   int turnLeft();
   int turnRight();
   void thrust();
   void de_thrust();
   void advance() {}
  private:
   
};

/***********************************************************************
 * Bullet Class. A derived class of UFO that controls all the physic
 * properties of the bullet.
 **********************************************************************/

#define BULLET_SPEED 5
#define BULLET_LIFE 40

class Bullet : public UFO
{
  public:
   //Bullet() {}
   Bullet(Ship & pShip);
  Bullet(Point pt): UFO(pt) {}
   ~Bullet() {}
   void draw();
   void advance();
   void destroyLaser();
  private:
};

/***********************************************************************
 * Star Class. A derived class of UFO that controls all the physic
 * properties of the shooting stars.
 **********************************************************************/
#define SHOOTING_STAR_SPEED 10

class Star : public UFO
{
  public:
    Star();
    Star(Point p1);
    void draw();
    void advance();
    void angle();
  private:
    int rand;
  
};

/***********************************************************************
 * Rock Class. A derived class of UFO and a base class of all rocks
 * that controls all the physic properties of the asteroids.
 **********************************************************************/
#define BIG_ROCK_SIZE 16
#define MEDIUM_ROCK_SIZE 8
#define SMALL_ROCK_SIZE 4

#define BIG_ROCK_SPIN 2
#define MEDIUM_ROCK_SPIN 5
#define SMALL_ROCK_SPIN 10

class Rock : public UFO
{
  public:
   Rock();
   Rock(Point pt);
   virtual void draw() = 0;
   void breakApart(list<Rock*>);
   virtual void advance() = 0;
   Point getRandomPoint() const;
   void angle();


  protected:
   //Point pt;
   int rand;
   
  private:
   
      
};

/***********************************************************************
 * BigRock Class. A derived class of Rock that controls all the physic
 * properties of the big asteroids.
 **********************************************************************/
class BigRock : public Rock
{
  public:
   BigRock() {}
   BigRock(Point pt);
   void advance();
   void draw() {drawLargeAsteroid(getVel().getPt(), BIG_ROCK_SPIN);}
  private:
};

/***********************************************************************
 * MediumRock Class. A derived class of Rock that controls all the physic
 * properties of the medium asteroids.
 **********************************************************************/
class MediumRock : public Rock
{
  public:
   MediumRock(Point pt);
   void advance();
   void draw() {drawMediumAsteroid(this->getVel().getPt(), MEDIUM_ROCK_SPIN);}
  private:
};

/***********************************************************************
 * SmallRock Class. A derived class of Rock that controls all the physic
 * properties of the small asteroids.
 **********************************************************************/
class SmallRock : public Rock
{
  public:
   SmallRock(Point pt);
   void advance();
   void draw() {drawSmallAsteroid(getVel().getPt(), SMALL_ROCK_SPIN);}
  private:
};


#endif /* flyingObject_h */
