/***********************************************************************
 * Program:
 *    Exploration 5, Neatness
 *    Brother Neff, CS 238
 * Author:
 *    You
 * Summary:
 *    Boolean Network building and simulating.
 *
 ***********************************************************************/

#include <iostream>
#include <string>
using namespace std;

/*************************************************************************
 * What was learned to be implemented more granularly in neatness.cpp
 * via these 9 functions.
 *************************************************************************/
void howIcategorizedThePatternsIobserved();
void howIMasteredTheBasicTerminologyAndOperationsOfBooleanLogicAndGatingNetworks();
void howIDemonstratedDiscreteMathematicalReasoningThroughSolvingProblems();
void howIDiscernedBetweenEffectiveAndIneffectiveApproachesToProblemSolving();
void howISolvedProblemsUsingLimitedOrConstrainedResources();
void howISynthesizedNewProblemSolvingConceptsByPuttingOldConceptsTogetherInNovelWays();
void howIRecognizedTheRelativeImportanceOfDifferentElementsOfAMathematicalOrComputerScienceProblem();
void howIMadeConnectionsBetweenDiscreteMathematicsAndRealWorldApplications();
void howIKnowHowDiscreteMathematicsAppliesToAllPartsOfComputerScience();

void learned()
{
   howIcategorizedThePatternsIobserved();

   howIMasteredTheBasicTerminologyAndOperationsOfBooleanLogicAndGatingNetworks();

   howIDemonstratedDiscreteMathematicalReasoningThroughSolvingProblems();

   howIDiscernedBetweenEffectiveAndIneffectiveApproachesToProblemSolving();

   howISolvedProblemsUsingLimitedOrConstrainedResources();

   howISynthesizedNewProblemSolvingConceptsByPuttingOldConceptsTogetherInNovelWays();

   howIRecognizedTheRelativeImportanceOfDifferentElementsOfAMathematicalOrComputerScienceProblem();

   howIMadeConnectionsBetweenDiscreteMathematicsAndRealWorldApplications();

   howIKnowHowDiscreteMathematicsAppliesToAllPartsOfComputerScience();
}

/*************************************************************************
 * How to use this program to be implemented in neatness.cpp
 *************************************************************************/
void usage(const char* programName);

/****************************************************************
 * getArgs gets command-line arguments.
 ****************************************************************/
void getArgs(int argc, char* argv[],
             unsigned int& booleanFunctionNumber,
             unsigned int& numberOfCells,
             unsigned int& numberOfSteps);

/****************************************************************
 * buildNetworkAndStartItRunning should do just that.
 ****************************************************************/
void buildNetworkAndStartItRunning(unsigned int booleanFunctionNumber,
                                   unsigned int numberOfCells,
                                   unsigned int numberOfSteps);

/****************************************************************
 * main looks at its command-line parameters.
 * If none, it calls two functions in order, namely
 *   learned
 *   usage
 *
 * Otherwise it calls getArgs
 * and then buildNetworkAndStartItRunning
 * to do just that.
 ****************************************************************/
int main(int argc, char* argv[])
{
   if (argc <= 1)
   {
      learned();
      usage(argv[0]);
      return 0;
   }
   else
   {
      unsigned int booleanFunctionNumber;
      unsigned int numberOfCells;
      unsigned int numberOfSteps;

      getArgs(argc, argv, booleanFunctionNumber,
              numberOfCells, numberOfSteps);
              
      buildNetworkAndStartItRunning(booleanFunctionNumber,
                                    numberOfCells, numberOfSteps);
   }

   return 0;
}
