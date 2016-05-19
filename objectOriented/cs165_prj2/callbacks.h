/***********************************************************************
 * THIS CODE WAS NOT WRITTEN BY JOLLEY OR SAM. IT WAS BORROWED FROM THE
 * FMOD EXAMPLES>
 ***********************************************************************/

#ifndef SoundManager_callbacks_h
#define SoundManager_callbacks_h

bool ERRCHECK(FMOD_RESULT result);

FMOD_RESULT F_CALLBACK myopen(const char *name, int unicode, unsigned int *filesize, void **handle, void **userdata);

FMOD_RESULT F_CALLBACK myclose(void *handle, void *userdata);

FMOD_RESULT F_CALLBACK myread(void *handle, void *buffer, unsigned int sizebytes, unsigned int *bytesread, void *userdata);

FMOD_RESULT F_CALLBACK myseek(void *handle, unsigned int pos, void *userdata);

#endif
