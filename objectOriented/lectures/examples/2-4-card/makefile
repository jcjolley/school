###############################################################
# Program:
#     Lesson 24, Demo for Card class
#     Brother Helfrich, CS165
# Author:
#     Br. Helfrich
# Summary:
#     These files are designed to demonstrate the principles of
#     encapsulation.  This includes how do do the various types
#     of operator overloading.  
##############################################################

##############################################################
#         cardTest : Test the card class
###############################################################
cardTest : cardTest.o card.o
	g++ -o cardTest card.o cardTest.o

###############################################################
# Individual files
###############################################################
card.o : card.cpp card.h
	g++ -c card.cpp

cardTest.o : cardTest.cpp card.h card.cpp
	g++ -c cardTest.cpp

###############################################################
# General rules
###############################################################
clean :
	rm cardTest *.o 

all : cardTest

