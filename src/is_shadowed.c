#include "../include/header.h"

bool is_shadowed(t_light light, t_world world, t_tuple point)
{
	t_tuple		v;
	float		distance;
	t_tuple		direction;
	t_ray		r;
	t_list	*intersections;
	t_intersection	h;

	v = sub(light.position,point);
	distance = magnitude(v);
	direction = normalize(v);
	r = ray(point, direction);
	intersections = intersect_world(world, r);
	h  = hit(intersections);
	if (intersections != NULL)
	{
		ft_lstclear(&intersections);
	}
	if (h.valid == true && h.t < distance)
	{
		return(true);
	}
	else
	{
		return (false);
	}
}
