#######################################################################
# Program:
#    Assignment 26, Non-Member Overloading
#    Brother Helfrich, CS165
# Author:
#    Joshua Jolley
# Summary: 
#    Displays the date given using a class
#    Estimated:  1.0 hrs   
#    Actual:     0.3 hrs
#    Because I had last class' assignment done this was easy.
########################################################################
###############################################################
# The main program is:
#    currentDriverp
###############################################################
a.out : date.o currentDriver.o
	g++ -o a.out currentDriver.o date.o
	tar -cf currentDriver.tar *.h *.cpp makefile
	make clean

###############################################################
# Individual files
###############################################################
date.o : date.cpp date.h
	g++ -c date.cpp
currentDriver.o : currentDriver.cpp date.h
	g++ -c currentDriver.cpp

###############################################################
# General rules
###############################################################
clean :
	rm *.o

all :  a.out

###############################################################
# Ref: http://www.gnu.org/software/make/manual/make.html
###############################################################