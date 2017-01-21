#ifndef HITINFO_H
#define HITINFO_H

#include <iostream>
#include "myvector.h"

using namespace std;

class hitinfo_t {
   public:
      void     setdistance(const double &value);
      void     sethitpoint(const myvector &H);
      void     setnormal(const myvector &N);
      double   getdistance();
      myvector gethitpoint();
      myvector getnormal();

  protected:
      double   distance;
      myvector hitpoint;
      myvector normal;
};

#endif
