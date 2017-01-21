#include "ray.h"

/** render **/
void render(scene_t *scene) {
   int rowndx = 0;
   int colndx = 0;
   int height;
   int width;
   int row;
   int offset;
   
   pixel_t *pix = ((pixel_t*)scene->getPicture()->image);
   pixel_t *pixPtr;
 
   height = scene->getPicture()->rows;
   width = scene->getPicture()->columns;

   for(rowndx = 0; rowndx < height; rowndx++)
   {
       for(colndx = 0; colndx < width; colndx++)
       {
          row = height - rowndx - 1;
          offset = row * width + colndx;
         
          *(pix + offset) = makePixel(scene, colndx, rowndx);
       }
   }
   
} /* End render */

/** makePixel **/
pixel_t makePixel(scene_t *scene, int colndx, int rowndx) {
   myvector intensity;
   myvector dir;
   window_t *windowPtr;
   pixel_t pix;
   double x;
   double y;
   double z;

   dir = genRay(scene, colndx, rowndx);
   windowPtr = (window_t *)(scene->getWindow());
   intensity = rayTrace(scene, windowPtr->getViewPoint(), dir, 0.0, NULL);
   
   x = intensity.getx();
   y = intensity.gety();
   z = intensity.getz();

   if(x > 1.0)
      x = 1.0;
   
   if(y > 1.0)
       y = 1.0;
   
   if(z > 1.0)
      z = 1.0;
   
   //intensity = myvector(x, y, z);
   pix.r = (unsigned char)(255 * x);
   pix.g = (unsigned char)(255 * y);
   pix.b = (unsigned char)(255 * z);

   return pix;
} /* End makePixel */

