###############################################################
# Program:
#     Lesson 24, Demo for Card class
#     Brother Helfrich, CS165
# Author:
#     Br. Helfrich
# Summary:
#     These files are designed to demonstrate how to use the
#     static modifier in member variables
##############################################################

##############################################################
#         cardTestLow.out:  When aces are low (below the two)
#         cardTestHigh.out: When aces are high (above the King)
###############################################################
cardTestLow.out : cardTestLow.o card.o
	g++ -o cardTestLow.out card.o cardTestLow.o

cardTestHigh.out : cardTestHigh.o card.o
	g++ -o cardTestHigh.out card.o cardTestHigh.o

###############################################################
# Individual files
###############################################################
card.o : card.cpp card.h
	g++ -c card.cpp

cardTestLow.o : cardTestLow.cpp card.h 
	g++ -c cardTestLow.cpp

cardTestHigh.o : cardTestHigh.cpp card.h 
	g++ -c cardTestHigh.cpp

###############################################################
# General rules
###############################################################
clean :
	rm cardTestLow.out cardTestHigh.out *.o 

all : cardTestLow.out cardTestHigh.out

