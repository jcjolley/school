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
#         a.out : Test the card class
###############################################################
a.out : cardTest.o card.o
	g++ -o a.out card.o cardTest.o

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
	rm a.out *.o

all : a.out

###############################################################
# Ref: http://www.gnu.org/software/make/manual/make.html
###############################################################