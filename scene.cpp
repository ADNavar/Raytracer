#include "ray.h"

using namespace std;

/** getindex **/

/** constructor  **/
scene_t::scene_t(ifstream &infile)
{
   sobjList = newList();
   lightList = newList();

   loadScene(infile);
}

/** loadScene **/
void scene_t::loadScene(ifstream &infile)
{
   string token;
   sobj_t *obj;
   pointlight_t *lgt;
// entity_t::load(ifstream, token);

   /* Start processing scene description language */
   while (infile >> token)
   {
      if(token == "window") 
      {
         window = new window_t(infile);
      }   
      else if(token == "plane")
      {
         obj = new plane_t(infile);
         l_add(sobjList, (void *)obj);
      }
      else if (token == "sphere")
      {
         obj = new sphere_t(infile);
         l_add(sobjList, (void *)obj);
      }
      else if(token == "pointlight")
      {
         lgt = new pointlight_t(infile);
         l_add(lightList, (void *)lgt);
      } 
      else
      {
         cerr << "scene_t::loadScene: Unknown token " << token << endl;
         exit(1);
      }
    }

/** completeScene **/
   // assert(window->magic == WINDOW_T);

   picture = newImage(window->getPixelColumns(), 
             window->getPixelColumns()*
             window->getWindowHeight()/
             window->getWindowWidth(), 255);
}

/** dumpScene **/
void scene_t::dumpScene()
{
   entity_t *obj;         // object_t pointer
   iterator_t *objiter;    // iterator to walk through list

   //assert(scene->magic == SCENE_T);


    cerr <<  "\nPixel Height :    " 
        << picture->rows << endl;

   /* First dump the window data */
   /* Print the separately computed pixel rows value */
   
    cerr << "\nDUMP OF WINDOW\n";
    window->dump();

   /* Now dump the scene objects list */
   cerr <<  "\nDUMP OF SCENE OBJECTS:\n";
   objiter = newIterator(sobjList);
   while(l_hasnext(objiter))
   {
       obj = (entity_t *)l_next(objiter);
       obj->dump();

   }
   free(objiter);

   /* Next print light data */
   cerr << "\nDUMP OF LIGHT LIST:\n";
   objiter = newIterator(lightList);

   while(l_hasnext(objiter))
   {
      obj = (entity_t *)l_next(objiter);
      obj->dump();
   }
 
   free(objiter);

}


window_t * scene_t::getWindow()
{
   return window;
}

image_t *scene_t::getPicture()
{
   return picture;
}
