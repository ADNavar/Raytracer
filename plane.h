#ifndef PLANE_H
#define PLANE_H

#include <iostream>
#include "sceneobj.h"
#include "hitinfo.h"

using namespace std;

class plane_t : public sobj_t {
   public:
      plane_t(ifstream &infile);
      void load(ifstream &infile);
      myvector getpoint();
      myvector getnormal();
      int hits(myvector &base, myvector &dir, hitinfo_t &hit);
      void   dump();

  protected:
      myvector point;
      myvector normal;
      myvector orient1;
      myvector orient2;
};

#endif
