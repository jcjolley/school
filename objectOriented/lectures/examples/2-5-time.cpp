/***********************************************************************
 * This program is designed to demonstrate:
 *      The time class with either do a 24-hour display or am/pm display
 ************************************************************************/

#include <iostream>
#include <cassert>
using namespace std;

/***********************************
 * TIME
 * This class definition.  A very simple
 * class to be honest
 ***********************************/
class Time
{
   public:
     // Constructors
     Time() : minutes(0) { }                 // default constructor
     Time(int hours, int minutes = 0)        // non-default constructor
     {
        set(hours, minutes);
     }
     Time(const Time & rhs)                  // copy constructor
     {
        assert(rhs.validate());
        minutes = rhs.minutes;
        assert(validate());
     }
   
     // TIME :: SET : Set the time according to user input
     void set(int hours = 0, int minutes = 0)
     {
        // first just trust them
        this->minutes = hours * 60 + minutes;

        // now validate
        if (!validate())
           this->minutes = 0;    // set to midnight
      }

      // TIME :: DISPLAY : Display the time in a user-friendly way
      void display() const
      {
         // paranoia...
         assert(validate());
         if (isMilitary)
            displayMilitary();
         else
            displayCivilian();
         cout << endl;
      }
   
      // TIME :: GET MINUTES : Fetch the minutes since midnight
      int  getMinutes() const
      {
         // more paranoia...
         assert(validate());

         return minutes % 60;
      }

      // TIME :: GET HOURS : Fetch the hours in military time
      int  getHours() const
      {
         // even more paranoia...
         assert(validate());

         return minutes / 60;
      }
   
   private:
      // TIME :: VALIDATE : Ensure that the member variable is set correctly   
      bool validate() const
      {
         return (minutes >= 0 && minutes < 24 * 60);
      }
      // TIME :: DISPLAY MILITARY: Display time with the 24 hour clock
      void displayMilitary() const
      {
         // hours.  Midnight is 24:00
         int hours = getHours();
         cout << (hours == 0 ? 24 : hours) << ":";

         // minutes
         int minutes = getMinutes();
         cout << (minutes < 10 ? "0" : "") << minutes;
      }
      // TIME :: DISPLAY CIVILIAN: Display time with am/pm
      void displayCivilian() const
      {
         // hours.  Midnight is 12:00 am
         int hours = getHours();
         cout << (hours == 0 ? 12 : hours % 12) << ":";

         // display minutes
         int minutes = getMinutes();
         cout << (minutes < 10 ? "0" : "") << minutes;

         // display am/pm
         cout << (hours < 12 ? " am" : " pm");
      }
   
      int  minutes;
      static bool isMilitary;
};

bool Time :: isMilitary = false;              // Configure the time class

/**********************************************************************
 * This will be just a simple driver program to exercise Time
 ***********************************************************************/
int main()
{
   Time time1;                                // start with midnight
   cout << "Time1 is midnight - ";
   time1.display();
   
   Time time2(9 /*hours*/, 11 /*minutes*/);   // Next 9:11 am
   cout << "Time2 is in the morning - ";
   time2.display();
   
   Time time3(18 /*hours*/, 2 /*minutes*/);   // Finally 6:02 pm
   cout << "Time3 is the afternoon - ";
   time3.display();
   
   return 0;
}
