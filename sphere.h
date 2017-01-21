#ifndef SPHERE_H
#define SPHERE_H

#include <iostream>
#include "sceneobj.h"
#include "hitinfo.h"

using namespace std;

class sphere_t : public sobj_t 
{
   public:
      // Constructor
      sphere_t(ifstream &infile);

      // Methods
      void     load(ifstream &infile);
      myvector getcenter();
      double   getradius();
      int      hits(myvector &base, myvector &dir, hitinfo_t &hit);
      void     dump();

  protected:
      myvector center;
      double   radius;
};

#endif
