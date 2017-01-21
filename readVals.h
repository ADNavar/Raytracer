#ifndef READVALS_H
#define READVALS_H

#include <stdio.h>
#include <string.h>

/** prototype statements **/
int     readInt(FILE *fp, char *errmsg);
pixel_t readColor(FILE *fp, char *errmsg);
double  readDouble(FILE *fp, char *errmsg);
char    *readString(FILE *fp, char *errmsg);

#endif
