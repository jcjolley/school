###############################################################
# Program:
#     Lesson 25, Demo for Point class
#     Brother Helfrich, CS165
# Author:
#     Br. Helfrich
# Summary:
#     This example is meant to demonstrate how to use static
#     to help all object of a given class share the same
#     member variablles
##############################################################

##############################################################
#         cardTest : Test the card class
###############################################################
a.out : pointTest.o point.o
	g++ point.o pointTest.o

###############################################################
# Individual files
###############################################################
point.o : point.cpp point.h
	g++ -c point.cpp

pointTest.o : point.h pointTest.cpp
	g++ -c pointTest.cpp

###############################################################
# General rules
###############################################################
clean :
	rm a.out *.o 

all : a.out

