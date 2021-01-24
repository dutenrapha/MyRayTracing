#include "../include/header.h"

t_color  color_at(t_world world, t_ray ray)
{
	t_intersection  *inter_world;
	t_color c;
	t_intersection in;
	t_comps comps;
	int lenght;
	int *p_lenght;

	lenght = 0;
	p_lenght = &lenght;
	inter_world = intersect_world(world, ray, p_lenght);	
	in = hit(inter_world, lenght);
	free(inter_world);
	if (in.valid == false)
	{
		c = color(0,0,0);
		return(c);
	}	
	else
	{
		comps = prepare_computations(in, ray);
		c = shade_hit(world,comps);			
		return(c);
	}
}
