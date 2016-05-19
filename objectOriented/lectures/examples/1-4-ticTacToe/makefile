###############################################################
# Program:
#     Example 1.4, Complex Numbers demo
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
a.out: file.o interface.o game.o ticTacToe.o
	g++ file.o interface.o game.o ticTacToe.o
	tar -cf example14.tar *.h *.cpp makefile

##############################################################
# The individual components
##############################################################

file.o : file.cpp file.h ticTacToe.h
	g++ -c file.cpp

interface.o : interface.cpp interface.h ticTacToe.h
	g++ -c interface.cpp

game.o : game.cpp game.h ticTacToe.h
	g++ -c game.cpp

ticTacToe.o : ticTacToe.cpp ticTacToe.h
	g++ -c ticTacToe.cpp
