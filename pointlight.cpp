/**
	Andrew Navarro (adnavar)

    Ray 2
    Fall 2015

    pointlight.cpp

    pointlight.cpp contains all of the functions included in the pointlight
    class,  which is a light found at a singular point.
**/


#include "pointlight.h"

using namespace std;

pointlight_t::pointlight_t(ifstream &infile) : entity_t(infile, "pointlight")
{
    /* initialize color, brightness, and center */
	color = mycolor();
	center = myvector();
	brightness = 0.0;
	
	/* load data from input file */
    load(infile);
}

/* load takes in a file and reads in the values of the provided attribute. */
void pointlight_t::load(ifstream &infile)
{
 string token;
 
   /* read label for data */
   infile >> token;

   while(token != ";")   //ends at end of object entry
   {
	   /* check label for data type */
      if (token == "color") {
         infile >> color;
      }
      else if(token == "brightness")
      {
         infile >> brightness;
      }
      else if (token == "center") {
         infile >> center;
      }
      else 
      {
         cerr << "bad point light token " << token 
              << ". exiting" << endl;
         exit(1);
      }
	  
	  /* move to next label */
      infile >> token;
   }
}



/* return center of light */
myvector pointlight_t::getcenter()
{
  /** intialize the vector with correct points **/
    myvector light_center(center.getx(),center.gety(),center.getz());
    return light_center;
}


/* return color of light */
mycolor pointlight_t::getcolor()
{
  mycolor light_color = (color.getR(),color.getG(),color.getB());
  return light_color;
}


/* returns brightness of light */
double pointlight_t::getbrightness()
{
   return brightness;
}


/* dumps data to output file */
void pointlight_t::dump()
{
  entity_t::dump();
   cerr << "   color:      " << color << endl;
   cerr << "   brightness: " << brightness << endl;
   cerr << "   center:     " << center << endl;
}


myvector pointlight_t::processLight(scene_t *scene, entity_t *ent, hitinfo_t &hit) 
{
	myvector light_ray, light_unit, diffuse, refl, n, d, v, reflective;
	double distance, angle_cos, dDotN, vDotR, specCoefficient;
	
	/* create ray from hitpoint to center of light */
	light_ray = center - hit.gethitpoint();
	
	/* find light angle */
	light_unit = ~light_ray;   
	angle_cos = light_unit.dot(hit.getnormal());
	
    /*  check for self-occlusion */
	if (angle_cos < 0) {
		return myvector(0.0, 0.0, 0.0);
	}
	
	/* find closest entity object */
        entity_t *entity_pointer = closest(scene, center, light_unit*(-1), NULL, hit);

	/* check if occluded by other object */
	if (entity_pointer != ent) {
		return myvector(0.0, 0.0, 0.0);
	}
	
	/* find distance between light and object */
	distance = light_ray.length();
	
	
	/* get diffuse from object */
	sobj_t *obj = (sobj_t *)ent;
	diffuse = obj->getdiffuse();
	
	/* compute intensity */
	myvector intensity (color.getR() * brightness, 
	                    color.getG() * brightness,
						     color.getB() * brightness);


						
	/* 	compute light's effect */		
	myvector result (diffuse.getx() * intensity.getx() * angle_cos / distance,
			           diffuse.gety() * intensity.gety() * angle_cos / distance,
			           diffuse.getz() * intensity.getz() * angle_cos / distance);

   //use normal of hit vector and the reflection of the ray
	//for specular reflection

	n = hit.getnormal();
	d = light_unit;
	n = n.scale(-1.0);
	refl = d.dot(n);
	refl = refl.scale(2.0);
	reflective = obj->getreflective();

	specCoefficient = reflective.getx()+reflective.gety()+reflective.getz();
	
	vDotR = d.dot(refl);
	vDotR = pow(vDotR, 8);
	vDotR *= specCoefficient;

	myvector spec (color.getR() * brightness, 
	               color.getG() * brightness,
						color.getB() * brightness);

	spec=spec.scale(vDotR/distance/255);

   return result.sum(spec);

}
