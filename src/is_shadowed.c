#include "../include/header.h"

bool is_shadowed(t_world world, t_tuple point)
{
	t_tuple		v;
	float		distance;
	t_tuple		direction;
	t_ray		r;
	t_intersection	*intersections;
	t_intersection	h;
	int		leght;
	int		*p_lenght;

	leght = 0;
	p_lenght = &leght;
	v = sub(world.light.position,point);
	distance = magnitude(v);
	direction = normalize(v);
	r = ray(point, direction);
	intersections = intersect_world(world, r, p_lenght);
	h  = hit(intersections, leght);
	free(intersections);
	if (h.valid == true && h.t < distance)
	{
		return(true);
	}
	else
	{
		return (false);
	}
}
