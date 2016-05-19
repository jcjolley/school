###############################################################
# The main programs are:
#    dateTest   : test the date structure and functions
###############################################################
a.out : dateTest.o date.o
	g++ -o a.out dateTest.o date.o

###############################################################
# Individual files
###############################################################
date.o : date.cpp date.h
	g++ -c date.cpp

dateTest.o : dateTest.cpp date.h
	g++ -c dateTest.cpp

###############################################################
# General rules
###############################################################
clean :
	rm a.out *.o

all :  a.out

###############################################################
# Ref: http://www.gnu.org/software/make/manual/make.html
###############################################################