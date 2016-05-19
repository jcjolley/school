/***********************************************************************
* Program:
*    SOUNDMANAGER.CPP, Skeet
*    Brother Helfrich, CS165
* Author:
*    Sam Barney and Joshua Jolley
* Summary:
*    This program emulates the game of Skeet, complete with menus,
*    original sound, levels, and powerups.  
*    Estimated:  15.0 hrs
*    Actual:     30.0 hrs
*    Homing was difficult to implement well, and learning how to uses
*    classess and pass the right information between classes was,
*    well, a learning experience.
**********************************************************************/

#include "SoundManager.h"
#include <iostream>
#include "callbacks.h"
using namespace std;

/**********************************************************************
 * SoundManager::SoundManager
 *    INPUTS:
 *    OUTPUTS:
 *    DESCRIPTION:
 *       Constructor. Initializes the system, checks to see if we are
 *       using the right version and sets up the file interface
 **********************************************************************/
SoundManager::SoundManager() {
   FMOD_RESULT       result;
   unsigned int      version;
   
   // Create the system
   result = FMOD::System_Create(&system);
   ERRCHECK(result);
   
   // Grab the version and check that we are using the right one
   result = system->getVersion(&version);
   ERRCHECK(result);
   
   if (version < FMOD_VERSION)
   {
      printf("Error!  You are using an old version of FMOD %08x.  This program requires %08x\n", version, FMOD_VERSION);
      return;
   }
   
   // Initilize the system
   result = system->init(32, FMOD_INIT_NORMAL, 0);
   ERRCHECK(result);
   
   // Set the file IO handlers and such
   result = system->setFileSystem(myopen, myclose, myread, myseek, 0, 0, 2048);
   ERRCHECK(result);
   
}

/**********************************************************************
 * SoundManager::isPlaying
 *    INPUTS:  const string &
 *    OUTPUTS: bool
 *    DESCRIPTION:
 *       Returns wheter the specified sound's channel is playing.
 **********************************************************************/
bool SoundManager::isPlaying(const std::string & soundname)
{
   bool isPlaying;
   if (soundname.find("Music") == string::npos)
   {
      channel->isPlaying(&isPlaying);
   }
   else
   {
      background->isPlaying(&isPlaying);
   }
   return isPlaying;
}

/**********************************************************************
 * SoundManager::play
 *    INPUTS:  const string &
 *    OUTPUTS:
 *    DESCRIPTION:
 *       Plays the sound identified by the string that was passed in.
 *       Plays music on the background channel and sound effects
 *       elsewhere.
 *       Only plays them if they exist.
 **********************************************************************/
void SoundManager::play(const string & soundname)
{
   FMOD_RESULT       result;
   FMOD::Sound * sound = sounds[soundname];
   /*
    *Play the sound.
    */
   if (soundname.find("Music") == string::npos)
   {
      result = system->playSound(FMOD_CHANNEL_FREE, sound, false, &channel);
   }
   else
   {
      result = system->playSound(FMOD_CHANNEL_FREE, sound, false, &background);
   }

   if (!ERRCHECK(result))
   {
      cerr << "SOUND NOT PLAYING: " << soundname << endl;
      exit(1);
   }
   
   system->update();
}

/**********************************************************************
 * SoundManager::stop
 *    INPUTS:  const string &
 *    OUTPUTS:
 *    DESCRIPTION:
 *       Stops background musics in their tracks. Kind of a hack
 *       because we couldn't find a way to stop a singular sound on a 
 *       channel with multiple sounds playing.
 **********************************************************************/
void SoundManager::stop(const std::string & soundname)
{
   // If we were passed a background music name
   if (soundname.find("Music") != string::npos)
   {
      // Release and erase the sound from the soundmap.
      sounds[soundname]->release();
      sounds.erase(soundname);
      // Reload the music
      load(soundname, FMOD_LOOP_NORMAL);
   }
}

/**********************************************************************
 * SoundManager::load
 *    INPUTS:  const string &, FMOD_MODE
 *    OUTPUTS: bool
 *    DESCRIPTION:
 *       Loads a sound into the sound map and return whether the sound
 *       was loaded.
 **********************************************************************/
bool SoundManager::load(const string & soundname, FMOD_MODE settings)
{
   // If the sound hasn't been loaded already
   if (sounds.find(soundname) == sounds.end())
   {
      FMOD_RESULT       result;
      string filename = soundname +".mp3";
      // Try to load the mp3 file
      result = system->createSound(filename.c_str(), FMOD_HARDWARE | settings, 0, &sound);
      
      // If we couldn't load the sound, print an error and exit abnormally
      if (!ERRCHECK(result))
      {
         cerr << "SOUND NOT LOADED: " << soundname << endl;
         exit(1);
      }
      // Otherwise, load the sound into the sound map
      sounds[soundname] = sound;
      return true;
   }
   return false;
}


/**********************************************************************
 * SoundManager::remove
 *    INPUTS: const string &
 *    OUTPUTS: bool
 *    DESCRIPTION:
 *       Deletes a sound if it exists. Returns whether it existed or
 *       not.
 **********************************************************************/
bool SoundManager::remove(const string & soundname)
{
   if(sounds.find(soundname) != sounds.end())
   {
      // Release the sound and then delete it from the map
      sounds[soundname]->release();
      sounds.erase(soundname);
      return true;
   }
   return false;
}

/**********************************************************************
 * SoundManager::~SoundManager
 *    INPUTS:
 *    OUTPUTS:
 *    DESCRIPTION:
 *       Deconstructor for the Sound Manager Class. Releases all of the
 *       sounds that were loaded, shuts down the system and releases it
 **********************************************************************/
SoundManager::~SoundManager()
{
   FMOD_RESULT result;
   // Design sound release iterator
   for(map<string, FMOD::Sound*>::iterator iter = sounds.begin(); iter != sounds.end(); iter++)
   {
    
      iter->second->release();
   }
   
   result = system->close();
   ERRCHECK(result);
   result = system->release();
   ERRCHECK(result);
}