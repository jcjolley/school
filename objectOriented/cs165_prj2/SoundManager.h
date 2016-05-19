/***********************************************************************
* Program:
*    SOUNDMANAGER.H, Skeet
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
//
//  SoundManager.h
//  FMOD_Test
//
//  Created by Samuel Barney on 10/11/12.
//  Copyright (c) 2012 ImagineIt! Studios. All rights reserved.
//

#ifndef __FMOD_Test__SoundManager__
#define __FMOD_Test__SoundManager__


#include "wincompat.h"
#include "fmod.hpp"
#include "fmod.h"
#include "fmod_errors.h"
#include <string>
#include <map>


/***********************************************************************
 * SoundManager Class
 *    This class handles the loading, playing, stopping and unloading
 *    of sounds or music that will be played within the game.
 **********************************************************************/
class SoundManager
{
   std::map<std::string, FMOD::Sound*> sounds;
   FMOD::Sound      *sound;
   FMOD::System     *system;
   FMOD::Channel    *channel;
   FMOD::Channel    *background;
   
public:
   void update() { system->update(); }
   bool isPlaying(const std::string & soundname);
	SoundManager();
   bool load(const std::string & soundname, FMOD_MODE settings = FMOD_LOOP_OFF | FMOD_2D);
   bool remove(const std::string & filename);
   void play(const std::string & soundname);
   void stop(const std::string & soundname);
   FMOD::Sound * getSound(std::string soundname);
   void go();
	~SoundManager();
};
bool ERRCHECK(FMOD_RESULT result);

#endif /* defined(__FMOD_Test__SoundManager__) */
