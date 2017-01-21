#ifndef POINTLIGHT_H
#define POINTLIGHT_H

#include <iostream>
#include "entity.h"
#include "lighting.h"
using namespace std;

class pointlight_t : public entity_t 
{
   public:
      pointlight_t(ifstream &infile);

      void load(ifstream &infile);
      myvector getcenter();
      mycolor  getcolor();
      double   getbrightness();
      void     dump();
      myvector processLight (scene_t *scene, entity_t *ent, hitinfo_t &hit);

  protected:
      myvector center;
      mycolor color; // Okay, I know color is not a vector, but this is a hack
      double   brightness;
};

#endif
