#ifndef RAYTRACE_H
#define RAYTRACE_H

#include "ray.h"

/** Prototype statements **/
myvector rayTrace(scene_t *scene, myvector base, myvector unitDir,
                 double total_dist, entity_t *self);
entity_t       *closest(scene_t *scene, myvector base, myvector unitDir, 
                 entity_t *self, hitinfo_t &hit);
myvector  genRay(scene_t *scene, int columnNdx, int rowIndx);

#endif
