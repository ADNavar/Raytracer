/**
  CPSC 2100
  lighting.h
 **/

#ifndef LIGHTING_H
#define LIGHTING_H
#include "ray.h"

/* lighting returns the total lighting on a point hit in the form of a vector */
myvector lighting(scene_t *scene, entity_t *ent, hitinfo_t &hit);

#endif
