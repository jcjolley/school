###############################################################
# Program:
#     Lecture 3.4, Card game demo
#     Brother Helfrich, CS165
# Author:
#     Br. Helfrich
# Summary:
#     This program is designed to demonstrate inheritance and
#     polymorphism in the const of a card class.
###############################################################

###############################################################
# The main programs are:
#    cardTest : Validate our card class
###############################################################
cardTest : cardTest.o card.o
	g++ -o cardTest card.o cardTest.o

###############################################################
# Individual files
#    card.o      : Everything working with a single playing card
#    cardTest.o  : Driver program for card.o
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

