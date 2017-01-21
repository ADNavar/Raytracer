/* Prototype statements for triple library (structure version)
 *
 * CPSC 210, Spring 2013 
 *
 */

#ifndef TUPLE_H
#define TUPLE_H

#include <stdio.h>

/** Data type definitions **/
typedef struct triple {
   double x;
   double y;
   double z;
} tuple_t;


/** Tuple Library Prototype Statement **/
/* ray
 * Returns a vector pointing from t1 to t2 */
tuple_t ray(tuple_t t1, tuple_t t2);

/* Tuple Length */
double length(tuple_t t1);

/* Scale Tuple
 * Returns a triple containing (t * factor) */
tuple_t scale( tuple_t t, double factor);

/* Unitize triple
 * Returns a triple containing (t / ||t||) */
tuple_t unitize( tuple_t t);

/* Tuple Addition
 * Returns a  triple containing (t1 + t2) */
tuple_t add( tuple_t t1, tuple_t t2);

/* Dot Product 
 * Returns the scalar value of the dot product of two vectors */
double dot(tuple_t t1, tuple_t t2);

/* Tuple print
 * Print a label and the x, y, z values of a triple to an output stream */
void printTuple( FILE *outfile, char *label, tuple_t t);

/* Tuple read
 * Read values from the specified input stream into the triple */
tuple_t readTuple(FILE *infile, char *errmsg);

/* Cross Product 
 * Compute the cross product of two vectors   */
tuple_t cross(tuple_t t1, tuple_t t2);

#endif
