#include "../include/header.h"

static t_intersection *intersect_sphere(t_object s, t_ray ray)
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

        INV = inverse(s.transform);
        ray_t = transform(ray, INV);
        freeMatrix(&INV);
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

static t_intersection *intersect_plan(t_object p, t_ray ray)
{
	t_intersection *xs;
	t_intersection i;
	float		t;	

	if (fabs(ray.direction.y) < EPSILON)
	{
		xs = NULL;
		return (xs);
	}

	t = -ray.origin.y / ray.direction.y;
	i = intersection(t, p);	
	xs = intersections(1,i);
	return (xs);
}

static t_intersection *intersect_cube(t_object c, t_ray ray)
{
        float   xtmin;
	float   xtmax;
	float   ytmin;
	float   ytmax; 
	float   ztmin;
	float   ztmax;
	float	*p_xtmin;
        float   *p_xtmax;
	float   *p_ytmin;
	float   *p_ytmax; 
	float   *p_ztmin;
	float   *p_ztmax;
        float   tmin;
        float   tmax; 
        t_intersection *xs;          

        p_xtmin =&xtmin;
        p_xtmax =&xtmax;
	p_ytmin =&ytmin;
	p_ytmax =&ytmax; 
	p_ztmin =&ztmin;
	p_ztmax =&ztmax;

        check_axis(ray.origin.x, ray.direction.x, p_xtmin, p_xtmax);
        check_axis(ray.origin.y, ray.direction.y, p_ytmin,  p_ytmax);
        check_axis(ray.origin.z, ray.direction.z,  p_ztmin, p_ztmax);
        tmin = fmax(xtmin, ytmin);
        tmin = fmax(tmin, ztmin);
        tmax = fmin(xtmax, ytmax);
        tmax = fmin(tmax, ztmax);

        if (tmin > tmax)
        {
                xs = NULL;
        }
        else
        {
                xs = intersections(2,intersection(tmin, c), intersection(tmax, c));                
        }
        return (xs);
}

t_intersection *intersect(t_object s, t_ray ray)
{
	t_intersection *xs;
	t_ray local_ray;

	
	if (ft_memcmp("sphere",s.type) == 0)
        {
		xs  = intersect_sphere(s,ray);
        }
        else if (ft_memcmp("plan",s.type) == 0)
        {
		xs = intersect_plan(s,ray);
	}
        else if (ft_memcmp("cube",s.type) == 0)
        {
                local_ray = transform(ray,inverse(s.transform));
                xs  = intersect_cube(s,local_ray);
        }
        else
        {
		xs = NULL;
        }

	return (xs);
}
