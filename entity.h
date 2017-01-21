/** 

    Note use of "virtual" methods below.  The virtual modifier
    allows a method to be redefined in a derived class (something
    we can do with or without the virtual modifier) AND results in
    the method in the derived class being invoked when referenced
    via a pointer to the base class.

    Note that we have to provide a virtual destructor, even if it is
    a do nothing destructor, and that the code for the virtual method
    must be provided in the base class even if it is over-riden in the
    derived class and never called.

    For this demonstration example the virtual modifier is only used
    for load(), dump() and hits().  In a full implementation of the 
    ray tracer we would make many more functions virtual.

**/

#ifndef ENT_H
#define ENT_H

#include <iostream>
#include "hitinfo.h"
#include "myvector.h"
#include "mycolor.h"
#include <stdlib.h>
#include <fstream>
using namespace std;

class entity_t {
   public:
      // Constructor
      entity_t(ifstream &infile, const string & entTypeVal);
      virtual ~entity_t();           // Note virtual destructor

      // Methods
      virtual void load(ifstream &infile);
      virtual void dump();
      virtual int hits(myvector &base, myvector &dir, hitinfo_t &hit);
      string gettype();
      string getname();

  private:
      string type;
      string name;
};

#endif
