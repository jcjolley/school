/***********************************************************************
 * This program is designed to:
 *    Demonstrate polymorphism with virtual functions
 *    by having several classes (TimeGerman, TimeItalian, TimeMilitary)
 *    inherit off of a Time class.  We will also have simple inheritance
 *    were Time is inherited off of Minutes which comes from Hours
 ************************************************************************/

#include <iostream>           // well, this does simple i/o
#include <cassert>            // as we all know, I am paraniod
using namespace std;

/***********************************************************
 * HOURS: Number of hours in a day.  This is the base class
 *        so it does not inherit off anything.
 ***********************************************************/
class Hours
{
public:
   Hours()      : h(12)              {                                      }
   Hours(int h) : h(0)               { setHours(h);                         }
   Hours(const Hours & hours)        { setHours(hours.getHours());          }
   int  getHours()  const            { return h;                            }
   bool isMorning() const            { return h < 12;                       }
   void setHours(int h)              { if (validateHours(h)) this->h = h;   }
   void addHours(int h);
   void displayHours(bool is24) const
   {
      if (is24)
         cout << (h < 10 ? "0" : "") << h;
      else
         cout << ((h == 0 || h == 12) ? 12 : h % 12);
   }
private:
   bool validateHours(int h) const   { return (0 <= h && h <= 23);          }
   int h;
};

/**********************************************************
 * MINUTES: Number of hours and minutes in a day.
 *          Inherits off of Hours so it contains all Hours methods
 **********************************************************/
class Minutes : public Hours
{
public:
   Minutes()      : m(0), Hours()    {                                      }
   Minutes(int m) : m(0), Hours()    { setMinutes(m);                       }
   Minutes(const Minutes & minutes);
   int  getMinutes() const           { return m;                            }
   void setMinutes(int m)            { if (validateMinutes(m)) this->m = m; }
   void addMinutes(int m);
   void displayMinutes() const
   {
      cout << (m < 10 ? "0" : "") << m;
   }
private:
   bool validateMinutes(int m) const { return (0 <= m && m < 60);           }
   int m;
};

/************************************************************
 * Time: Hours, minutes, and seconds
 *       Inherits off of Minutes which inherits off of Hours
 ***********************************************************/
class Time : public Minutes
{
public:
   Time()      : s(0), Minutes()     {                                      }
   Time(int s) : s(0), Minutes()     { setSeconds(s);                       }
   Time(const Time & time);
   int  getSeconds() const           { return s;                            }
   void setSeconds(int s)            { if (validateSeconds(s)) this->s = s; }
   void addSeconds(int s);
   void displaySeconds() const
   {
      cout << (s < 10 ? "0" : "") << s;
   }
   virtual void display() const
   {
      displayHours(false /*is24*/);         // we will display the hours...
      cout << ':';                          // ... followed by the colon ... 
      displayMinutes();                     // ... followed by the minutes ...
      cout << (isMorning() ? "am" : "pm");  // ... and ending with the am/pm
   }
private:
   bool validateSeconds(int s) const { return (0 <= s && s < 60);           }
   int s;
};

/**************************************************
 * TIME GERMAN
 *        Inherits off of Time but rather than extending,
 *        it redefines.  TimeGerman is polymorphic
 **************************************************/
class TimeGerman : public Time
{
public:
   TimeGerman()                        : Time()     {}
   TimeGerman(int s)                   : Time(s)    {}
   TimeGerman(const TimeGerman & time) : Time(time) {}
   virtual void display() const     // virtual function
   {
      displayHours(true /*is24*/);
      cout << '.';
      displayMinutes();
   }
};

/**************************************************
 * TIME ITALIAN
 **************************************************/
class TimeItalian : public Time
{
public:
   TimeItalian()                         : Time()     {}
   TimeItalian(int s)                    : Time(s)    {}
   TimeItalian(const TimeItalian & time) : Time(time) {}
   virtual void display() const     // virtual function
   {
      displayHours(false /*is24*/);
      cout << '.';
      displayMinutes();
      cout << (isMorning() ? " AM" : " PM");
   }
};

/**************************************************
 * TIME MILITARY
 **************************************************/
class TimeMilitary : public Time
{
public:
   TimeMilitary()                          : Time()     {}
   TimeMilitary(int s)                     : Time(s)    {}
   TimeMilitary(const TimeMilitary & time) : Time(time) {}
   virtual void display() const    // virtual function
   {
      displayHours(true /*is24*/);
      cout << ':';
      displayMinutes();
   }
};


/**********************************************************************
 * MAIN:  A driver program to exercise the various versions of
 *        our Time class: TimeGerman, TimeItalian, and TimeMilitary
 ***********************************************************************/
int main()
{
   // Array of times. Could be Time, TimeGeman, TimeItalian, or Time MIlitary
   Time * array[5];                      // with pointers, no slicing problem

   // instructions
   cout << "We will have five times. Please specify the format each is in:\n";
   cout << "  1 : United States\n";
   cout << "  2 : German\n";
   cout << "  3 : Italian\n";
   cout << "  4 : Military\n";

   // create the time objects.  We don't know the verions of each at
   // compile time.  This is a run-time decision.  Therefore, we must use
   // polymorphism 
   for (int i = 0; i < 5; i++)
   {
      int selection;
      cout << "> ";
      cin  >> selection;

      switch (selection)
      {
         case 4:
            array[i] = new TimeMilitary; // in each case here, we are making
            break;                       //    a new Time object.  Each
         case 3:                         //    one will remember that it
            array[i] = new TimeItalian;  //    is not just a Time, but rather
            break;                       //    a TimeMilitary, TimeItalian,
         case 2:                         //    or whatever.  We need to make
            array[i] = new TimeGerman;   //    sure that we don't have an 
            break;                       //    array of Time, but an array
         case 1:                         //    of Time pointers!
         default:
            array[i] = new Time;
      }
   }

   // display the results
   for (int i = 0; i < 5; i++)
   {
      cout << "Time #" << i + 1 << ": ";
      array[i]->display();               // because this is virtual, we will
      cout << endl;                      //    call the appropriate version
   }

   // because we allocated each, we must delete when done
   for (int i = 0; i < 5; i++)
      delete array[i];

   return 0;
}


/**********************************
 * HOURS : ADD HOURS: add a fixed number of hours to our value
 *   INPUT:  hours: number to add
 **********************************/
void Hours :: addHours(int h)
{
   // note how we need to use this->h to distinguish between
   // the parameter and the member variable.
   int hNew = h + this->h;

   // always validate before assigning. In this case, we are going
   // to reject if it is greater than 23 because we don't have
   // a day variable to add to.
   if (validateHours(hNew))
      this->h = hNew;
}

/*******************************************
 * MINUTES : COPY CONSTRUCTOR
 *******************************************/
Minutes :: Minutes(const Minutes & minutes) : Hours(minutes.getHours())
{
   setMinutes(minutes.getMinutes());
}

/***************************************
 * MINUTES : ADD MINUTES: Set a number of minutes,
 *           adjusting hours as necessary
 *   INPUT m : minutes to add it to
 ***************************************/
void Minutes :: addMinutes(int m)
{
   // new minutes is the old plus the parameter
   int mNew = m + this->m;

   // just right
   if (validateMinutes(mNew))
   {
      assert(validateMinutes(mNew));
      this->m = mNew;
      return;
   }

   // too many - add hours
   if (mNew >= 60)
   {
      addHours(mNew / 60);
      assert(validateMinutes(mNew % 60));
      this->m = mNew % 60;
   }

   // too few - subtract hours
   else
   {
      assert(mNew < 0);
      if (mNew % 60 < 0)  // take an extra hour off to avoid negative minutes
      {
         addHours(mNew / 60 - 1);      // remove 1 hour and...
         mNew += 60 - mNew / 60 * 60;  // add 60 minutes. 
      }
      else
         addHours(mNew / 60);
         
      assert(validateMinutes(mNew % 60));
      this->m = mNew % 60;
   }
}

/*******************************************
 * TIME : COPY CONSTRUCTOR
 *        Note how we also call the Minutes default
 *        constructor.  When we look at Minutes, we
 *        realize the seconds default constructor gets
 *        copied as well.
 *******************************************/
Time :: Time(const Time & time) : Minutes()  // call the parent!
{
   setHours  (time.getHours()  );
   setMinutes(time.getMinutes());
   setSeconds(time.getSeconds());
}


/***************************************
 * TIME : ADD SECONDS: Set a number of seconds
 *          adjusting hours and minutes as necessary
 *   INPUT s : seconds to add it to
 ***************************************/
void Time :: addSeconds(int s)
{
   // new seconds is the old value plus the parameter
   int sNew = s + this->s;

   // just right
   if (validateSeconds(sNew))
   {
      assert(validateSeconds(sNew));
      this->s = sNew;
      return;
   }

   // too many - add minutes
   if (sNew >= 60)
   {
      addMinutes(sNew / 60);
      assert(validateSeconds(sNew % 60));
      this->s = sNew % 60;
   }
   
   // too few - subtract minutes
   else
   {
      assert(sNew < 0);
      if (sNew % 60 < 0)  // take an extra minute off to avoid negative seconds
      {
         addMinutes(sNew / 60 - 1);    // remove one minute and...
         sNew += 60 - sNew / 60 * 60;  // add 60 seconds.
      }
      else
         addMinutes(sNew / 60);
         
      assert(validateSeconds(sNew % 60));
      this->s = sNew % 60;
   }
}

