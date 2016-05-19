###############################################################
# Program:
#     Example 1.5, Complex Numbers demo
#     Brother Helfrich, CS165
# Author:
#     Br. Helfrich
# Summary:
#     This program will demonstrate how to break a large program 
#     into several small and managable files
###############################################################

##############################################################
# The main rule
##############################################################
a.out: complexTest.o complex.o
	g++ -o a.out complexTest.o complex.o
	tar -cf example14.tar *.h *.cpp makefile

##############################################################
# The individual components
#      complex.o      : Compile only if complex.cpp or complex.h changed
#      complexTest.o  : Compile only if complextTest.cpp or complex.h changed
##############################################################
complexTest.o: complexTest.cpp complex.h
	g++ -c complexTest.cpp

complex.o: complex.cpp complex.h
	g++ -c complex.cpp
