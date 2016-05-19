#######################################################################
# Program:
#    Project 1, (Chess)
#    Brother Helfrich, CS165
# Author:
#    Joshua Jolley
# Summary: 
#    Plays Chess, loading a file, saving a file, displaying the board
#    in color.  Does not enforce rules.
#    Estimated:  8.0 hrs   
#    Actual:     13.0 hrs
#      Getting the design together was the hardest part... and splitting
#      the file
########################################################################

### Chess Program ###
a.out: chess.o saveGame.o loadGame.o display.o interact.o movePiece.o
	g++ -o a.out chess.o saveGame.o loadGame.o display.o interact.o movePiece.o
	tar -cf prj1chess.tar *.h *.cpp makefile
	make clean

### main and reset board functions ###
chess.o: chess.cpp chess.h interact.h display.h
	g++ chess.cpp -c

### interact and listMoves functions ###
interact.o: interact.cpp interact.h display.h loadGame.h saveGame.h
	g++ interact.cpp -c

### displayBoard, displayTest, and displayOptions functions ###
display.o: display.cpp display.h
	g++ display.cpp -c

### getFilename, readFile, and loadGame functions ###
loadGame.o: loadGame.cpp loadGame.h movePiece.h chess.h
	g++ loadGame.cpp -c

### getSavename, writeFile and saveGame functions ###
saveGame.o: saveGame.cpp saveGame.h
	g++ saveGame.cpp -c

### isInvalidMove, convertMove, makeMove, and movePiece functions ###
movePiece.o: movePiece.cpp movePiece.h
	g++ movePiece.cpp -c

### clean up the .o files ###
clean: 
	rm *.o