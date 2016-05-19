/***********************************************************************
 * This file describes the WRITE interface, a class
 *      designed to write data to a file
 ************************************************************************/

#ifndef _WRITE_H_
#define _WRITE_H_

#include <fstream>        // necessary for the ofstream object
#include <string>         // necessary for the string parameters

/******************************************************
 * WRITE
 * This class will write text to a file without having
 * the client have to worry about opening or closing it
 ******************************************************/
class Write
{
   public:
      Write() : isOpen(false)      {       }
      Write(const std::string & fileName);
     ~Write();
      void writeToFile(const std::string & text);

   private:
      bool          isOpen;           // did we successfully open the file?
      std::ofstream fout;             // the file stream object
};
#endif // _WRITE_H_
