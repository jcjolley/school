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
      Complex operator + (const Complex & rhs) const
      {  // (a + bi) + (c + di) = (a + c) + (b + d)i
         return Complex(r + rhs.r, i + rhs.i);
      }
      Complex operator + (double rhs) const
      {
         return Complex(r + rhs, i);
      }
      inline friend Complex operator + (int lhs, const Complex & rhs)
      {                        // communitive property of addition
         return rhs + lhs;     // define a + b in terms of b + a
      }

      Complex operator - (const Complex & rhs) const
      {  // (a + bi) - (c + di) = (a - c) + (b - d)i
         return Complex(r - rhs.r, i - rhs.i);
      }
      Complex operator - (double rhs) const
      {
         return Complex(r - rhs, i);
      }
      inline friend Complex operator - (double lhs, const Complex & rhs)
      {         
         return Complex(lhs - rhs.r, -rhs.i);
      }

      Complex operator * (const Complex & rhs) const
      {  // (a + bi)(c + di) = (ac - bd) + i(ad + bc)
         return Complex((r * rhs.r - i * rhs.i),
                        (r * rhs.i + i * rhs.r));
      }
      Complex operator * (double rhs) const
      {  // (a + bi)c = ac + bci
         return Complex(r * rhs, i * rhs);
      }
      inline friend Complex operator * (double lhs, const Complex & rhs)
      {                      // communitive property of multiplication
         return rhs * lhs;   // define "a * b" as "b * a"
      }

      Complex operator / (double rhs) const
      { // (a + bi)/c = a/c + bi/c
         return Complex(r / rhs, i / rhs);
      }
      // the others are too complex ;-)

     /*******************************************
      * ADD-ONTO OPERATORS
      *******************************************/
      Complex & operator += (const Complex & rhs)
      {  // (a + bi) + (c + di) = (a + c) + (b + d)i
         r += rhs.r;
         i += rhs.i;
         return *this;
      }
      Complex & operator += (double rhs)
      {  // (a + bi) + c = (a + c) + bi
         r += rhs;
         return *this;
      }
      Complex & operator -= (const Complex & rhs)
      {  // (a + bi) - (c + di) = (a - c) + (b - d)i
         r -= rhs.r;
         i -= rhs.i;
         return *this;
      }
      Complex & operator -= (double rhs)
      {  // (a + bi) - c = (a - c) + bi
         r -= rhs;
         return *this;
      }
      Complex & operator *= (const Complex & rhs)
      {  // (a + bi)(c + di) = (ac - bd) + i(ad + bc)
         r = (r * rhs.r - i * rhs.i);
         i = (r * rhs.i + i * rhs.r);
         return *this;
      }
      Complex & operator *= (double rhs)
      {   // (a + bi)c = ac + bci
         r *= rhs;
         i *= rhs;
         return *this;
      }
      Complex & operator /= (double rhs)
      {   // (a + bi)/c = a/c + (b/c)i
         r /= rhs;
         i /= rhs;
         return *this;
      }

     /*******************************************
      * INCREMENT AND DECREMENT
      *******************************************/
      Complex & operator ++ ()
      {
         return *this += 1.0;        // prefix ++ is exactly the same as += 1
      }
      Complex & operator -- ()
      {
         return *this -= 1.0;        // prefix -- is exactly the same as -= 1
      }
      Complex operator ++ (int postfix)
      {
         Complex old(*this);  // the easiest way is to remember the old value
         *this += 1.0;        //    and return it after we have done
         return old;          //    the increment
      }
      Complex operator -- (int postfix)
      {
         *this -= 1.0;         // another way is to increment and then
         return *this + 1.0;   //    return an equivalent value
      }

     /*******************************************
      * NEGATIVE AND NOT
      ******************************************/
      Complex operator - () const
      {
         return *this * -1.0;                  // -c is the same as c * -1.0
      }
      bool operator ! () const
      {
         return (r == 0.0 && i == 0.0);
      }

     /******************************************
      * COMPARISION
      ******************************************/
      bool operator == (const Complex & rhs) const
      {
         return (r == rhs.r && i == rhs.i);
      }
      bool operator != (const Complex & rhs) const
      {
         return !(*this == rhs);
      }
      bool operator > (const Complex & rhs) const
      {  // the distance from the origin
         return (r * r + i * i) > (rhs.r * rhs.r + rhs.i * rhs.i);
      }
      bool operator >= (const Complex & rhs) const
      {
         return (*this > rhs) || (*this == rhs);
      }
      bool operator < (const Complex & rhs) const
      {
         return !(*this >= rhs);
      }
      bool operator <= (const Complex & rhs)
      {
         return !(*this > rhs);
      }
};

   




