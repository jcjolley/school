/***********************************************************************
* Program:
*    Project 3, Chess with Objects
*    Brother Helfrich, CS165
* Author:
*    The Key
* Summary: 
*    This file will keep track one move
************************************************************************/

#ifndef _MOVE_
#define _MOVE_

#include <string>
#include "position.h"

#define PIECE_EMPTY ' '


/***************************************************
 * MOVE
 * One move across the board
 ***************************************************/
class Move
{
  public:
      Move(); 
      Move(const Move & rhs)           { *this = rhs;      };
      const Position & getDes()  const { return dest;      };
      const Position & getSrc()  const { return source;    };
      std::string getText() const;
      char getPromotion()        const { return piece;     };
      char getCapture()          const { return capture;   };
      bool getEnPassant()        const { return enpassant; };
      bool getCastleK()          const { return castleK;   };
      bool getCastleQ()          const { return castleQ;   };
      bool getWhiteMove()        const { return isWhite;   };
      bool operator == (const std::string & rhs) const { return getText() == rhs; };
      bool operator != (const std::string & rhs) const { return getText() != rhs; };
      bool operator == (const Move & rhs)   const;
      bool operator != (const Move & rhs)   const { return !(*this == rhs); } ;

      void setCapture(char letter)      { capture    = tolower(letter); };
      void setWhiteMove(bool f)         { isWhite    = f;               };
      void setSrc(const Position & src) { source     = src;             };
      void setDes(const Position & des) { dest       = des;             };
      void setEnPassant()               { enpassant  = true;            };
      void setPromote(char letter)      { piece      = letter;          };
      void setCastle(bool isKing)
      {
         if (isKing)
            castleK = true;
         else
            castleQ = true;
      };

      friend std::ostream & operator << (std::ostream & out, Move & rhs);
      friend std::istream & operator >> (std::istream & in,  Move & rhs) throw (std::string);
      
      const Move & operator = (const Move & rhs);
      const Move & operator = (const std::string & s) throw ( std::string )
         {
            read(s);
            return *this;
         }
      const Move & operator = (const char *s) throw ( std::string )
         {
            read(std::string(s));
            return *this;
         }
      
  private:
      void read(const std::string & s) throw(std::string);

      Position  source;    // where the move originated from
      Position  dest;      // where the move finished
      char      piece;     // piece to be promoted to
      char      capture;   // did a capture happen this move?
      bool      enpassant; // Enpassant pawn capture
      bool      castleK;   // kingside castle
      bool      castleQ;   // queenside castle
      bool      isWhite;   // white's move?
      std::string    error;     // if in error state, what was the bug?
      
};


#endif // _MOVE_
