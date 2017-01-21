/* window.c */

#ifndef WINDOW_H
#define WINDOW_H

#define WINDOW_T 3311657

#include "ray.h"

class window_t : public entity_t
{
  public:
     window_t(ifstream &infile);
     void load(ifstream &infile); 
     void dump();
     double getWindowWidth();
     double getWindowHeight();
     myvector getViewPoint();
     myvector getAmbient();
     int getPixelColumns();

  private:
     double windowWidth;
     double windowHeight;
     myvector viewPoint;
     myvector ambient;
     int pixelColumns; 
};

#endif
