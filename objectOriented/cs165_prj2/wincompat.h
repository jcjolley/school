/***********************************************************************
 * THIS CODE WAS NOT WRITTEN BY JOLLEY OR SAM. IT WAS BORROWED FROM THE
 * FMOD EXAMPLES.
 ***********************************************************************/
#if !defined(WINCOMPAT_INCLUDED) && !defined(PLATFORM_WINDOWS) && !defined(WIN32) && !defined(WINDOWS) && !defined(__WIN32__)
#define WINCOMPAT_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#ifndef TRUE
    #define TRUE 1
#endif
#ifndef FALSE
    #define FALSE 0
#endif

#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>
#include <termios.h>
#include <string.h>

#define _kbhit kbhit
#define _getch getch
#define Sleep(x) usleep((x)*1000)

static int            inited=0;
static struct termios ori;

static void tcatexit()
{
   tcsetattr(0,TCSANOW,&ori);
}

static void init_terminal()
{
   struct termios t;
   tcgetattr(0,&t);
   tcgetattr(0,&ori);
   t.c_lflag &= ~(ICANON);
   t.c_lflag &= ~(ECHO);
   tcsetattr(0,TCSANOW,&t);
   atexit(tcatexit);
}

static inline int kbhit()
{
  fd_set rfds;
  struct timeval tv;

   if (!inited)
   {
	  inited=1;
	  init_terminal();
   }
   
   FD_ZERO(&rfds);
   FD_SET(0, &rfds);
   tv.tv_sec = 0;
   tv.tv_usec = 10*1000;
   return select(1, &rfds, NULL, NULL, &tv)>0;
}

static inline int getch()
{
   fd_set rfds;
   
   if (!inited)
   {
	  inited=1;
	  init_terminal();
   }
   
   FD_ZERO(&rfds);
   FD_SET(0, &rfds);
   if (select(1, &rfds, NULL, NULL, NULL) > 0)
   {
	 return getchar();
   }
   else
   {
	  printf("wincompat.h: select() on fd 0 failed\n");
	  return 0xDeadBeef;
   }	 
}

#endif
