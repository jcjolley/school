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
      void set(int hours = 0, int minutes = 0);
      void display();
      int  getMinutes();
      int  getHours();

   private:
      bool validate();
      int  minutes;
};

/**************************************
 * TIME :: SET
 * Set the time. Keep it valid
 **************************************/
void Time :: set(int hours, int minutes)
{
   // first just trust them
   this->minutes = hours * 60 + minutes;

   // now validate
   if (!validate())
      this->minutes = 0;    // set to midnight
}

/**************************************
 * TIME :: DISPLAY
 * Display the time in a user-friendly way
 *************************************/
void Time :: display()
{
   // paranoia...
   assert(validate());

   int minutes = getMinutes();
   cout << getHours() << ":";
   if (minutes < 10)
      cout << 0;
   cout << minutes;
}

/*************************************
 * TIME :: GET MINUTES
 * Fetch the minutes
 ************************************/
int Time :: getMinutes()
{
   // more paranoia...
   assert(validate());

   return minutes % 60;
}

/*************************************
 * TIME :: GET HOURS
 * Fetch the hours
 *************************************/
int Time :: getHours()
{
   // even more paranoia...
   assert(validate());

   return minutes / 60;
}

/************************************
 * TIME :: VALIDATE
 * Feed my paranoia to ensure that the
 * member variable is set correctly
 ************************************/
bool Time :: validate()
{
   // check to make sure we are in the valid range
   return (minutes >= 0 && minutes < 24 * 60);
}

/**********************************************************************
 * This will be just a simple driver program to exercise Time
 ***********************************************************************/
int main()
{
   Time time;
   
   // infinite loop to facilitate testing
   for (;;)           
   {
      // get the hours
      int hours;
      cout << "What hour is it? ";
      cin  >> hours;

      // get the minutes
      int minutes;
      cout << "How many minutes past the hour? ";
      cin  >> minutes;

      // display the results
      time.set(hours, minutes);
      time.display();
      cout << endl;
   }
   
   return 0;
}
