/***************************************************
 * ADJUST DAY.  Adjust the current date by a given number of days
 *  INPUT  date        date we are adjusting
 *         adjustment  how many days we will adjust
 *  OUTPUT date
 ***************************************************/
void Date::adjustDay(int adjustment)
{

   int days = daysMonth(month, year);

   // adjust down if negative
   while (adjustment < 0)
   {
      day--;
      if (day == 0)
      {
         day = 28; // to keep it valid at all points in time
         adjustMonth(-1 /*adjustment*/);
         days = daysMonth(month, year);
         day = days; // last day of the new month
      }
      adjustment++;
   }

   // adjust up if positive
   while (adjustment > 0)
   {
      day++;
      if (day > days)
      {
         day = 1; // first day of the new month
         adjustMonth(1 /*adjustment*/);
         days = daysMonth(month, year);
      }
      adjustment--;
   }

   assertDate();
}

/*********************************************************
 * ADJUST MONTH.  Adjust the current date by a given number of months
 *  INPUT  date       date we are adjusting
 *         adjustment how many months we will adjust
 *  OUTPUT date
 *********************************************************/
void Date::adjustMonth(int adjustment)
{

   // adjust down if negative
   while (adjustment < 0)
   {
      month--;
      if (month == 0)
      {
         month = 12;  // last month of the new year
         adjustYear(-1 /*adjustment*/);
      }
      adjustment++;
   }


   // adjust up if positive
   while (adjustment > 0)
   {
      month++;
      if (month > 12)
      {
         month = 1; // first month of the new year
         adjustYear(1 /*adjustment*/);
      }
      adjustment--;
   }

}

/****************************************************
 * ADJUST YEAR.  Adjust the year bug a given number of years
 *  INPUT  date       date we are adjusting
 *         adjustment how many years we will adjust
 *  OUTPUT date
 *********************************************************/
void Date::adjustYear(int adjustment)
{

   year += adjustment;

}
