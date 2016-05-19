a.out : complexTest.o complex.o
	g++ -o a.out complexTest.o complex.o

complexTest.o : complexTest.cpp complex.h
	g++ complexTest.cpp -c

complex.o : complex.h complex.cpp 
	g++ complex.cpp -c

