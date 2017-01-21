
#include "plane.h"
#include "hitinfo.h"

using namespace std;

// Constructor
plane_t:: plane_t(ifstream &infile) : sobj_t(infile, "plane")
{
   point = myvector();  // initalize point to <0,0,0>
   normal = myvector(); // initalize normal to <0,0,0>

   load(infile);
   normal = orient1.cross(orient2);
}

// loads a plane_t object from a file
void plane_t:: load(ifstream &infile)
{
   string token;
   infile >> token;

   while(token != ";")
   {
      if (token == "orient1") {
         infile >> orient1;
      }
      else if(token == "orient2")
      {
         infile >> orient2;
      }
      else if (token == "point") {
         infile >> point;
      }
      else 
      {
         cerr << "bad plane token " << token 
              << ". exiting" << endl;
         exit(1);
      }
      infile >> token;
   }
}

/*  Return a point on the plane  */

myvector plane_t::getpoint(){
  myvector point_on_plane = (point.getx(),point.gety(),point.getz());
  return point_on_plane;
}


/*  Return the plane's normal  */

myvector plane_t::getnormal(){
  myvector plane_normal(normal.getx(), normal.gety(), normal.getz());
  return plane_normal;
}


/* detect if plane is hit */

int plane_t::hits (myvector &base, myvector &dir, hitinfo_t &hit){
  myvector hit_point;
  double hit_distance;
  myvector normal = getnormal();

  /* check if ray is parallel to plane */
  if (normal.dot(dir) ==   0) {
	  return 0;
  }
  
  /* calculate hit distance */
  hit_distance = ((normal.dot(point) - normal.dot(base)) / normal.dot(dir));
  
  /* check if hit lies behind viewpoint */
  if (hit_distance < 0) {
	  return 0;
  }
  
  /* calculate hit point */
  hit_point = base + (dir * hit_distance);
  
  /* check if hit lies behind screen */
  if (hit_point.getz() > 0) {
	  return 0;
  }
  
  /* set hit info */
  hit.setnormal(normal);
  hit.setdistance(hit_distance);
  hit.sethitpoint(hit_point);
  
  return 1;
}


/* dump info to std_err */

void plane_t::dump(){
  entity_t::dump();
  cerr << "   color:       " << sobj_t::getcolor() << endl;
  cerr << "   diffuse:     " << sobj_t::getdiffuse() << endl;
  cerr << "   reflective:  " << sobj_t::getreflective() << endl;
  cerr << "   point:       " << point << endl;
  cerr << "   orient1:     " << orient1 << endl;
  cerr << "   orient2:     " << orient2 << endl;
  cerr << "   normal:      " << normal << endl;
}
