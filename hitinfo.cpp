/** hitinfo_t class 

    A hitinfo_t is used to pass information about a hit on an entity

**/

#include "hitinfo.h"

using namespace std;

void hitinfo_t::setdistance(const double &value) {
   distance = value;
}

void hitinfo_t::sethitpoint(const myvector &H) {
   hitpoint = H;
}

void hitinfo_t::setnormal(const myvector &N) {
   normal = N;
}

double   hitinfo_t::getdistance() { 
   return(distance); 
}

myvector hitinfo_t::gethitpoint() { 
   return(hitpoint); 
}

myvector hitinfo_t::getnormal() { 
   return(normal);
}
