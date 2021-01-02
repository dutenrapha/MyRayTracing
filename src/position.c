#include "../include/header.h"

t_tuple position(t_ray ray,float t)
{
	t_tuple p;
	p = add(ray.origin,multi(ray.direction,t));
	return p;
}
