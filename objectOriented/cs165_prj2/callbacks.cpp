/***********************************************************************
 * THIS CODE WAS NOT WRITTEN BY JOLLEY OR SAM. IT WAS BORROWED FROM THE
 * FMOD EXAMPLES>
 ***********************************************************************/

#include "SoundManager.h"

#define RELEASE


bool ERRCHECK(FMOD_RESULT result)
{
#ifndef RELEASE
   if (result != FMOD_OK)
   {
      system("pwd");
      printf("FMOD error! (%d): %s\n", result, FMOD_ErrorString(result));
      //exit(-1);
      return false;
   }
#endif
   return true;
}

FMOD_RESULT F_CALLBACK myopen(const char *name, int unicode, unsigned int *filesize, void **handle, void **userdata)
{
   if (name)
   {
      FILE *fp;
      
      fp = fopen(name, "rb");
      if (!fp)
      {
         return FMOD_ERR_FILE_NOTFOUND;
      }
      
      fseek(fp, 0, SEEK_END);
      *filesize = ftell(fp);
      fseek(fp, 0, SEEK_SET);
      
      *userdata = (void *)0x12345678;
      *handle = fp;
   }
   
   return FMOD_OK;
}

FMOD_RESULT F_CALLBACK myclose(void *handle, void *userdata)
{
   if (!handle)
   {
      return FMOD_ERR_INVALID_PARAM;
   }
   
   fclose((FILE *)handle);
   
   return FMOD_OK;
}

FMOD_RESULT F_CALLBACK myread(void *handle, void *buffer, unsigned int sizebytes, unsigned int *bytesread, void *userdata)
{
   if (!handle)
   {
      return FMOD_ERR_INVALID_PARAM;
   }
   
   if (bytesread)
   {
      *bytesread = (int)fread(buffer, 1, sizebytes, (FILE *)handle);
      
      if (*bytesread < sizebytes)
      {
         return FMOD_ERR_FILE_EOF;
      }
   }
   
   return FMOD_OK;
}

FMOD_RESULT F_CALLBACK myseek(void *handle, unsigned int pos, void *userdata)
{
   if (!handle)
   {
      return FMOD_ERR_INVALID_PARAM;
   }
   
   fseek((FILE *)handle, pos, SEEK_SET);
   
   return FMOD_OK;
}