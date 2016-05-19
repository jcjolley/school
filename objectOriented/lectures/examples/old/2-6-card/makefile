###############################################################
# Program:
#     Section 2.6, Demo
#     Brother Helfrich, CS165
# Author:
#     Br. Helfrich
# Summary:
#     These files are designed to demonstrate the principles of
#     encapsulation.  This includes how do do the various types
#     of operator overloading.  
#
#     I hope this helps with the assignments of Section 2
##############################################################

##############################################################
#         war      : Play the game of war
#         cardTest : Test the card class
###############################################################
war : playGame.o war.o card.o hand.o
	g++ -o war playGame.o war.o card.o hand.o
	tar -cf war.tar *.h *.cpp makefile

cardTest : cardTest.o card.o
	g++ -o cardTest card.o cardTest.o

###############################################################
# Individual files
###############################################################
playGame.o : playGame.cpp war.h hand.h card.h
	g++ -c playGame.cpp

war.o : war.cpp card.h hand.h war.h
	g++ -c war.cpp

hand.o : hand.cpp hand.h card.h
	g++ -c hand.cpp

card.o : card.cpp card.h
	g++ -c card.cpp

cardTest.o : cardTest.cpp card.h card.cpp
	g++ -c cardTest.cpp

###############################################################
# General rules
###############################################################
clean :
	rm war cardTest *.o war.tar

all : war cardTest

###############################################################
# Ref: http://www.gnu.org/software/make/manual/make.html
###############################################################