/***********************************************************************
* Program:
*    Project 1, (Chess)
*    Brother Helfrich, CS165
* Author:
*    Joshua Jolley
* Summary: 
*    
*    Estimated:  4.0 hrs   
*    Actual:     0.0 hrs
*      Please describe briefly what was the most difficult part
************************************************************************/

#include <iostream>
#include <cstdlib>
#include <cassert>
#include <cctype>
#include <string>
#include <fstream>
using namespace std;

#ifdef DEBUG
#define debug(x) cout << #x << ": " << x << endl;
#else
#define debug(x)
#endif

void interact(char board[][8][8]);
bool displayTest(const char board[][8][8]);
void displayBoard(const char board[][8][8]);
void displayOptions();
void listMoves(const int turn, const string move, string moves[]);
bool loadGame(int &turn, string moves[], char board[][8][8]);
void getFilename(string &filename);
bool readFile(string moves[], int &numMoves, const string filename);
void quitGame(const string moves[], const int turn);
void getSavename(string &filename);
void writeFile(const string moves[], const string filename, const int turn);
bool movePiece(int turn, string move, char board[][8][8], string filename);
bool movePiece(const int turn, const string move, char board[][8][8]);
int isInvalidMove(const string move, const char board[][8][8]);
void convertMove(const string move, int &startRow, int &startCol,
                 int &endRow, int &endCol, bool &isCastle);
void makeMove(const int startRow, const int startCol, const int endRow,
              const int endCol, const int turn, const bool isCastle,
              char board[][8][8]);
void resetBoard(char board[][8][8]);
/**********************************************************************
* Main
* This is the driver function.  It initializes the board and passes it
* off to interact.
***********************************************************************/
int main()
{
   char board[2][8][8] =
      {
         'R','N','B','Q','K','B','N','R',
         'p','p','p','p','p','p','p','p',
         ' ',' ',' ',' ',' ',' ',' ',' ',
         ' ',' ',' ',' ',' ',' ',' ',' ',
         ' ',' ',' ',' ',' ',' ',' ',' ',
         ' ',' ',' ',' ',' ',' ',' ',' ',
         'p','p','p','p','p','p','p','p',
         'R','N','B','Q','K','B','N','R',
         
         'b','b','b','b','b','b','b','b',
         'b','b','b','b','b','b','b','b',
         ' ',' ',' ',' ',' ',' ',' ',' ',
         ' ',' ',' ',' ',' ',' ',' ',' ',
         ' ',' ',' ',' ',' ',' ',' ',' ',
         ' ',' ',' ',' ',' ',' ',' ',' ',
         'w','w','w','w','w','w','w','w',
         'w','w','w','w','w','w','w','w',
      };
   
   displayBoard(board);
   interact(board);
   
        return 0;
}
/**********************************************************************
 * interact
 * This function controls all user interaction. It uses a while loop
 * to continue until the user inputs 'quit'
 **********************************************************************/
void interact(char board[][8][8])
{
   bool test = false;
   int turn = 0;
   string moves[256] = {" "};
   string move = "filler";
   
   while (move != "quit")
   {
      if (turn %2 == 0)
         cout << "(White): ";
      else
         cout << "(Black): ";
      debug(turn);
      cin  >> move;
      
      if (move.compare("?") == 0)
         displayOptions();
      else if (move.compare("read") == 0)
      {
         if(loadGame(turn,moves,board))
         {
            if(!test)
               displayBoard(board);
            else
               displayTest(board);
         }
      }
      else if (move.compare("test") == 0)
         test = displayTest(board);
      else if (move.compare("quit") == 0)
         quitGame(moves, turn);
      else
      {
         if (movePiece(turn,move,board))
         {
            listMoves(turn,move,moves);
            turn++;
            if(!test)
               displayBoard(board);
            else
               displayTest(board);
         }
      }
      
   }
}


/**********************************************************************
 *displayTest
 *shows the display without all the fancy colors and spacing
 **********************************************************************/
bool displayTest(const char board[][8][8])
{

   cout << "  abcdefgh\n";
   for (int row = 0; row <8; row++)
      for (int col = 0; col < 8; col++)
      {
         if (col == 0)
            //the rows are backwards, this math sets it right
            cout << row + (7 - (2 * row)) + 1 << " ";
         if (board[1][row][col] == 'w') //if it is white
            cout << (char)tolower(board[0][row][col]); //make it lowercase
         else if (board[1][row][col] == 'b') //if it's black
            cout << (char)toupper(board[0][row][col]); //uppercase!
         else
            cout << board[0][row][col];  //if it's empty, who cares? ;)
         if (col == 7)
            cout << endl;
      }
                            
   return true;
}

/**********************************************************************
 *displayBoard
 *displays the chessboard and pieces in fancy colors
 **********************************************************************/
void displayBoard(const char board[][8][8])
{
   system("clear");
   cout << "   a  b  c  d  e  f  g  h \n";
   for (int row = 0; row <8; row++)
      for (int col = 0; col < 8; col++)
      {
         if (col == 0)
            cout << row + (7 - (2 * row)) + 1 << " ";  
         if (row %2 == 0 && col %2 == 0 && board[1][row][col] == 'w')
            cout << "\E[31;47m" << " " << board[0][row][col] << " "
                 << "\E[0m";
         if (row %2 == 0 && col %2 != 0 && board[1][row][col] == 'w')
            cout << "\E[37;41m " << board[0][row][col] << " \E[0m";
          if (row %2 == 0 && col %2 == 0 && board[1][row][col] == 'b')
            cout << "\E[30;47m" << " " << board[0][row][col] << " "
                 << "\E[0m";
          if (row %2 == 0 && col %2 != 0 && board[1][row][col] == 'b')
            cout << "\E[30;41m " << board[0][row][col] << " \E[0m";
         if (row %2 == 0 && col %2 == 0 && board[1][row][col] == ' ')
            cout << "\E[47m   \E[0m";
         if (row %2 == 0 && col %2 != 0 && board[1][row][col] == ' ')
            cout << "\E[41m   \E[0m";
         
         if (row %2 != 0 && col %2 != 0 && board[1][row][col] == 'w')
            cout << "\E[31;47m" << " " << board[0][row][col] << " "
                 << "\E[0m";
         if (row %2 != 0 && col %2 == 0 && board[1][row][col] == 'w')
            cout << "\E[37;41m " << board[0][row][col] << " \E[0m";
          if (row %2 != 0 && col %2 != 0 && board[1][row][col] == 'b')
            cout << "\E[30;47m" << " " << board[0][row][col] << " "
                 << "\E[0m";
         if (row %2 != 0 && col %2 == 0 && board[1][row][col] == 'b')
            cout << "\E[30;41m " << board[0][row][col] << " \E[0m";
         if (row %2 != 0 && col %2 != 0 && board[1][row][col] == ' ')
            cout << "\E[47m   \E[0m";
         if (row %2 != 0 && col %2 == 0 && board[1][row][col] == ' ')
            cout << "\E[41m   \E[0m";
         if (col == 7)
            cout << endl;
      }
}
/**********************************************************************
 * displayOptions
 * It's all in the name.
 **********************************************************************/
void displayOptions()
{
   cout << "Options:\n"
        << "?\tDisplay these options\n"
        << "b2b4\tSpecify a move using the Smith Notation\n"
        << "test\tSimple display for test purposes\n"
        << "quit\tLeave the game. You will be prompted to save\n";
}

/**********************************************************************
 * listMoves
 * trivial function that creates a list of moves.
 **********************************************************************/
void listMoves(const int turn, const string move, string moves[])
{
   moves[turn] = move;
}

/**********************************************************************
 *loadGame
 *this function handles everything related to loading a game from a file
 **********************************************************************/
bool loadGame(int &turn, string moves[], char board[][8][8])
{
   
   string filename = " ";
   string move = " ";
   int numMoves = 0;

   getFilename(filename);
   if (readFile(moves, numMoves, filename))
   {
      turn = 0;
      resetBoard(board);
      
      for (int i = 0; i < numMoves; i++)
      {
         move = moves[i];
         if (! movePiece(turn,move,board,filename))
            return false;
         turn++;
      }
   }
   return true;
}

/**********************************************************************
 *
 *
 **********************************************************************/
void getFilename(string &filename)
{
   cout << "Filename: ";
   cin  >> filename;
   debug(filename);
}

/**********************************************************************
 *
 *
 **********************************************************************/
bool readFile(string moves[], int &numMoves, const string filename)
{
   ifstream fin(filename.c_str());
   
   if (fin.fail())
   {
      cout << "Unable to open file " << filename << " for input\n";
      return false;
   }
   while (fin >> moves[numMoves])
   {
      debug(moves[numMoves]);
      numMoves++;
   }
   
   fin.close();
   return true;
}

/**********************************************************************
 *
 *
 **********************************************************************/
void quitGame(const string moves[], const int turn)
{
   string filename = " ";
   getSavename(filename);
      if (!isspace(filename[0]))
         writeFile(moves, filename, turn);
      debug(filename[0]);
      debug(filename);
}

/**********************************************************************
 *
 *
 **********************************************************************/
void getSavename(string &filename)
{
   cout << "To save a game, please specify the filename.\n"
        << "\tTo quit without saving a file, just press <enter>\n";
   cin.ignore();
   getline(cin, filename);
}

/**********************************************************************
 *
 *
 **********************************************************************/
void writeFile(const string moves[], const string filename, const int turn)
{
   ofstream fout(filename.c_str());
   if (fout.fail())
      cout << "Unable to open file " << filename << "for output.\n";
   for (int i = 0; i <= turn; i++)
   {
      fout << moves[i] << " ";
      if (i > 0 && i %2 != 0)
         fout << "\n";
   }
   fout.close();
}

/**********************************************************************
 * movePiece
 * this function does everything related to moving a piece (or, like your
 * lazy younger brother, whines if things go wrong
 * and begs other functions to do the work for him)
 **********************************************************************/
bool movePiece(const int turn, const string move, char board[][8][8])
{
   bool isCastle = false;
   int startRow = 0;
   int startCol = 0;
   int endRow = 0;
   int endCol = 0;
   
      if (!isInvalidMove(move, board))
      {
         convertMove(move, startRow, startCol,
                     endRow, endCol, isCastle);
         makeMove(startRow, startCol, endRow, endCol, turn, isCastle, board);
         return true;
      }
      else if (isInvalidMove(move, board) == 1)
         cout << "Error in move \'" << move << "\': Invalid format of source "
              << "coordinates\n\tType ? for more options\n";
      else if (isInvalidMove(move, board) == 2)
         cout << "Error in move \'" << move << "\': Invalid format of destination "
              << "coordinates\n\tType ? for more options\n";
      else if (isInvalidMove(move, board) == 3)
         cout << "Error in move \'" << move << "\': No piece in the source "
              << "coordinates position\n\tType ? for more options\n";
      return false;
      
}


bool movePiece(int turn, string move, char board[][8][8], string filename)
{
   bool isCastle = false;
   int startRow = 0;
   int startCol = 0;
   int endRow = 0;
   int endCol = 0;

   if (!isInvalidMove(move, board))
   {
      convertMove(move, startRow, startCol,
                  endRow, endCol, isCastle);
      makeMove(startRow, startCol, endRow, endCol, turn, isCastle, board);
      return true;
   }
   else
   {
      int error = isInvalidMove(move, board);
      if (error == 1)
      {
         cout << "Error parsing file " << filename << " with move \'"
              << move << "\': Invalid format of source coordinates\n";
         return false;
      }
      if (error == 2)
      {
         cout << "Error parsing file " << filename << " with move \'"
              << move << "\': Invalid format of destination coordinates\n";
         return false;
      }
      if (error == 3)
      {
         cout << "Error parsing file " << filename << " with move \'"
              << move << "\': No piece in the source "
              << "coordinates position\n";
         return false;
      }
   }
}
/**********************************************************************
 * isInvalidMove
 * determines whether the move is valid or not
 * It's not a bool function because I needed more than one possible
 * return for different errors
 **********************************************************************/
int isInvalidMove(const string move, const char board[][8][8])
{
   if (move.length() > 5)
      return 1;
   if ((int)move[0] - 'a' < 0 || (int)move[0] - 'a' > 7)
      return 1;
   if ((int)move[1] - '1' < 0 || (int)move[1] - '1' > 7)
      return 1;
   if ((int)move[2] - 'a' < 0 || (int)move[2] - 'a' > 7)
      return 2;
   if ((int)move[3] - '1' < 0 || (int)move[3] - '1' > 7)
      return 2;
   int startCol = (int)move[0] - 'a';
   int startRow = (int)move[1] - '1';
   startRow = startRow + (7 - (2 * startRow));
   if (board[1][startRow][startCol] == ' ')
      return 3;
   return 0;
}

/**********************************************************************
 * convertMove
 * converts the string 'move' into starting and ending coordinates
 **********************************************************************/
void convertMove(const string move, int &startRow, int &startCol,
                 int &endRow, int &endCol, bool &isCastle)
{
   startCol = (int)move[0] - 'a';
   startRow = (int)move[1] - '1';
   startRow = startRow + (7 - (2 * startRow));
   endCol   = (int)move[2] - 'a';
   endRow   = (int)move[3] - '1';
   endRow   = endRow + (7 - (2 * endRow));
   
   if (move[4] == 'c' && move [0] == 'e' && (move[2] == 'g' || move[2] == 'c'))
      isCastle = true;
   else
      isCastle = false;
   debug(isCastle); 
}

/**********************************************************************
 * makeMove
 * this function changs the board based on the coordinates from
 * convertMove
 **********************************************************************/
void makeMove(const int startRow, const int startCol, const int endRow,
              const int endCol, const int turn, const bool isCastle,
              char board[][8][8])
{
   board[1][startRow][startCol] = ' ';
   if (turn %2 == 0)
      board[1][endRow][endCol] = 'w';
   else
      board[1][endRow][endCol] = 'b';
   board[0][endRow][endCol] = board[0][startRow][startCol];
   board[0][startRow][startCol] = ' ';
  
   if (isCastle && endCol == 6)
   {
      if (turn %2 == 0)
      {
         board[1][7][5] = 'w';
         board[0][7][5] = 'R';
         board[0][7][7] = ' ';
         board[0][7][7] = ' ';
      } else {
         board[1][0][5] = 'b';
         board[0][0][5] = 'R';
         board[0][0][7] = ' ';
         board[1][0][7] = ' ';
      }
   }
   else if (isCastle && endCol == 2)
      if (turn%2 == 0)
      {
         board[1][7][3] = 'w';
         board[0][7][3] = 'R';
         board[0][7][0] = ' ';
         board[1][7][0] = ' ';
      } else {
         board[1][0][3] = 'b';
         board[0][0][3] = 'R';
         board[0][0][0] = ' ';
         board[1][0][0] = ' ';
      }
         
            
      
}
/**********************************************************************
 * resetBoard
 * resets the Board to starting positions
 **********************************************************************/
void resetBoard (char board[][8][8])
{
   for (int row = 0; row < 8; row++)
   {
      for (int col = 0; col < 2; col++)
         board[1][col][row] = 'b';
      for (int col = 1; col < 2; col++)
         board[0][col][row] = 'p';
      for (int col = 2; col < 6; col++)
      {
         board[1][col][row] = ' ';
         board[0][col][row] = ' ';
      }
      for (int col = 6; col < 8; col++)
         board[1][col][row] = 'w';
      for (int col = 6; col < 7; col++)
         board[0][col][row] = 'p';
   }
   board[0][0][0] = 'R';
   board[0][7][0] = 'R';
   board[0][0][1] = 'N';
   board[0][7][1] = 'N';
   board[0][0][2] = 'B';
   board[0][7][2] = 'B';
   board[0][0][3] = 'Q';
   board[0][7][3] = 'Q';
   board[0][0][4] = 'K';
   board[0][7][4] = 'K';
   board[0][0][5] = 'B';
   board[0][7][5] = 'B';
   board[0][0][6] = 'N';
   board[0][7][6] = 'N';
   board[0][0][7] = 'R';
   board[0][7][7] = 'R';
}
