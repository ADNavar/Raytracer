/* CPSC 2100
 *
 * tuple.c
 *
 * Vector and tuple functions
 *
 */

#include <math.h>
#include <stdlib.h>
#include "tuple.h"

/** length **/
/* Computes the length of a 3-D tuple */
double length(tuple_t t1) {
   double sum = 0.0;
   
   sum = t1.x*t1.x + t1.y*t1.y + t1.z*t1.z;
   
   return sqrt(sum);
}


/** scale **/
/* Scales a 3-D tuple by a specified factor. Returns a new tuple */
tuple_t  scale(tuple_t t, double factor) {
   tuple_t result;
   
   result.x = t.x * factor;
   result.y = t.y * factor;
   result.z = t.z * factor;

   return result;
}


/** unitize **/
/* Returns a unit tuple in the same direction as the tuple v.  */
tuple_t unitize(tuple_t v) {
   tuple_t result = {0, 0, 0};
   double len;

   len = length(v);
   if (len != 0) {
      result = scale(v, 1.0/len);
   }
   
   return result;
}


/** dot **/
/* Computes the dot product of two 3-D tuples */
double dot(tuple_t t1, tuple_t t2) {
   double sum;
   
   sum = (t1.x * t2.x) + (t1.y * t2.y) + (t1.z * t2.z);
   
   return sum;
}


/** ray **/
/* Returns a new tuple that points from t1 to t2 */
tuple_t ray(tuple_t t1, tuple_t t2) {
   tuple_t result;

   result.x = t2.x - t1.x;
   result.y = t2.y - t1.y;
   result.z = t2.z - t1.z;
   
   return result;
}


/** add **/
/* Returns a new tuple that has the value of t1 + t2 */
tuple_t add(tuple_t t1, tuple_t t2) {
   tuple_t  result;
   
   result.x = t1.x + t2.x;
   result.y = t1.y + t2.y;
   result.z = t1.z + t2.z;
   
   return result;
}

/** printTuple **/
/* Print a tuple to output stream, with a label */
void printTuple(FILE *outfile, char *label, tuple_t v) {
   fprintf(outfile, "%s %8.4lf %8.4lf %8.4lf\n", label, v.x, v.y, v.z);
}

/** readTuple **/
/* Input values from a designated input stream into a tuple */
tuple_t readTuple(FILE *infile, char *errmsg) {
    tuple_t result;
    if (fscanf(infile, "%lf %lf %lf",
                          &result.x,
                          &result.y,
                          &result.z) != 3) {
       /* Error -- print error message and exit */
       fprintf(stderr, "%s\n", errmsg);
       exit(1);
    }

    /* Success */
    return(result);
}

/** cross **/
/* Compute cross product of two vectors */
tuple_t cross(tuple_t t1, tuple_t t2) {
   tuple_t result;
   result.x = t1.y*t2.z - t1.z*t2.y;
   result.y = t1.z*t2.x - t1.x*t2.z;
   result.z = t1.x*t2.y - t1.y*t2.x;

   return(result);
}
   
