###############################################################
# Program:
#     Lesson 24, Demo for Write class
#     Brother Helfrich, CS165
# Author:
#     Br. Helfrich
# Summary:
#     Just exercise our simple Write class
##############################################################

##############################################################
#         a.out : Test the Write class
###############################################################
a.out : writeTest.o write.o
	g++ write.o writeTest.o

###############################################################
# Individual files
###############################################################
write.o : write.cpp write.h
	g++ -c write.cpp

writeTest.o : writeTest.cpp write.h write.cpp
	g++ -c writeTest.cpp

###############################################################
# General rules
###############################################################
clean :
	rm a.out *.o 

all : a.out

