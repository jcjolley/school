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
};


/*******************************************
 * INSERTION AND EXTRACTION
 *******************************************/
inline std::ostream & operator << (std::ostream & out, const Complex & rhs)
{
   out << rhs.getReal();
   if (rhs.getImaginary() != 0.0)                 // only display the imaginary
      out << " + " << rhs.getImaginary() << "i";  //    component if non-zero
   return out;                                    // return "out"
}
inline std::istream & operator >> (std::istream & in, Complex & rhs)
{
   float real;
   float imaginary;
   in >> real >> imaginary;   // first fetch input into local variables
   rhs.set(real, imaginary);  // then set rhs with the data
   return in;                 // do not forget to return "in"
}

/*******************************************
 * ARITHMETIC OPERATORS
 *******************************************/
inline Complex operator + (const Complex & lhs, const Complex & rhs)
{  // (a + bi) + (c + di) = (a + c) + (b + d)i
   return Complex(lhs.getReal()      + rhs.getReal(),
                  lhs.getImaginary() + rhs.getImaginary());
}
inline Complex operator + (const Complex & lhs, double rhs)
{
   return Complex(lhs.getReal() + rhs, lhs.getImaginary());
}
inline Complex operator + (int lhs, const Complex & rhs)
{                        // communitive property of addition
   return rhs + lhs;     // define a + b in terms of b + a
}

inline Complex operator - (const Complex & lhs, const Complex & rhs)
{  // (a + bi) - (c + di) = (a - c) + (b - d)i
   return Complex(lhs.getReal()      - rhs.getReal(),
                  lhs.getImaginary() - rhs.getImaginary());
}
inline Complex operator - (const Complex & lhs, double rhs)
{
   return Complex(lhs.getReal() - rhs, lhs.getImaginary());
}
inline Complex operator - (double lhs, const Complex & rhs)
{         
   return Complex(lhs - rhs.getReal(), -rhs.getImaginary());
}

inline Complex operator * (const Complex & lhs, const Complex & rhs)
{  // (a + bi)(c + di) = (ac - bd) + i(ad + bc)
   return Complex((lhs.getReal()      * rhs.getReal() -
                   lhs.getImaginary() * rhs.getImaginary()),
                  (lhs.getReal()      * rhs.getImaginary() +
                   lhs.getImaginary() * rhs.getReal()) );
}
inline Complex operator * (const Complex & lhs, double rhs)
{  // (a + bi)c = ac + bci
   return Complex(lhs.getReal() * rhs, lhs.getImaginary() * rhs);
}
inline Complex operator * (double lhs, const Complex & rhs)
{                      // communitive property of multiplication
   return rhs * lhs;   // define "a * b" as "b * a"
}

inline Complex operator / (const Complex & lhs, double rhs)
{ // (a + bi)/c = a/c + bi/c
   return Complex(lhs.getReal() / rhs, lhs.getImaginary() / rhs);
}
// the others are too complex ;-)

/*******************************************
 * ADD-ONTO OPERATORS
 *******************************************/
inline Complex & operator += (Complex & lhs, const Complex & rhs)
{  // (a + bi) + (c + di) = (a + c) + (b + d)i
   lhs.set(lhs.getReal()      + rhs.getReal(),
           lhs.getImaginary() + rhs.getImaginary());
   return lhs;
}
inline Complex & operator += (Complex & lhs, double rhs)
{  // (a + bi) + c = (a + c) + bi
   lhs.set(lhs.getReal()      + rhs,
           lhs.getImaginary());
   return lhs;
}
inline Complex & operator -= (Complex & lhs, const Complex & rhs)
{  // (a + bi) - (c + di) = (a - c) + (b - d)i
   lhs.set(lhs.getReal()      - rhs.getReal(),
           lhs.getImaginary() - rhs.getImaginary());
   return lhs;
}
inline Complex & operator -= (Complex & lhs, double rhs)
{  // (a + bi) - c = (a - c) + bi
   lhs.set(lhs.getReal()      - rhs,
           lhs.getImaginary());
   return lhs;
}
inline Complex & operator *= (Complex & lhs, const Complex & rhs)
{  // (a + bi)(c + di) = (ac - bd) + i(ad + bc)
   lhs.set((lhs.getReal()      * rhs.getReal() -
            lhs.getImaginary() * rhs.getImaginary()),
           (lhs.getReal()      * rhs.getImaginary() +
            lhs.getImaginary() * rhs.getReal()) );
   return lhs;
}
inline Complex & operator *= (Complex & lhs, double rhs)
{   // (a + bi)c = ac + bci
   lhs.set(lhs.getReal() * rhs, lhs.getImaginary() * rhs);
   return lhs;
}
inline Complex & operator /= (Complex & lhs, double rhs)
{   // (a + bi)/c = a/c + (b/c)i
   lhs.set(lhs.getReal() / rhs, lhs.getImaginary() / rhs);
   return lhs;
}


/*******************************************
 * INCREMENT AND DECREMENT
 *******************************************/
inline Complex & operator ++ (Complex & lhs)
{
   return lhs += 1.0;        // prefix ++ is exactly the same as += 1
}
inline Complex & operator -- (Complex & lhs)
{
   return lhs -= 1.0;        // prefix -- is exactly the same as -= 1
}
inline Complex operator ++ (Complex & rhs, int postfix)
{
   Complex old(rhs);         // the easiest way is to remember the old value
   rhs += 1.0;               //    and return it after we have done
   return old;               //    the increment
}
inline Complex operator -- (Complex & rhs, int postfix)
{
   rhs -= 1.0;               // another way is to increment and then
   return rhs + 1.0;         //    return an equivalent value
}

/*******************************************
 * NEGATIVE AND NOT
 ******************************************/
inline Complex operator - (const Complex & rhs)
{
   return rhs * -1.0;                     // -c is the same as c * -1.0
}
inline bool operator ! (const Complex & rhs)
{
   return (rhs.getReal() == 0.0 && rhs.getImaginary() == 0.0);
}

/******************************************
 * COMPARISION
 ******************************************/
inline bool operator == (const Complex & lhs, const Complex & rhs)
{
   return (lhs.getReal()      == rhs.getReal() &&
           lhs.getImaginary() == rhs.getImaginary());
}
inline bool operator != (const Complex & lhs, const Complex & rhs)
{
   return !(lhs == rhs);
}
inline bool operator > (const Complex & lhs, const Complex & rhs)
{  // the distance from the origin
   return (lhs.getReal()      * lhs.getReal() +
           lhs.getImaginary() * lhs.getImaginary()) >
          (rhs.getReal()      * rhs.getReal() +
           rhs.getImaginary() * rhs.getImaginary());
}
inline bool operator >= (const Complex & lhs, const Complex & rhs)
{
   return (lhs > rhs) || (lhs == rhs);
}
inline bool operator < (const Complex & lhs, const Complex & rhs)
{
   return !(lhs >= rhs);
}
inline bool operator <= (const Complex & lhs, const Complex & rhs)
{
   return !(lhs > rhs);
}

   




