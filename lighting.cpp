

#include "lighting.h"

myvector lighting(scene_t *scene, entity_t *ent, hitinfo_t &hit) 
{
	myvector total_illumination;
  	iterator_t *light_iter = newIterator(scene->lightList);

	/* gather light from all sources */
	while(l_hasnext(light_iter)) {
	      	/* set pointer to current light 
		   and advance the light_iterator*/
	        pointlight_t *light_ptr = static_cast<pointlight_t*>
		  (l_next(light_iter));
		
		/* process light */
		myvector new_light = light_ptr->processLight(scene, ent, hit);

		/* add to current illumination */
		total_illumination = total_illumination + new_light;
	}

    return total_illumination;
}

