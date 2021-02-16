#include "../include/header.h"

t_color  color_at2(t_world world, t_ray ray)
{
	t_list  *inter_world;
	t_color c;
	t_intersection in;
	t_comps comps;

	inter_world = intersect_world2(world, ray);
	in = hit2(inter_world);
    if (inter_world != NULL)
    {
        ft_lstclear(&inter_world);
    }
	if (in.valid == false)
	{
		c = color(0,0,0);
		return(c);
	}	
	else
	{
		comps = prepare_computations(in, ray);
		c = shade_hit2(world,comps);			
		return(c);
	}
}
