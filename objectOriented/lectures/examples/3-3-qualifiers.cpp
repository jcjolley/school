/***********************************************************************
 * This demo program is designed to:
 *      Demonstrate all versions if inheritance
 ************************************************************************/

#include <iostream>
using namespace std;

/****************************************
 * BASE : The class everyone derives from
 ****************************************/
class Base
{
   public:
      void pub()  {} // Has access to all members of Base
   protected:      
      void prot() {} // Also has access to all members of Base
   private:
      void priv() {} // Also has access to all members of Base
};

/****************************************
 * DERIVED PUB : taking the Base as a Public
 *****************************************/
class DerivedPub : public Base
{
   public:
      void derivedPublic()
      {         
         pub();     // Was public in the Base, now public from DerivedPub 
         prot();    // Was protected in Base, not still protected so no change
      // priv();    // ERROR:
         // 3-3-qualifers.cpp: In member function
         //"void DerivedPub::derivedPublic()":
         // 3-3-qualifers.cpp:19: error: "void Base::priv()" is private
         // 3-3-qualifers.cpp:32: error: within this context
      }
   
   protected:
      // Same rules apply here as for derivedPublic() with regards to access
      // to Base.  Of couse, we have access to all members of DerivedPub
      void derivedProtected() {}
   private:
      // Same rules apply here as for derivedProtected() and derivedPublic()
      void derivedPrivate()   {}
};

/*********************************************
 * DERIVED PRO : taking the Base as a Protected
 *********************************************/
class DerivedPro : protected Base
{
   public:
      void derivedPublic()
      {
         pub();     // Was public, now protected. Client can no longer access
         prot();    // Was protected, now protected.  No change
      // priv();    // ERROR: no access to privates 
         // 3-3-qualifers.cpp: In member function
         //"void DerivedPro::derivedPublic()":
         // 3-3-qualifers.cpp:19: error: "void Base::priv()" is private
         // 3-3-qualifers.cpp:58: error: within this context
      }
   protected:
      // Same rules apply here as for derivedPublic() with regards to access
      // to Base.  Of couse, we have access to all members of DerivedPub
      void derivedProtected() {}
   private:
      // Same rules apply here as for derivedPublic() with regards to access
      // to Base.  Of couse, we have access to all members of DerivedPub
      void derivedPrivate()   {}
};

/***********************************************
 * DERIVED PRIV : taking the Base as Private
 ************************************************/
class DerivedPriv : private Base
{
   public:
      void derivedPublic()
      {
         pub();   // Was public, not private so we can still access it
         prot();  // Was protected, now is private so we can still access it
      // priv();  // ERROR: No access to privates from outside the class
        // 3-3-qualifers.cpp: In member function
        //"void DerivedPriv::derivedPublic()":
        // 3-3-qualifers.cpp:19: error: "void Base::priv()" is private
        // 3-3-qualifers.cpp:84: error: within this context
      }
   protected:
      // Same rules apply here as for derivedPublic() with regards to access
      // to Base.  Of couse, we have access to all members of DerivedPub
      void derivedProtected() {}
   private:
      // Same rules apply here as for derivedPublic() with regards to access
      // to Base.  Of couse, we have access to all members of DerivedPub
      void derivedPrivate()   {}
};


/**********************************************************************
 * main()...
 ***********************************************************************/
int main()
{
   Base base;
   DerivedPub  derivedPub;
   DerivedPro  derivedPro;
   DerivedPriv derivedPriv;

   //
   // Access the methods from Base
   //
   
   base.pub();   // legal.  Base::pub() is public

// base.prot();  // ERROR:  Cannot access protected methods from object
   // 3-3-qualifers.cpp:17: error: "void Base::prot()" is protected

// base.priv();  // ERROR:  Cannot access private methods from object
   // 3-3-qualifers.cpp:29: error: "void Base::priv()" is private

   //
   // Access the methods from DerivedPub
   //
   
   derivedPub.pub(); // legal.  Base::pub() is still public

// derivedPub.prot(); // ERROR: Cannot access protected methods from object
   // 3-3-qualifers.cpp:17: error: "void Base::prot()" is protected

// derivedPub.priv(); // ERROR: Cannot access private methods from object
   // 3-3-qualifers.cpp:19: error: "void Base::priv()" is private

   derivedPub.derivedPublic(); // legal.  Derived::derivedPublic() is public

// derivedPub.derivedProtected(); // ERROR: No access to protected methods
   // 3-3-qualifers.cpp:42: error:
   //"void DerivedPub::derivedProtec()" is protected
   
// derivedPub.derivedPrivate(); // ERROR: No access to private methods
   // 3-3-qualifers.cpp:45: error:
   //"void DerivedPub::derivedPrivate()" is private

   //
   // Access methods from DerivedPro
   //

// derivedPro.pub(); // ERROR: Was public, now protected so no access
   // 3-3-qualifers.cpp:15: error: "void Base::pub()" is inaccessible

// derivedPro.prot(); // ERROR: No access to protected methods
   // 3-3-qualifers.cpp:17: error: "void Base::prot()" is protected

// derivedPro.priv(); // ERROR: No access to private methods
   // 3-3-qualifers.cpp:19: error: "void Base::priv()" is private

   derivedPro.derivedPublic(); // legal.  derivedPublic() is public

// derivedPro.derivedProtected(); // ERROR: derivedProtected() is protected
   // 3-3-qualifers.cpp:67: error:
   //"void DerivedPro::derivedProtec()" is protected
   
// derivedPro.derivedPrivate(); // ERROR: derivedPrivate() is private
   // 3-3-qualifers.cpp:71: error:
   //"void DerivedPro::derivedPrivate()" is private

   //
   // Access methods from DerivedPriv
   //
   
// derivedPriv.pub(); // ERROR: was public now is private
   // 3-3-qualifers.cpp:15: error: "void Base::pub()" is inaccessible

// derivedPriv.prot(); // ERROR: was protected now is private
   // 3-3-qualifers.cpp:17: error:
   //"void Base::prot()" is protected

// derivedPriv.priv(); // ERROR: private methods are not accessible here
   // 3-3-qualifers.cpp:19: error: "void Base::priv()" is private

   derivedPriv.derivedPublic(); // legal: publics are accessible from object

// derivedPriv.derivedProtected(); // ERROR: protected is not accessible here
   // 3-3-qualifers.cpp:93: error:
   //"void DerivedPriv::derivedProt()" is protected

// derivedPriv.derivedPrivate(); // ERROR: private is not accessible here
   // 3-3-qualifers.cpp:97: error:
   //"void DerivedPriv::derivedPrivat()" is private
   
   return 0;
}
