/** main.cpp 

    Main program for ray tracer

**/
#include "ray.h"
#include <fstream>

using namespace std;

int main( int argc, char *argv[])
{
   ifstream infile;
   FILE *outfile;
   
   /* Open scene definition file */
   if (argc != 3) {
      fprintf(stderr, "Usage: ./ray mdl_file ppm_image_file\n");
      exit(1);
   }

   infile.open(argv[1], ios::in);
   assert(infile != NULL);

   scene_t *scene = new scene_t(infile);

   outfile = fopen(argv[2], "w");
   assert(outfile != NULL);

   /* Load and dump scene data */
   

   scene->dumpScene();

   /* Render the image */
   render(scene);

   /* And output the image to a PPM file */
   //strcpy(outFile, argv[2]);
   outImage(outfile, scene->getPicture());

   return 0;
}

