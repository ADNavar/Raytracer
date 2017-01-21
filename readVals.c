
#include "ray.h"
/** readInt 

    Reads a single integer value.  If an error is encountered the provided
    error message is printed and the program is terminated.
**/
int readInt(FILE *infp, char *errmsg) {
    int result;
    if (fscanf(infp, "%d", &result) != 1) {
       /* Error exit */
       fprintf(stderr,"%s\n", errmsg);
       exit(1);
    }
    return(result);
}

/** readDouble

    Reads a single double value.  If an error is encountered the provided
    error message is printed and the program is terminated.
**/
//double readDouble(FILE *infp, char *errmsg) {
double readDouble(FILE *infp, string errmsg) {
    double result;
    if (fscanf(infp, "%lf", &result) != 1) {
       /* Error exit */
       cerr << errmsg << endl;
       exit(1);
    }
    return(result);
}

/** readString

    Reads a single "word".  If an error is encountered the provided
    error message is printed and the program is terminated.
**/
char *readWord(FILE *infp, const char *errmsg) {
    char buffer[100];
    if (fscanf(infp, "%s", buffer) != 1) {
       /* Error exit */
       fprintf(stderr,"%s\n", errmsg);
       exit(1);
    }
    return(strdup(buffer));
}

/** readColor()

    Converts the decimal values, color name or hex value to the 
    3 byte RGB field

    Returns the rgb values if successful.  Or error prints errmsg and
    exits.
**/
pixel_t readColor(FILE *infile, const char *errmsg) {
   int ndx;             /* Array index                          */
   unsigned int value;  /* RGB integer value                    */
   char word[20];       /* input word buffer                    */
   int code;            /* read code                            */
   pixel_t pixel;       /* Return value                         */
   int pixarray[3];     /* Array to hold pixel values           */

   /* Known color names and color values                         */
   typedef struct knownColors {
      const char *name;
      pixel_t value;
   } knownColors_t;

   knownColors_t colors[] = {
         {"white",    {255, 255, 255}},
         {"black",    {0, 0, 0}},
         {"red",      {255, 0, 0}},
         {"green",    {0, 255, 0}},
         {"blue",     {0, 0, 255}},
         {"orange",   {255, 128, 0}},
         {"purple",   {128, 0, 255}},
         {"yellow",   {255, 255, 0}},
         {NULL,       {0, 0, 0}}};      // Marks end of colors array
    
 
   /* First try to read the input as 3 decimal values */
   code = fscanf(infile, "%d %d %d", &pixarray[0], &pixarray[1], &pixarray[2]);
   if (code == 3) {
      for (ndx=0; ndx<3; ndx++) {
          if (pixarray[ndx] > 255 || pixarray[ndx] < 0) {
             fprintf(stderr, "%s\n", errmsg);
             exit(0);
          }
      }
      pixel.r  =  pixarray[0];
      pixel.g  =  pixarray[1];
      pixel.b  =  pixarray[2];
      return(pixel);     /* Success, 3 values read okay */
   }
   if (code != 0) {
      /* There must have been 1 or 2 decimal numbers, but not 3 */
      fprintf(stderr, "%s\n", errmsg);
      exit(1);
   }

   /* Well it's not decimal digits, is the input hex or a known color name? */
   if (fscanf(infile, "%19s", word) != 1) {
      fprintf(stderr, "%s\n", errmsg);
      exit(1);
   }

   /* Should we check for a "well-known" color name, i.e. "word" does not
      start with '#'?
   */
   if (word[0] != '#') {
      /* Search the colors array for the name */
      for (ndx=0; colors[ndx].name != NULL &&
                  strcasecmp(word, colors[ndx].name) != 0 ; ndx++) 
                  /* Just searching */;
      /* Note that ndx is left set to the index of the color in the
         colors array */
      if (colors[ndx].name == NULL) {
         /* Color name not found */
         fprintf(stderr, "%s\n", errmsg);
         exit(1);
      }
      /* Return the equivalent color RGB value */
      return(colors[ndx].value);
   }

   /* Last option: hex string of digits -- convert to internal integer */
   if (strspn(word+1, "0123456789abcdefABCDEF") != strlen(word)-1) {
      /* Error, something other than hex digit embedded or at end in string */
      fprintf(stderr, "%s\n", errmsg);
      exit(1);
   }
   if (sscanf(word+1, "%x", &value) != 1) {
      /* Oops -- bad hex string */
      fprintf(stderr, "%s\n", errmsg);
      exit(1);
   }

   /* Finally partition the value into its three 8-bit RGB components */
   pixel.r  =  value >> 16;
   pixel.g = (value >> 8) & 0xff;
   pixel.b = value & 0xff;
   return(pixel);
}
