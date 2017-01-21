
#include "image.h"
/** newImage 

    Create and initialize a new image_t.

    Prototype:
       image_t *newImage(int columns, int rows, int brightness);
 
    where
       columns: number of pixel columns in new PPM image
       rows:    number of pixel rows in new PPM image
       brightness:  pixel brightness (0-255)

    Return value:
       Pointer to newly allocated and initialized image_t
**/

image_t *newImage(int columns, int rows, int brightness) {
   image_t *newImage;

   /* Allocate a new image_t */
   newImage = (image_t *)malloc(sizeof(image_t));
   
   /* Initialize image_t, and allocate space for image */
   newImage->rows       = rows;
   newImage->columns    = columns;
   newImage->brightness = brightness;
   newImage->image      = 
       (pixel_t *)malloc(newImage->columns * newImage->rows * sizeof(pixel_t));

   return(newImage);
}


/** outImag

    Output a PPM image to a specified file. 

    Prototype:
       void outImage(ofstream &outfile, image_t *tintedImage);

    where
       outfile:    pointer to the output file to create,
       tintedImage: pointer to the image_t of the image to write.

**/
#include "image.h"

/** outImage **/
void outImage(FILE *outfile, image_t *tintedImage) 
{

   /* Now write the image to the file */
   fprintf(outfile, "P6 %d %d %d\n",
    tintedImage->columns, tintedImage->rows, tintedImage->brightness);
   fwrite(tintedImage->image, sizeof(pixel_t),
            tintedImage->columns * tintedImage->rows, outfile);
}


/** getimage.c **/
#include "image.h"
int getPPMInt(FILE *fp, int *result);   // Protype statement

/** getImage()
       Retrieve a PPM image from a file and return it via a pointer
       to a newly created image_t
 
    Prototype:
 
       image_t *getImage(char *inFileName) {
       
       where
          inFileName: the name of the input image PPM file
 
       Return value:
          Pointer to a newly created image_t containing the input
          image.
**/
image_t *getImage(char *inFileName) {
   char header[3];
   char buf[256];
   FILE *inFile;
   image_t *inImage;
   int   rows;
   int   cols;
   int   brightness;

   if ((inFile = fopen(inFileName, "r")) == NULL ) {
      fprintf(stderr, "Cannot open file \"%s\"\n", inFileName);
      exit(1);
   }

   /* Allocate space for the image structure */
   inImage = (image_t *)malloc(sizeof(image_t));

   /* Process the PPM header */
   if (fscanf(inFile, "%2s", header) != 1) {
      fprintf(stderr,"Premature end to PPM header\n");
      exit(1);
   }
   if (strcmp(header, "P6") != 0) {
      fprintf(stderr, "PPM file does not start with \"P6\"\n");
      exit(1);
   }
   if (getPPMInt(inFile, &cols) <= 0) {
      fprintf(stderr,"Error in PPM header -- columns\n");
      exit(1);
   }
   if (getPPMInt(inFile, &rows) <= 0) {
      fprintf(stderr,"Error in PPM header -- rows\n");
      exit(1);
   }
   if (getPPMInt(inFile, &brightness) <= 0) {
      fprintf(stderr,"Error in PPM header -- brightness\n");
      exit(1);
   }
   if (fgets(buf, sizeof(buf), inFile) == NULL) {
      fprintf(stderr,"Error in PPM header -- after brightness\n");
      exit(1);
   }

   /* Compute the size of the input image, and allocate space for it */
   inImage = newImage(cols, rows, brightness);
 
   /* And read the image */
   if (fread(inImage->image, sizeof(pixel_t), cols*rows, inFile) != 
         cols*rows) {
      fprintf(stderr, "Error: input file truncated\n");
      exit(1);
   }

   fclose(inFile);

   return(inImage);
}

/** getPPMInt 

    Read an individual integer field from a PPM header.
    Skips over PPM comments (which start with a '#')

    Prototype:
       int getPPMInt(FILE *fp, int *result);

  
    where 
       fp: open input stream,
       result: integer value read

    Return values:
       1: success
       -1: end of file
       0: error in input.

**/
int getPPMInt(FILE *fp, int *result) {
    char buf[100];
    int  code;

    while ((code=fscanf(fp, "%d", result)) != 1) {
       if (fgets(buf, sizeof(buf), fp) == NULL) {
          return(-1);
       }
       if (buf[0] != '#') {
          fprintf(stderr, "getPPMInt[%d]: Error in input: \"%s\"\n", code, buf);
          return(0);
       }
    }
    return(1);
}
