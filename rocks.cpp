#include "flyingObject.h"
#include <cmath>


/***********************************************************************
 * Constructor for Rock. Intializes a random degree for the rocks to
 * travel in.
 **********************************************************************/
Rock::Rock(): rand(rand)
{
   rand = random(-360,360);
}

/***********************************************************************
 * Constructor for Rock. Passes in a random point for the rocks to start
 * at.
 **********************************************************************/
Rock::Rock(Point pt): rand(rand)
{
   setX(pt.getX());
   setY(pt.getY());
}

/***********************************************************************
 * Checks what the size of the rock is. It breaks it apart into two
 * other rocks the next size down.
 **********************************************************************/
void Rock::breakApart(list<Rock*> rock)
{
   if (this->getSize() == BIG_ROCK_SIZE)
   {
      isAlive();
      for (int i = 0; i < 3; i++)
      {
         MediumRock * pRock = new MediumRock(getVel().getPt());
         rock.clear();
         rock.push_back(pRock);
         pRock->isAlive();
         pRock->advance();
         pRock->draw();
      }
      //sleep(1);
      //for (list<Rock*>::iterator mRock = rock.begin();
      //   mRock != rock.end();
      //   mRock++)
      //{
         //(*mRock)->isAlive();
         //(*mRock)->advance();
         //(*mRock)->draw();
         //}
      
      //cout << "killed big rock\n";
   } 
   
   if (this->getSize() == MEDIUM_ROCK_SIZE)
   {
      isAlive();
      for (int i = 0; i < 2; i++)
      {
         SmallRock * pRock = new SmallRock(getVel().getPt());
         rock.clear();
         rock.push_back(pRock);
      }
      //sleep(1);
      for (list<Rock*>::iterator mRock = rock.begin();
           mRock != rock.end();
           mRock++)
      {
         //(*mRock)->isAlive();
         (*mRock)->advance();
         (*mRock)->draw();
      }
   }
   if (this->getSize() == SMALL_ROCK_SIZE)
      rock.clear();
}

/***********************************************************************
 * Controls the angle in which the rock is moving
 **********************************************************************/
void Rock::angle()
{
   float dx = (float)incr * (-cos((float)M_PI / rand * (rotation - 90)));
   float dy = (float)incr * (sin((float)M_PI / rand * (rotation + 90)));

   addVelDx(dx); 
   addVelDy(dy);   
}

/***********************************************************************
 * Controls the velocity of the BigRock.
 **********************************************************************/
void BigRock::advance()
{
   if (incr <= 2)
   {
      if (incr == 0)
         incr += 0.2;
      incr *= 2;
   }
   angle();
}

/***********************************************************************
 * Controls the velocity of the MediumRock.
 **********************************************************************/
void MediumRock::advance()
{
   if (incr <= 4)
   {
      if (incr == 0)
         incr += 0.2;
      incr *= 2;
   }
   angle();
}

/***********************************************************************
 * Controls the velocity of the SmallRock.
 **********************************************************************/
void SmallRock::advance()
{
   if (incr <= 8)
   {
      if (incr == 0)
         incr += 0.2;
      incr *= 2;
   }
   angle();
}

/***********************************************************************
 * Constructor that intializes the size of the BigRock.
 **********************************************************************/
BigRock::BigRock(Point pt): Rock(pt)
{
   size = BIG_ROCK_SIZE;
}

/***********************************************************************
 * Constructor that intializes the size of the MediumRock.
 **********************************************************************/
MediumRock::MediumRock(Point pt): Rock(pt)
{
   size = MEDIUM_ROCK_SIZE;
}

/***********************************************************************
 * Constructor that intializes the size of the SmallRock.
 **********************************************************************/
SmallRock::SmallRock(Point pt): Rock(pt)
{
   size = SMALL_ROCK_SIZE;
}





// Put your Rock methods here
