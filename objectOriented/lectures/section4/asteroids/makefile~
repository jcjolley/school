###############################################################
# Program:
#     Project 2, Skeet Game
#     Brother Grimmett, CS165
# Author:
#     Biff Henderson
#     
# Summary:
#     Enter a brief description of your program here! If you do any
#     extra credit, this would be a good place to describe it.
#
#     Estimated:  0.0 hrs
#     Actual:     0.0 hrs
#       Please describe briefly what was the most difficult part
###############################################################

###############################################################
# Programs:
#    skeet:         The playable game
#    uiTest:       Simple driver program for the drawing interface
###############################################################
skeet : skeet.o uiInteract.o uiDraw.o point.o vector.o gameEntities.o
	g++ -o skeet skeet.o uiInteract.o uiDraw.o point.o vector.o gameEntities.o -lglut -lGLU
	tar -cf skeet.tar *.cpp *.h makefile

uiTest : uiTest.o uiDraw.o uiInteract.o point.o vector.o
	g++ -o uiTest uiTest.o uiDraw.o uiInteract.o point.o vector.o -lglut -lGLU

###############################################################
# Individual files
#    uiDraw.o      Draw polygons on the screen and do all OpenGL graphics
#    uiInteract.o  Handles input events
#    point.o       The position on the screen
#    vector.o      The Vector (Direction and magnitude)
#    gameEntities.o The different entities for the game
#    uiTest.o      Driver program for uiDraw and uiTest
#    skeet.o       Skeet game  
###############################################################
uiInteract.o : uiInteract.cpp uiInteract.h point.h
	g++ -c uiInteract.cpp

uiDraw.o : uiDraw.cpp uiDraw.h point.h
	g++ -c uiDraw.cpp

point.o : point.cpp point.h
	g++ -c point.cpp

vector.o : vector.cpp vector.h
	g++ -c vector.cpp

gameEntities.o : gameEntities.cpp gameEntities.h
	g++ -c gameEntities.cpp

uiTest.o : uiTest.cpp point.h vector.h uiDraw.h uiInteract.h
	g++ -c uiTest.cpp

skeet.o : skeet.cpp uiDraw.h uiInteract.h point.h vector.h gameEntities.h
	g++ -c skeet.cpp


###############################################################
# General rules
###############################################################
clean :
	rm uiTest skeet *.o *.tar

all :  uiTest skeet

