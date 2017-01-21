#ifndef SOLID_H
#define SOLID_H

#include <iostream>
#include "entity.h"
#include "myvector.h"
#include "mycolor.h"

using namespace std;

class sobj_t : public entity_t {
   public:
      // Constructor
      sobj_t(ifstream &infile, const string & objtype);

      // Methods
      void     load(ifstream &infile);
      mycolor   getcolor();
      myvector  getdiffuse();
      myvector  getreflective();
      void     dump();

  private:
      //myvector color;
      mycolor color;
      myvector diffuse;
      myvector reflective;
};

#endif
