/***********************************************************************
 * This demo program is designed to:
 *      Demonstrate Polymorphism
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*********************************************
 * PERSON
 * Base class
 *********************************************/
class Person
{
public:
   Person(const string & s)             { name = s;                        }
   virtual void display() const         { cout << name << endl;            }
protected:
   string name;
};

/*********************************************
 * MALE
 * First derived class
 *********************************************/
class Male : public Person
{
public:
   Male(const string & s) : Person(s)   {                                  }
   void display() const                 { cout << "Mr. " << name << endl;  }
};

/*********************************************
 * FEMALE
 * Second derived class
 *********************************************/
class Female : public Person
{
public: 
   Female(const string & s) : Person(s) {                                  }
   void display() const                 { cout << "Mrs. " << name << endl; }
};


/**********************************************************************
 * main()...
 ***********************************************************************/
int main()
{
   // first, we will create a bunch of people.
   Male   male1(  string("Hooper"));
   Male   male2(  string("Rothey"));
   Male   male3(  string("Hurst"));
   Female female1(string("Richards"));
   Female female2(string("Dewey"));
   Female female3(string("Summers"));
   Female female4(string("Peterson"));

   // A collection of people. Note that each is a pointer to a Person,
   // not a Person.  If we make them a Person then we will have the
   // slicing problem and they will loose their gender.
   vector <Person *> people;

   // add them to my collection of people
   people.push_back(&male1);
   people.push_back(&male2);
   people.push_back(&female1);
   people.push_back(&female2);
   people.push_back(&female3);
   people.push_back(&male3);
   people.push_back(&female4);

   // Note how the vector only knows about Persons.  It knows nothing
   // about males or females.  Yet somehow the correct display
   // function is called for each.  This is because we are
   // using polymorphism; each person has a vtable which
   // points to the correct function
   for (int i = 0; i < people.size(); i++)
      people[i]->display();
   return 0;
}
