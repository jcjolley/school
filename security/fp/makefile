CC = g++
CFLAGS = -g -Wall -std=c++11

main: stringTest.cpp String.o
	$(CC) $(CFLAGS) -o driver.out stringTest.cpp String.o
String.o: String.cpp String.h
	$(CC) $(CFLAGS) -c String.cpp	
clean:
	rm *.o *.out
