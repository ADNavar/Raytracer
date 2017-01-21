/** image.h **/
#ifndef IMAGE_H
#define IMAGE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/** pixel_t definition **/
typedef struct pixelType {
   unsigned char r;  // Red value
   unsigned char g;  // Green value
   unsigned char b;  // Blue value
} pixel_t;

/** image_t defintion **/
typedef struct imageType {
   pixel_t *image;   // Pointer to PPM image binary data
   int     columns;  // Number of pixel columns
   int     rows;     // Number of pixel rows
   int     brightness; // Image brightness
} image_t;

/** Prototype statements **/
image_t *getImage(char *inFileName);
image_t *newImage(int columns, int rows, int brightness);
void    outImage(FILE *outfile, image_t *outImage);
image_t *duotone(image_t *inImage, pixel_t tint);

#endif
