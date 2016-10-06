###############################################################
# Program:
#     Project 4, Asteroids
#     Brother McCracken, CS165
# Author:
#     Ben Wright
# Summary:
#     This is a program that generates the game Asteroids. In
#     here we use inheritance, polymorphism, and encapsulation
#     to control all the physics of the game. We have a UFO class,
#     the parent class, and derived classes of Ship, Bullet, Star,
#     Rock, with it's derived classes: BigRock, MediumRock, and
#     SmallRock. The ship first starts off at the coordinates (0,0)
#     and five asteroids are drawn in random coordinates and are given
#     a random direction to advance in. The user controls all the
#     movements of the ship and the direction it want to fire bullets
#     in. When a bullet collides with an asteroid, then the asteroid 
#     and bullet will be destroyed. If a ship collides with an asteroid
#     then the ship will stop in motion and it will be game over.
# Hardest Part:
#     It took me a long time to figure out how to control the velocity
#     of the ship and the angle it advanced on. I almost half my project
#     trying to figure that out, then once I did, it was easier to do
#     the same thing with the velocity of the stars, asteroids, and
#     bullets. I would then say the hardest part was trying to figure
#     out the break apart function. I did everything I could do but the
#     large asteroids would break into medium asteroids. You can looking
#     in my break apart function in rocks.cpp to see everything that I
#     was trying to do. Once a big asteroid was destroyed, it would draw
#     a medium asteroid in it's same spot but then it also gets destroyed
#     with the big asteroid. Once a bullet hits an asteroid it kills the
#     the bullet. I have no idea why the bullet destroyed the medium 
#     asteroid as well. If I could of figured this out then the project
#     would meet all of the requirements. I also couldn't figure out how
#     make the ship disappear after it collides with an asteroid, however
#     it will stop the ship if that happens and the user will not be able
#     to move it anymore. Also if the ship doesn't move when you first
#     execute a.out, then that means it was spawn killed, so restart the
#     game.  
# Above and Beyond:
#     I worked on this project all by myself without a laptop. My
#     hardrive got ruined and I was without a laptop for the last
#     two weeks of school. My only source to work on this was
#     the linux lab on campus during its opened hours.
#
#     I made a Star class so that the game can have shooting stars.
#     this is to help the user feel that he/she is playing a
#     video game in space.
#
#     I made an option to shoot lasers instead of bullets. To
#     change whether you want to switch between lasers and bullets,
#     go to the draw function in the bullet class and comment out
#     the draw function and uncomment the draw line function.
#     Note: I couldn't seem to figure out why the lasers start
#     position wasn't the same as the ships position. It was
#     if you fired bullets but not lasers. The starting position
#     was set at (0,0). However it will still fire in the direction
#     that the ship is facing and it will destroy asteroids.
###############################################################


LFLAGS = -lglut -lGLU -lGL

###############################################################
# Build the main game
###############################################################
a.out: game.o uiInteract.o uiDraw.o point.o velocity.o flyingObject.o ship.o bullet.o rocks.o star.o
	g++ game.o uiInteract.o uiDraw.o point.o velocity.o flyingObject.o ship.o bullet.o rocks.o star.o $(LFLAGS)
	tar -cf project4.tar *.h *.cpp makefile

###############################################################
# Individual files
#    uiDraw.o       Draw polygons on the screen and do all OpenGL graphics
#    uiInteract.o   Handles input events
#    point.o        The position on the screen
#    game.o         Handles the game interaction
#    velocity.o     Velocity (speed and direction)
#    flyingObject.o Base class for all flying objects
#    ship.o         The player's ship
#    bullet.o       The bullets fired from the ship
#    rocks.o        Contains all of the Rock classes
#    star.o         Shooting Stars flying across the screen.
###############################################################
uiDraw.o: uiDraw.cpp uiDraw.h
	g++ -c uiDraw.cpp

uiInteract.o: uiInteract.cpp uiInteract.h
	g++ -c uiInteract.cpp

point.o: point.cpp point.h
	g++ -c point.cpp

game.o: game.cpp game.h uiDraw.h uiInteract.h point.h flyingObject.h 
	g++ -c game.cpp

velocity.o: velocity.cpp velocity.h point.h
	g++ -c velocity.cpp

flyingObject.o: flyingObject.cpp flyingObject.h point.h velocity.h uiDraw.h
	g++ -c flyingObject.cpp

ship.o: ship.cpp flyingObject.h point.h velocity.h uiDraw.h
	g++ -c ship.cpp

bullet.o: bullet.cpp flyingObject.h point.h velocity.h uiDraw.h
	g++ -c bullet.cpp

rocks.o: rocks.cpp flyingObject.h point.h velocity.h uiDraw.h
	g++ -c rocks.cpp

star.o: star.cpp flyingObject.h
	g++ -c star.cpp

###############################################################
# General rules
###############################################################
clean:
	@rm -f *.0 a.out *.cpp~ *.h~ makefile~ *tar *compile *.o
	clear
