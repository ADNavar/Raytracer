/**

    "virtual" methods are defined in the entity_t class definition that
       allows methods referenced by a base class pointer to actually
       invoke the function in the derived class (e.g. the dump() or hits()
       function in the derived class).
    
**/

#include "entity.h"

using namespace std;

// Constructor
entity_t:: entity_t(ifstream &infile, const string &entTypeVal) {
   type = entTypeVal;
   load(infile);
}

// When we define virtual functions in a class, we also need to
//    define a "virtual" destructor in the base class.  In this
//    case this is a "do nothing" destructor.
entity_t:: ~entity_t() {
  // do nothing
}


// Methods
void entity_t::load(ifstream &infile)
{
   string token;
   infile >> token;
   while(token != ";")
   {
      if (token == "name") {
         infile >> name;
      }
      else 
      {
         cerr << "entity_t::load: Unknown attribute \"" << token << "\"" 
              << endl; 
         exit(1);
      }
      infile >> token;
   }
}

string entity_t::gettype() {
   return type;
}

string entity_t::getname() {
   return name;
}

// Even though the following method in the base class should never
//   be invoked since it is a virtual function, we still need to
//   define it to keep the compiler happy.
int entity_t:: hits(myvector &base, myvector &dir, hitinfo_t &hit) {
   cerr << "In entity_t hits function -- WHY?: objname=" << name << endl;
   return(-1);
}

// dump() is also defined as a virtual function, but it is also directly
//   invoked from the derived classes (sobj_t and light_t).
void entity_t:: dump() {
   cerr << "\nEntity name:   ";
   cerr << name;
   cerr << "\n   type =      ";
   cerr << type;
   cerr << endl;
}
