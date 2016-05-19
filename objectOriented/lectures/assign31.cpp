/***********************************************************************
* Program:
*    Assignment 31, Building Polymorphism
*    Brother Helfrich, CS165
* Author:
*    your name
* Summary: 
*    This program will demonstrate the implementation of polymorphism
*    based on two procedural tools: pointers to functions, and structures.
*
*    Your assignment is to create three functions which may be binded
*    to our Piece structure:
*            getLetterKing():  Return 'K' or 'k' depending on color
*            getLetterQueen(): Return 'Q' or 'q'
*            getLetterPawn():  Return 'P' or 'p'
*    Each of these three functions is prototyped in the driver program.
*    Next, create a fourth function which will perform the binding.
*    In our case, we will need to bind pPiece->getPiece with our various
*    getPieceKing() function
*
*    Estimated:  0.0 hrs   
*    Actual:     0.0 hrs
*      Please describe briefly what was the most difficult part
************************************************************************/

#include <iostream>
#include <cassert>
using namespace std;

enum PieceType {NONE, KING, QUEEN, PAWN};

// forward declaration because both Date and VTableDate point to each other
struct Piece;  

/****************************************
 * V-TABLE PIECE
 *  The Virtual Method Table for Piece
 ***************************************/
struct VTablePiece
{
   char (*getLetter)(const Piece *pThis);
};

/****************************************
 * Piece
 *  Our home-made class.  You are not allowed
 *  to change the definition of Piece in any way
 ***************************************/
struct Piece
{
   VTablePiece *__vtptr;

   bool isWhite;
};


/****************************************
 * OUT << PIECE
 * Display the contents of a piece
 ****************************************/
ostream & operator << (ostream & out, const Piece & piece)
{
   out << piece.__vtptr->getLetter(&piece);
   
   return out;
}

/****************************************
 * GET LETTER KING
 * Return a 'k' or 'K' depending on side
 ***************************************/
char getLetterKing(const Piece * pThis)
{
   return (pThis->isWhite) ? 'k' : 'K';
}

/****************************************
 * GET LETTER QUEEN
 * Return a 'q' or 'Q' depending on side
 ***************************************/
char getLetterQueen(const Piece * pThis)
{
   return (pThis->isWhite) ? 'q' : 'Q';
}

/****************************************
 * GET LETTER PAWN
 * Return a 'p' or 'P' depending on side
 ***************************************/
char getLetterPawn(const Piece * pThis)
{
   return (pThis->isWhite) ? 'p' : 'P';
}

/***********************************************
 * BIND.   Attach the appropriate v-table to the Piece object 
 *  INPUT  Piece                Which display function will I call
 *         isWhite              Which side am I on
 *  OUTPUT 
 ***********************************************/
void bind(Piece * pThis, PieceType pt, bool isWhite)
{
   pThis->isWhite = isWhite;
   
   // your code goes here
}

/**********************************************************************
 * MAIN is designed to use our home-made class called Piece.  You are not
 *   allowed to change the definition of Piece nor modify any code in MAIN
 ***********************************************************************/
int main()
{
   // Set up the structure.  Note how we have to manually
   // specify the member functions in Initialize(); something
   // a real class will do for us at instantiation time
   Piece pieces[6];
   bind(&(pieces[0]),  PAWN , false /*black*/);
   bind(&(pieces[1]),  QUEEN, false /*black*/);
   bind(&(pieces[2]),  KING , false /*black*/);
   bind(&(pieces[3]),  PAWN , true  /*white*/);
   bind(&(pieces[4]),  QUEEN, true  /*white*/);
   bind(&(pieces[5]),  KING , true  /*white*/);

   // display the pieces. Note how the correct version of getLetter
   // will be called
   for (int i = 0; i < 6; i++)
      cout << pieces[i] << endl;

   return 0;
}
