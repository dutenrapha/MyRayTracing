#include "../include/header.h"

t_color shade_hit2(t_world world,t_comps comps)
{
	t_color c;
	bool	shadowed;
	shadowed = is_shadowed2(world, comps.over_point);

	c = lighting(comps.object.material,world.light,comps.over_point,comps.eyev,comps.normalv, shadowed);	
	return (c);	
}
