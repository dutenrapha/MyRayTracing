#include "../include/header.h"

t_ray ray(t_tuple origin, t_tuple direction)
{
	t_ray r;

	r.origin = origin;
	r.direction = direction;
	return r;
}
