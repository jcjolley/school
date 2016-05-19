/***********************************************************************
 * This program is designed to demonstrate:
 *      How to create a simple class: a Time class in this case
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

         int minutes = getMinutes();
         cout << getHours() << ":";
         if (minutes < 10)
            cout << 0;
         cout << minutes;
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

         return (minutes == 0) ? 24 : minutes / 60;
      }
   
   private:
      // TIME :: VALIDATE : Ensure that the member variable is set correctly   
      bool validate() const
      {
         return (minutes >= 0 && minutes < 24 * 60);
      }
   
      int  minutes;
};

/**********************************************************************
 * This will be just a simple driver program to exercise Time
 ***********************************************************************/
int main()
{
   // exercise the default constructor
   Time time1;
   cout << "Time1 is midnight - ";
   time1.display();
   cout << endl;

   // the non-default constructor
   Time time2(10 /*hours*/, 11 /*minutes*/);
   cout << "Time2 is in the morning - ";
   time2.display();
   cout << endl;
   
   // the copy constructor
   Time time3(time2);
   cout << "Time3 is the same as time2 - ";
   time3.display();
   cout << endl;
   
   return 0;
}
