#include "../include/header.h"

t_color shade_hit(t_world world,t_comps comps)
{
	t_color c;

	c = lighting(comps.object.material,world.light,comps.point,comps.eyev,comps.normalv);	
	return (c);	
}
