/***********************************************************************
 * Program:
 *    Exploration 5, Neatness
 *    Brother Neff, CS238
 *
 * Author:
 *    Joshua Jolley
 *
 * Summary:
 *    Boolean Network building and simulating.
 *
 * Note:
 *    Some of this code is uncommented --- this is deliberate.
 *
  g++ -o neatness neatness.cpp neatnessCLI.cpp
neatness.cpp:230:14: error: variable length array of non-POD element type 'Wire'
   Wire wires[numberOfCells];
             ^
1 error generated.
 ***********************************************************************/

#include <cassert>
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <vector>
#include <fstream>
using namespace std;

/*******************************************************************
 * A class that represents a Wire with a current and a new boolean
 * value.  The new value is set by the operation of a Cell, and it
 * will become the current value after being updated, which typically
 * happens right before showing (outputting) the value.
 *******************************************************************/
class Wire
{
private:
   bool mValue;
   bool mNewValue;
   bool mUseStarAndBlank;

public:
   /****************************************************************
    * Constructs a new wire instance with a default value (false).
    ****************************************************************/
   Wire()
   {
      setValue(false);
      setNewValue(false);
      setUseStarAndBlank(true);
   }

   /****************************************************************
    * Constructs a new wire instance with a given value.
    ****************************************************************/
   Wire(bool pValue, bool pUseStarAndBlank = true)
   {
      setValue(pValue);
      setNewValue(false);
      setUseStarAndBlank(pUseStarAndBlank);
   }

   /******************************
    * Gets this wire's value.
    *******************************/
   bool getValue() const { return mValue; }

   /******************************
    * Gets this wire's new value.
    *******************************/
   bool getNewValue() const { return mNewValue; }

   /******************************
    * Sets this wire's value.
    *******************************/
   void setValue(bool pValue) { mValue = pValue; }

   /******************************
    * Sets this wire's new value.
    *******************************/
   void setNewValue(bool pNewValue) { mNewValue = pNewValue; }

   /******************************
    * Sets this wire's value to its new value.
    *******************************/
   void setValueToNew() { mValue = mNewValue; }

   /******************************
    * Gets this wire's display mode.
    *******************************/
   bool isUsingStarAndBlank() const
   {
      return mUseStarAndBlank;
   }

   /******************************
    * Sets this wire's display mode.
    *******************************/
   void setUseStarAndBlank(bool pUseStarAndBlank)
   {
      mUseStarAndBlank = pUseStarAndBlank;
   }

   /****************************************************
    * Gets the character representing this wire's value.
    ****************************************************/
   string getCharacterRepresentingValue() const
   {
      return
         (isUsingStarAndBlank() ?
          (getValue() ? "\u2588" : "\u2591") :
          (getValue() ? "1" : "0"));
   }
};

/****************************************************************
 * Outputs a Wire.
 ****************************************************************/
ostream& operator<<(ostream& os, const Wire& w)
{
   os << w.getCharacterRepresentingValue();
   return os;
}

/****************************************************************
 * A class representing a Boolean function of degree 3.
 ****************************************************************/
class BooleanFunction3
{
protected:
   bool mValues[8];
public:
   BooleanFunction3()
   {
      for (int i = 0; i < 8; i++)
      {
         mValues[i] = false;
      }
   }

   BooleanFunction3(int values)
   {
      populate(values);
   }

   bool evaluate(bool p1, bool p2, bool p3)
   {
      int i = 0;
      if (p3)
      {
         i |= 1;
      }
      if (p2)
      {
         i |= 2;
      }
      if (p1)
      {
         i |= 4;
      }
      return mValues[i];
   }

   void populate(int values)
   {
      int i = 0;
      while (values > 0)
      {
         mValues[i++] = ((values & 1) == 1);
         values /= 2;
      }
   }
};

/****************************************************************
 * A Cell evaluating a boolean function of degree 3.
 ****************************************************************/
class Cell
{
public:
   /****************************************************************
    * Constructs a new Cell instance with a pointer to a Boolean
    * Function of degree 3, and three wires.
    *
    * This merely has the side effect of computing the boolean
    * function on the three wire inputs, storing the result in the
    * middle (output) wire.
    ****************************************************************/
   Cell(BooleanFunction3 * bfp, Wire& x, Wire& y, Wire& z)
   {
      y.setNewValue(bfp->evaluate(
         x.getValue(), y.getValue(), z.getValue()));
   }
};

/****************************************************************
 * getArgs gets command-line arguments.
 ****************************************************************/
void getArgs(int argc, char* argv[],
             unsigned int& booleanFunctionNumber,
             unsigned int& numberOfCells,
             unsigned int& numberOfSteps)
{
   // TODO 1: get program input a better way.

   assert(argc > 1);

   booleanFunctionNumber = atoi(argv[1]);

   numberOfCells = 100;

   if (argc > 2)
   {
      numberOfCells = atoi(argv[2]);
   }

   numberOfSteps = numberOfCells;

   if (argc > 3)
   {
      numberOfSteps = atoi(argv[3]);
   }
}

/****************************************************************
 * buildNetworkAndStartItRunning should do just that.
 ****************************************************************/
void buildNetworkAndStartItRunning(unsigned int booleanFunctionNumber,
                                   unsigned int numberOfCells,
                                   unsigned int numberOfSteps)
{
   // TODO 2: create numberOfCells Wires.
   Wire wires[numberOfCells];
   
   // TODO 3: set to true the new value of the middle-most Wire
   wires[numberOfCells / 2].setNewValue(true);     
   
   for (int i = 0; i < numberOfCells; i++)
   {
      // TODO 4: update values to new values and show (output) all Wires.
      wires[i].setValueToNew();
      cout << wires[i];  
   }
   cout << endl;

   // TODO 5: create a BooleanFunction3 given the booleanFunctionNumber.
   BooleanFunction3 bf3(booleanFunctionNumber);
   
   // TODO 6: iterate TODO 7 and TODO 8 for numberOfSteps steps.
   for (int i = 0; i < numberOfSteps; i++)
   {
      for(int j = 0; j < numberOfCells; j++)
      {
         // TODO 7: create the network of Cells evaluating the BooleanFunction3
         // and connect them to the already-created Wires in the desired fashion.
         if (j < numberOfCells - 2)
         {
            Cell(&bf3, wires[j], wires[j + 1], wires[j + 2]);
         }
      
         // TODO 8: update values to new values and show (output) all wires.
         wires[j].setValueToNew();
         cout << wires[j];
      }
      cout << endl;
   }
}

/****************************************************************
 * For reporting on what was learned.
 ****************************************************************/
void howIcategorizedThePatternsIobserved()
{
   cout << "When doing research online into Pascal's triangle and while collaborating "
        << "with my peers I found Wolfram Alpha's page on the elementary cellular "
        << "automaton. After reviewing the page I decided not to categorize the "
        << "rules in the same way that Wolfram Alpha did. Their research was much "
        << "deeper than mine, and I didn't wish to simply copy their organization. "
        << "Their method found 88 distinct patterns. "
        << "My much more simplistic categorization has 6 groups: Diagonal, flag, "
        << "peak, Sierpinksi, single dot, and visually appealing. To categorize the files I "
        << "used a bash script to run neatness 255 times, outputting a file each "
        << "time (e.g., neatness212.out). Before moving rules into their respective "
        << "categories, I eliminated most amphichiral rules using a few simple c++ "
        << "programs combined with a bash script to automate the diffs (e.g., "
        << "reverse.cpp and diffFiles.sh).\n"; 
}

void howIMasteredTheBasicTerminologyAndOperationsOfBooleanLogicAndGatingNetworks()
{
   cout << "The website mentioned in the function 'howIcategorizedThePatternsIobserved' "
        << "helped me learn the terminology of boolean logic and gating networks "
        << "as it applies to this elementary cellular automaton. For example, I "
        << "learned that an object is amphichiral with another object if you can "
        << "superpose it with that object after mirroring it on a plane.  In more "
        << "simple terms, if you can flip and/or rotate one object and it exactly matches "
        << "another object, those objects are amphichiral.  Wolfram alpha states that "
        << "this term is synonymous with reflexible (not to be confused with reflexive).\n";
}

void howIDemonstratedDiscreteMathematicalReasoningThroughSolvingProblems()
{
   cout << "Discrete mathematics is the basis for computer science, and, by extension, "
        << "is the basis for programming in C++. By correctly implementing this "
        << "program I have demonstrated discrete mathematical reasoning. "
        << "More specifically, I used discrete mathematical reasoning when filtering "
        << "and sorting my files. Given set A where x is a member of the set A "
        << "when it is a valid output of neatness, I created set B where x is "
        << "a member of set B if, forall x in A and forall y in A where x does not equal "
        << "y, x is not amphichiral with y.  Set B was much easier to work with "
        << "than set A, which helped me solve this problem more easily.\n";
}

void howIDiscernedBetweenEffectiveAndIneffectiveApproachesToProblemSolving()
{
   cout << "One of the primary ways I discern between effective and ineffective "
        << "approaches to problem solving is by gauging my progress towards solving "
        << "the problem at hand.  Gauging this progress can be difficult. I find it "
        << "helpful to attempt to solve a more simple version of the problem first. "
        << "I will progressively simplify the problem until I can either solve it with "
        << "my approach, or decide that it would be a better use of my time to "
        << "switch to another approach because I either can't simplify the problem "
        << "any further, or my exploration has given me new ideas.\n";
}

void howISolvedProblemsUsingLimitedOrConstrainedResources()
{
   cout << "My time this semester has been very limited, so this exploration was "
        << "definitely completed with a constraint on my time. In this instance, I "
        << "took advantage of the programming tools available to me.  Instead of "
        << "manually sorting all 255 files, I wrote programs and scripts to reduce "
        << "the number of time intensive manual categorizations I would need to do. "
        << "I considered attempting to further sort the files, but estimated that "
        << "it would take more time to make the tool than it would to do the task "
        << "without it.\n";
}

void howISynthesizedNewProblemSolvingConceptsByPuttingOldConceptsTogetherInNovelWays()
{
   cout << "By combining my knowledge of set theory, circuits, bash, and c++, I "
        << "was able to complete this exploration in much less time than it would "
        << "have taken otherwise. Recognizing that logic is an abstract boolean algebra "
        << "helped me manipulate sets using that style of logic (e.g., using a forall)."
        << "Combining bash and c++ with set theory helped me reduce the number of files "
        << "I worked with, greatly simplifying the problem.\n";
}

void howIRecognizedTheRelativeImportanceOfDifferentElementsOfAMathematicalOrComputerScienceProblem()
{
   cout << "If I did not understand the relative importance of different elements of "
        << "of computer science, I would not have been able to complete this assignment "
        << "by its deadline. For example, if I had studied generating functions to the "
        << "exclusion of set theory, this assignment would have been much more difficult."
        << "The beauty of discrete mathematics does not lie in its individual elements. "
        << "Instead, it is in application of combinations of elements in discrete "
        << "mathematics.\n";
}

void howIMadeConnectionsBetweenDiscreteMathematicsAndRealWorldApplications()
{
   cout << "Computer hardware is a real world application of discrete mathematics. "
        << "Computer programs are real world applications of discrete mathematics. "
        << "The connection between discrete mathematics and computing is such that without "
        << "discrete mathematics computing would not exist.\n";
}

void howIKnowHowDiscreteMathematicsAppliesToAllPartsOfComputerScience()
{
   cout << "You may have read the first sentence of this write up and thought, "
        << "'wow, what a cop-out sentence.'  But I think it is partially illustrative of how I "
        << "know that discrete mathematics applies to all parts of computer science. "
        << "It still amazes me that the machine I am currently writing on is processing "
        << "approximately 90 billion sets of 64 binary bits per second. From such "
        << "simple building blocks spring forth representations of nearly all of "
        << "human knowledge while simultaneously providing the tools to build up that "
        << "knowledge. Discrete mathematics is the set of rules for combining these building "
        << "blocks, and thus applies to all parts of computer science.\n"; 
}

/*************************************************************************
 * How to use this program to be implemented here.
 *************************************************************************/
void usage(const char* programName)
{
   cout << "USAGE: " << programName << "[rule] [numberOfCells] [numberOfSteps]" << endl;
}

