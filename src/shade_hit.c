#include "../include/header.h"

t_color shade_hit(t_world world,t_comps comps)
{
	t_color c1;
	t_color c2;
	t_lights *temp;
	bool	shadowed;

	c1 = color(0,0,0);
	c2 = color(0,0,0);
	temp = world.lights;
	while (temp->next)
	{
		shadowed = is_shadowed(temp->content, world, comps.over_point);
		c1 = lighting(comps.object.material,temp->content,comps.over_point,comps.eyev,comps.normalv, shadowed);	
		c2 = addcolor(c1,c2);
		temp = temp->next;
	}
	shadowed = is_shadowed(temp->content, world, comps.over_point);
	c1 = lighting(comps.object.material,temp->content,comps.over_point,comps.eyev,comps.normalv, shadowed);	
	c2 = addcolor(c1,c2);
	return (c2);	
}
