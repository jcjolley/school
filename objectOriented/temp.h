#ifndef _TEMP_H_
#define _TEMP_H_

#define MIN_TEMP -273.0;
class Temp
{
  public:
   Temp(float degrees = 0);
   Temp(Temp & rhs);
   Temp();
   float get() { return degrees; } 
   void set(float degrees);
   void display();
  private:
   float degrees;
}
#endif
