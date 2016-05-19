/***********************************************************************
 * This is the header file for Complex, a real an imaginary number is
 * the form of "4 + 3i" where 4 is the real component and 3 is the imaginary
 ************************************************************************/

#include <iostream>    // for ISTREAM and OSTREAM

/**********************************************************************
 * COMPLEX
 ***********************************************************************/
class Complex
{
   public:
      // constructors
      Complex()                         : r(0.0), i(0.0) {              }
      Complex(double r, double i = 0.0) : r(r),   i(i)   {              }
      Complex(const Complex & c)        : r(c.r), i(c.i) {              }  

      // getters and setters
      double getReal()      const                        { return r;    } 
      double getImaginary() const                        { return i;    } 
      void   setReal(double r)                           { this->r = r; }
      void   setImaginary(double i)                      { this->i = i; }
      void   set(double r, double i)
      {
         this->r = r;
         this->i = i;
      }
      
   private:
      double r;   // real component of the number
      double i;   // imaginary component of the number

   public:
      
     /*******************************************
      * INSERTION AND EXTRACTION
      *******************************************/
      inline friend std::ostream & operator << (std::ostream & out,
                                                const Complex & rhs)
      {
         out << rhs.r;
         if (rhs.i != 0.0)                       // only display the imaginary
            out << " + " << rhs.i << "i";        //    component if non-zero
         return out;                             // return "out"
      }
      inline friend std::istream & operator >> (std::istream & in,
                                                Complex & rhs)
      {
         in >> rhs.r >> rhs.i;      // input directly into the member varibles
         return in;                 // do not forget to return "in"
      }

     /*******************************************
      * ARITHMETIC OPERATORS
      *******************************************/
      inline friend Complex operator + (const Complex & lhs,
                                        const Complex & rhs)
      {  // (a + bi) + (c + di) = (a + c) + (b + d)i
         return Complex(lhs.r + rhs.r, lhs.i + rhs.i);
      }
      inline friend Complex operator + (const Complex & lhs, double rhs)
      {
         return Complex(lhs.r + rhs, lhs.i);
      }
      inline friend Complex operator + (int lhs, const Complex & rhs)
      {                        // communitive property of addition
         return rhs + lhs;     // define a + b in terms of b + a
      }

      inline friend Complex operator - (const Complex & lhs,
                                        const Complex & rhs)
      {  // (a + bi) - (c + di) = (a - c) + (b - d)i
         return Complex(lhs.r - rhs.r, lhs.i - rhs.i);
      }
      inline friend Complex operator - (const Complex & lhs, double rhs)
      {
         return Complex(lhs.r - rhs, lhs.i);
      }
      inline friend Complex operator - (double lhs, const Complex & rhs)
      {         
         return Complex(lhs - rhs.r, -rhs.i);
      }

      inline friend Complex operator * (const Complex & lhs,
                                        const Complex & rhs)
      {  // (a + bi)(c + di) = (ac - bd) + i(ad + bc)
         return Complex((lhs.r * rhs.r - lhs.i * rhs.i),
                        (lhs.r * rhs.i + lhs.i * rhs.r));
      }
      inline friend Complex operator * (const Complex & lhs, double rhs)
      {  // (a + bi)c = ac + bci
         return Complex(lhs.r * rhs, lhs.i * rhs);
      }
      inline friend Complex operator * (double lhs, const Complex & rhs)
      {                      // communitive property of multiplication
         return rhs * lhs;   // define "a * b" as "b * a"
      }

      inline friend Complex operator / (const Complex & lhs, double rhs)
      { // (a + bi)/c = a/c + bi/c
         return Complex(lhs.r / rhs, lhs.i / rhs);
      }
      // the others are too complex ;-)

     /*******************************************
      * ADD-ONTO OPERATORS
      *******************************************/
      inline friend Complex & operator += (Complex & lhs, const Complex & rhs)
      {  // (a + bi) + (c + di) = (a + c) + (b + d)i
         lhs.r += rhs.r;
         lhs.i += rhs.i;
         return lhs;
      }
      inline friend Complex & operator += (Complex & lhs, double rhs)
      {  // (a + bi) + c = (a + c) + bi
         lhs.r += rhs;
         return lhs;
      }
      inline friend Complex & operator -= (Complex & lhs, const Complex & rhs)
      {  // (a + bi) - (c + di) = (a - c) + (b - d)i
         lhs.r -= rhs.r;
         lhs.i -= rhs.i;
         return lhs;
      }
      inline friend Complex & operator -= (Complex & lhs, double rhs)
      {  // (a + bi) - c = (a - c) + bi
         lhs.r -= rhs;
         return lhs;
      }
      inline friend Complex & operator *= (Complex & lhs, const Complex & rhs)
      {  // (a + bi)(c + di) = (ac - bd) + i(ad + bc)
         lhs.r = (lhs.r * rhs.r - lhs.i * rhs.i);
         lhs.i = (lhs.r * rhs.i + lhs.i * rhs.r);
         return lhs;
      }
      inline friend Complex & operator *= (Complex & lhs, double rhs)
      {   // (a + bi)c = ac + bci
         lhs.r *= rhs;
         lhs.i *= rhs;
         return lhs;
      }
      inline friend Complex & operator /= (Complex & lhs, double rhs)
      {   // (a + bi)/c = a/c + (b/c)i
         lhs.r /= rhs;
         lhs.i /= rhs;
         return lhs;
      }

     /*******************************************
      * INCREMENT AND DECREMENT
      *******************************************/
      inline friend Complex & operator ++ (Complex & c)
      {
         return c += 1.0;        // prefix ++ is exactly the same as += 1
      }
      inline friend Complex & operator -- (Complex & c)
      {
         return c -= 1.0;        // prefix -- is exactly the same as -= 1
      }
      inline friend Complex operator ++ (Complex & c, int postfix)
      {
         Complex old(c);      // the easiest way is to remember the old value
         c += 1.0;            //    and return it after we have done
         return old;          //    the increment
      }
      inline friend Complex operator -- (Complex & c, int postfix)
      {
         c -= 1.0;               // another way is to increment and then
         return c + 1.0;         //    return an equivalent value
      }

     /*******************************************
      * NEGATIVE AND NOT
      ******************************************/
      inline friend Complex operator - (const Complex & c)
      {
         return c * -1.0;                     // -c is the same as c * -1.0
      }
      inline friend bool operator ! (const Complex & c)
      {
         return (c.r == 0.0 && c.i == 0.0);
      }

     /******************************************
      * COMPARISION
      ******************************************/
      inline friend bool operator == (const Complex & lhs, const Complex & rhs)
      {
         return (lhs.r == rhs.r && lhs.i == rhs.i);
      }
      inline friend bool operator != (const Complex & lhs, const Complex & rhs)
      {
         return !(lhs == rhs);
      }
      inline friend bool operator > (const Complex & lhs, const Complex & rhs)
      {  // the distance from the origin
         return (lhs.r * lhs.r + lhs.i * lhs.i) >
            (rhs.r * rhs.r + rhs.i * rhs.i);
      }
      inline friend bool operator >= (const Complex & lhs, const Complex & rhs)
      {
         return (lhs > rhs) || (lhs == rhs);
      }
      inline friend bool operator < (const Complex & lhs, const Complex & rhs)
      {
         return !(lhs >= rhs);
      }
      inline friend bool operator <= (const Complex & lhs, const Complex & rhs)
      {
         return !(lhs > rhs);
      }
};

   




