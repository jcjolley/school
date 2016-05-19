#ifndef __Skeet__powerups__
#define __Skeet__powerups__
#include "vector.h"

class Powerups
{
private:
   Powerups();
   void regenerate(int level);
   void draw();
   void advance();
   bool isDead();
   Vector & getVector() { return vector; }
   int getSize()  const { return diamPowerup; }
   void kill();
   
public:
   Vector vector;
   int diamPowerup;
};

#endif /* defined(__Skeet__powerups__) */
