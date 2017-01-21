#include "ray.h"

using namespace std;

/** newWindow **/
window_t::window_t(ifstream &infile) : entity_t(infile, "window")
{ 
   /* Set the default values */
   windowWidth = 4;
   windowHeight = 4;
   viewPoint = myvector(0, 0, 5);
   ambient = myvector(1, 1, 1);
   pixelColumns = 600;

    load(infile);
   /* Set the window_t's magic number */
   //magic = WINDOW_T;

} /* End window_t */

/** loadWindow **/
void window_t::load(ifstream &infile) {
   /* Attributes recognized by loadWindow */
   string token;
   infile >> token;
   while(token != ";")
   {
      if(token == "windowwidth")
      {
          infile >> windowWidth;
      }
      else if(token == "windowheight")
      { 
          infile >> windowHeight;
      } 
      else if(token == "columns")
      {
         infile >> pixelColumns;
      }
      else if(token == "viewpoint")
      {
         infile >> viewPoint;
      }
      else if(token == "ambient")
      {
          infile >> ambient;
      }
      else
      {
          cerr << "Unknown window token " << token
               << ". exiting." << endl;
          exit(1);
      }
      infile >> token;
   }
} /* End load */


/** dumpWindow **/
void window_t::dump() 
{
   entity_t::dump();
   cerr << "   Pixel Width:       " << pixelColumns << endl;
   cerr << "   World Width:       " << windowWidth << endl;
   cerr << "   World Height:      " << windowHeight << endl;
   cerr << "   viewPoint:         " << viewPoint << endl;
   cerr << "   ambient intensity: " << ambient << endl;
} /* End dump window */

int window_t::getPixelColumns()
{
   return pixelColumns;
}

double window_t::getWindowWidth()
{
  return windowWidth;
}

double window_t::getWindowHeight()
{
  return windowHeight;
}

myvector window_t::getViewPoint()
{
   return viewPoint;
}

myvector window_t::getAmbient()
{
   return ambient;
}
