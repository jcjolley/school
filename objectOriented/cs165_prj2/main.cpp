/***********************************************************************
* Program:
*    MAIN.CPP, Skeet
*    Brother Helfrich, CS165
* Author:
*    Sam Barney and Joshua Jolley
* Summary:
*    This program emulates the game of Skeet, complete with menus,
*    original sound, levels, and powerups.  
*    Estimated:  15.0 hrs
*    Actual:     30.0 hrs
*    Homing was difficult to implement well, and learning how to uses
*    classess and pass the right information between classes wwas,
*    well, a learning experience.
**********************************************************************/




#include "scene.h"
#include "uiInteract.h"


float Point::xMin = -300.0;
float Point::xMax =  300.0;
float Point::yMin = -300.0;
float Point::yMax =  300.0;


/***********************************************************************
 * Main
 * Creates an interface and an instance of scene to 
 **********************************************************************/
int main (int argc, char * * argv)
{
   Interface ui(argc, argv, "Test");  //create ui
   Scene scene;                       //create scene
   ui.run(callBack, &scene);          //pass it off to ui
   return 0;
}