#include "../include/header.h"

t_intersection *intersect(t_object s, t_ray ray)
{
	t_intersection *xs;
	t_ray ray_t;
	t_intersection i1;
	t_intersection i2;
	t_tuple sphere_to_ray;
	float a;
	float b;
	float c;
	float discriminant;
	t_matrix INV;

	INV = matrix(4);
	INV = inverse(s.transform);
	ray_t = transform(ray, INV);
	freeMatrix(INV);
	sphere_to_ray = sub(ray_t.origin,s.center);
	a =  dot(ray_t.direction, ray_t.direction);
	b =  2 * dot(ray_t.direction, sphere_to_ray);
	c = dot(sphere_to_ray, sphere_to_ray) - 1;
	discriminant =  b*b - 4 * a * c;

	if (discriminant < 0)
	{	
		xs = NULL;
	}
	else
	{
		i1.t = (-b - sqrt(discriminant)) / (2 * a);
		i1.object = s;
		i2.t = (-b + sqrt(discriminant)) / (2 * a);	
		i2.object = s;
		xs = intersections(2,i1,i2);
	}
	return (xs);
}
