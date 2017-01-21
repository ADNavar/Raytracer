/**
	Andrew Navarro (adnavar)

    Ray 2
    Fall 2015

    ray.cpp - this file implements the genray 
    and raytrace functions
    
**/


#include "ray.h"

/** genRay **/
myvector genRay(scene_t *scene, int column, int row) {
   double x;
   double y;
   double z;

   myvector dir;              // Directior vector
   window_t *window;
   image_t *picture;
   window = scene->getWindow();
   picture = scene->getPicture();

   /* Computer the pixel's real scene coordinates */
   x = ((double)(column)/
      (double)(picture->columns-1))*window->getWindowWidth();
   x -= window->getWindowWidth()/2.0;
   
   y = ((double)(row)/
      (double)(picture->rows-1))*window->getWindowHeight();
   y -= window->getWindowHeight()/2.0;
   
   z = 0;

   dir = myvector(x, y, z);
   /* And now construct a unit vector from the view point to the pixel */
   dir = dir.diff(window->getViewPoint());
   dir = dir.unitvec();
   return dir;
} /* End genRay */

/** rayTrace **/
myvector rayTrace(scene_t *scene, myvector base, myvector unitDir, double total_dist, entity_t *self) {

   double x;
   double y;
   double z;
	myvector refl;
	double kSubS = 0.5;
   hitinfo_t newHit;
   myvector intensity (0.0,0.0,0.0);
   mycolor  closeColor(0.0, 0.0, 0.0);
   myvector  ambient(0.0,0.0,0.0);
   window_t *win;
   sobj_t *close = (sobj_t *)closest(scene, base, unitDir, self, newHit);
   
   if(close == NULL)
   {
      return myvector(0,0,0);
   }
   
   total_dist += newHit.getdistance();
   win = (window_t *)scene->getWindow();
   
   ambient = win->getAmbient();
   closeColor = close->getcolor();
   
   x = closeColor.getR() * ambient.getx();
   y = closeColor.getG() * ambient.gety();
   z = closeColor.getB() * ambient.getz();

   intensity = myvector(x, y, z);
   
   // create a vector storing the diffuse light
   // and add to the intensity
   myvector diffuse_light = lighting(scene,close,newHit);
   intensity = intensity.sum(diffuse_light);

	// do some weird shit with specular shading
	// add this vector to intensity
	

   // add the diffuse_light at the hitpoint to the intesnity
   intensity = intensity.scale(1.0/255.0);
   intensity = intensity.scale(1.0/total_dist);
   return intensity;
} /* End rayTrace */

entity_t *closest(scene_t *scene, myvector base, 
            myvector unitDir, entity_t *self, hitinfo_t &hit) {
   
   entity_t *obj;
   entity_t *close = NULL;
   iterator_t *objiter; 
   objiter = newIterator(scene->sobjList);
   hitinfo_t currhit;

   double mindist = 999999;
   int isHit;
   
   while((obj = (entity_t *)l_next(objiter)) != NULL)
   {
       isHit = obj->hits(base,unitDir,currhit);
       if(isHit)
       {
           if(currhit.getdistance() < mindist)
           {
               close = obj;
               mindist = currhit.getdistance();
	           hit.setdistance(currhit.getdistance());
               hit.sethitpoint(currhit.gethitpoint());
               hit.setnormal(currhit.getnormal());
           }
       }
   }

   free(objiter);
   return(close);
} /* End closest */

