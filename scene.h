#ifndef SDL_H
#define SDL_H

#define SCENE_T  1933842

#include "scene.h"
#include "ray.h"

/** scene_t -- pointers to scene and window data **/
class scene_t
{
  public:
    scene_t(ifstream &infile);
    int getindex(char *token, char *table[]);
    void    loadScene(ifstream &infile);
    void    dumpScene();
    window_t *getWindow();
    image_t *getPicture();

   /** Lists of objects in the virtual world **/ 
   list_t  *sobjList;        /* scene objects list                */
   list_t  *lightList;       /* "Lights" list                     */

 protected:
   int magic;                /* magic number                      */

 private:
   window_t *window;          /* Window data                       */
   image_t  *picture;        /* output image                      */

};

/** scene prototype statements **/

#endif
