#include "../include/header.h"

void	intersect_2(t_shape *s,t_ray ray)
{
	t_ray local_ray;

	local_ray = transform(ray,inverse(s->transform));
	s->saved_ray = local_ray;
}
