################################################
# Chess Makefile
# Authors: Sam and Jolley
# 
#
################################################
SOURCES= main.cpp
OBJECT=$(SOURCES:.cpp=.o)
a.out: $(OBJECTS)
	g++ *.cpp 
	tar -cf project3.tar *.cpp *.h makefile

%.o: %.cpp
	g++ -c $<
