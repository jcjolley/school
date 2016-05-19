/***********************************************************************
* This program is designed to:
*    Demonstrate simple inheritance through an Time class,
*    inheriting off a Minutes parent, inheriting off a
*    Hours parent.
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
   int  getHours() const             { return h;                            }
   void setHours(int h)              { if (validateHours(h)) this->h = h;   }
   void addHours(int h);
private:
   bool validateHours(int h) const   { return (0 <= h && h <= 23);          }
   int h;
};

/**********************************************************
 * MINUTES: Number of hours and minutes in a day.
 *          Looks like HOURS and inherits off Hours
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
private:
   bool validateMinutes(int m) const { return (0 <= m && m < 60);           }
   int m;
};

/************************************************************
 * Time: Hours, minutes, and seconds
 *       Looks like HOURS and MINUTES but inherits off Minutes
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
private:
   bool validateSeconds(int s) const { return (0 <= s && s < 60);           }
   int s;
};

/**********************************************************************
 * MAIN:  A driver program to exercise our Hours, Minutes, and Time classes
 ***********************************************************************/
int main()
{
   //
   // HOURS: A couple quick tests 
   //

   Hours hours1;                   // (1) 12    create hours1 to be 12:00 noon
   assert(hours1.getHours() == 12); 
   hours1.addHours(4);             // (1) 16    add four hours to hours1
   Hours hours2(16);               // (2) 16    create hours1 to be 16:00
   assert(hours2.getHours() == hours1.getHours());

   //
   // validate Minutes next
   //

   Minutes minutes1;                   // (1) 12:00 create minutes1 to 12:00
   assert(minutes1.getMinutes() == 0 && minutes1.getHours() == 12);
   Minutes minutes2(80);               // (2) 12:00 because invalid so ignored
   assert(minutes2.getMinutes() == 0); // (2)       this better still be 12:00
   minutes1.addMinutes(60 * 2 + 30);   // (1) 14:30 add 150 minutes or 2:30
   minutes2.addHours(2);               // (2) 14:00 add two hours
   minutes2.addMinutes(30);            // (2) 14:30 and 30 minutes
   assert(minutes1.getHours()   == minutes2.getHours());
   assert(minutes1.getMinutes() == minutes2.getMinutes());
   minutes1.addHours(-3);              // (1) 11:30
   minutes1.addMinutes(-40);           // (1) 10:50
   minutes2.addMinutes(-(60 * 3 + 40));// (2) 10:50
   assert(minutes1.getHours()   == minutes2.getHours());
   assert(minutes1.getMinutes() == minutes2.getMinutes());

   //
   // finally, validate them all together
   //

   Time time1;                         // (1) 12:00:00 create time1 at 12:00
   assert(time1.getHours() == 12);     // (1)          better be 12 o'clock
   assert(time1.getMinutes() == 0);    // (1)          better be zero minues
   assert(time1.getSeconds() == 0);    // (1)          better be zero seconds
   time1.addSeconds(60 * 6 + 40);      // (1) 12:06:40 add 400 seconds
   time1.addMinutes(60 * 1 + 10);      // (1) 13:16:00 add 70 minutes 
   time1.addHours(3);                  // (1) 16:16:40 add three hours
   Time time2(time1);                  // (2) 16:16:40 Copy constructor
   assert(time1.getHours()   == time2.getHours());
   assert(time1.getMinutes() == time2.getMinutes());
   assert(time1.getSeconds() == time2.getSeconds());
   cout << time1.getHours()   << ":"
        << time1.getMinutes() << ":"
        << time1.getSeconds() << endl; // 16:16:40
   time1.addSeconds(-(6 * 60 + 40));   // (1) 16:10:00 remove 400 seconds
   time1.addMinutes(-(1 * 60 + 10));   // (1) 15:00:00 remove 70 minutes
   time1.addHours(-3);                 // (1) 12:00:00 remove three hours
   assert(time1.getHours() == Hours().getHours());
   time1.addSeconds(-1);               // (1) 11:59:59 remove 1 second
   cout << time1.getHours()   << ":"
        << time1.getMinutes() << ":"
        << time1.getSeconds() << endl; // 11:59:59

   Minutes min = time1.getMinutes();
   
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

