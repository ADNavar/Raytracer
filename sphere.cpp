
#include "sphere.h"
#include "math.h"

using namespace std;

// Constructor
sphere_t:: sphere_t(ifstream &infile) : sobj_t(infile, "sphere")
{
  center = myvector(); // intialize point to <0,0,0>
  
  load(infile);  
}

// loads a sphere_t object from a file
void sphere_t:: load(ifstream &infile) 
{
   string token;

   infile >> token;
   while(token != ";")
   {
      if (token == "center") {
         infile >> center;
      }
      else
      if (token == "radius") {
         infile >> radius;
      }
      else 
      {
         cerr << "Unknown sphere attribute " << token << "exiting." 
              << endl;
         exit(1);
      }
      infile >> token;
   }
}

// returns the center of a sphere
myvector sphere_t::getcenter(){
  myvector my_center ( center.getx(), center.gety(), center.getz());
  return my_center;
}

// returns the radius of a sphere
double sphere_t::getradius(){

  return radius;

}

// tests where a sphere_t object is hit by a view point
// returns a 1 if the sphere is hit and a 0 if it isn't
int sphere_t::hits(myvector &base, myvector &dir, hitinfo_t &hit){

  double a,b,c,discriminant,t_h;
  dir = dir.unitvec();

  myvector new_base = base + center*-1.0;
  myvector hit_point;

  // first calculate the values for the quadratic formula
  a = dir.dot(dir);
  b = 2*new_base.dot(dir);
  c = new_base.dot(new_base) - radius*radius;

  discriminant = b*b - 4*a*c;

  if (discriminant <= 0)   return 0;

  t_h = (-b - sqrt(discriminant))/(2*a);
  if (t_h<0) return 0;

  hit_point = base + dir*t_h;
  if (hit_point.getz() > 0) return 0;
  
  hit.sethitpoint(hit_point);
  myvector normal_temp = hit_point+center*-1;
  hit.setnormal(normal_temp*normal_temp.length());
  myvector distance_temp = hit_point*-1 + base;
  hit.setdistance(distance_temp.length());

  return 1;
}

// dumps the information related to a sphere_t object
void sphere_t::dump(){
  
  entity_t::dump();
  cerr << "   color:       " << sobj_t::getcolor() << endl;
  cerr << "   diffuse:     " << sobj_t::getdiffuse() << endl;
  cerr << "   reflective:  " << sobj_t::getreflective() << endl;
  cerr << "   center:     " << center << endl ;
  cerr << "   radius:     " << radius << endl;
 
}
