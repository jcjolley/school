###############################################################
# Program:
#     Lesson 2.65, Demo for Array class
#     Brother Helfrich, CS165
# Author:
#     Br. Helfrich
# Summary:
#     This example is meant to demonstrate how to create a
#     simple container class: arrays.  This is similar to the
#     vector class
##############################################################

##############################################################
#         arrayTest : Test the array class
###############################################################
a.out : arrayTest.o array.o
	g++ array.o arrayTest.o

###############################################################
# Individual files
###############################################################
array.o : array.h array.cpp
	g++ -c array.cpp

arrayTest.o : array.h arrayTest.cpp
	g++ -c arrayTest.cpp

###############################################################
# General rules
###############################################################
clean :
	rm a.out *.o 

all : a.out

