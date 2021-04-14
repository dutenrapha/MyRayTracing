#include "../include/header.h"

static t_list *intersect_sphere(t_object s, t_ray ray)
{
        t_list *xs;
        t_list *ii;
        t_ray ray_t;
        t_intersection i1;
        t_intersection i2;
        t_tuple sphere_to_ray;
        float a;
        float b;
        float c;
        float discriminant;
        t_matrix INV;

        xs = NULL;
        INV = inverse(s.transform);
        ray_t = transform(ray, INV);
        free_matrix(&INV);
        sphere_to_ray = sub(ray_t.origin,s.center);
        a =  dot(ray_t.direction, ray_t.direction);
        b =  2 * dot(ray_t.direction, sphere_to_ray);
        c = dot(sphere_to_ray, sphere_to_ray) - 1;
        discriminant =  b*b - 4 * a * c;
        if (discriminant > 0)
        {
            i1.t = (-b - sqrt(discriminant)) / (2 * a);
            i1.object = s;
            i2.t = (-b + sqrt(discriminant)) / (2 * a);
            i2.object = s;
            xs = ft_lstnew(i1);
            ii = ft_lstnew(i2);
            if (i1.t > 0 || i2.t > 0)
            {
                c  = 1;
            }
            ft_lstadd_back(&xs, ii);
        }
	return (xs);
}

static t_list *intersect_plan(t_object p, t_ray ray)
{
	t_list *xs;
	t_intersection i1;
	float		t;

    xs = NULL;
	if (fabs(ray.direction.y) < EPSILON)
	{
		return (xs);
	}

	t = -ray.origin.y / ray.direction.y;
	i1 = intersection(t, p);
    xs = ft_lstnew(i1);

	return (xs);
}


static t_list *intersect_square(t_object p, t_ray ray)
{
	t_list          *xs;
	t_intersection i1;
	float		    t;
    t_tuple         point;
    float           border;

    xs = NULL;
	if (fabs(ray.direction.y) < EPSILON)
	{
		return (xs);
	}
	t = -ray.origin.y / ray.direction.y;
    if (t > 0)
    {
        point = sub(add(ray.origin,multi(ray.direction, t)),p.center);
        border = p.side * 0.5;

        if ((fabs(point.x) <= border) && (fabs(point.y) <= border) && (fabs(point.z) <= border))
		{
            i1 = intersection(t, p);
            xs = ft_lstnew(i1);
		}
    }
	return (xs);
}


static t_list *intersect_cube(t_object c, t_ray ray)
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
    t_list *xs;
    t_list *ii;
    t_intersection  i1;

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
    xs = NULL;
    if (tmin < tmax)
    {
        i1 = intersection(tmin, c);
        xs = ft_lstnew(i1);
        i1 = intersection(tmax, c);
        ii = ft_lstnew(i1);
        ft_lstadd_back(&xs, ii);
    }
    return (xs);
}

static t_list *intersect_cylinder(t_object cyl, t_ray ray)
{
    float           a;
    float           b;
    float           c;
    float           t0;
    float           t1;
    float           temp;
    float           y0;
    float           y1;
    float           discriminant;
    t_list *xs;
    t_list *ii;
    t_list *xs_cap;
    t_intersection i1;
    int             cc;

    xs = NULL;
    xs_cap = NULL;
    cc = 0;
    a = ray.direction.x*ray.direction.x + ray.direction.z*ray.direction.z;
    if (fabs(a) < EPSILON)
    {
        cc = 1;
        xs_cap = intersect_caps(cyl,ray);
    }
    if (cc == 0)
    {
        b = 2 * ray.origin.x * ray.direction.x + 2 * ray.origin.z * ray.direction.z;
        c = ray.origin.x*ray.origin.x + ray.origin.z*ray.origin.z - 1;
        discriminant = b*b - 4 * a * c;
        if (discriminant < 0)
        {
            xs = NULL;
            if (xs_cap != NULL)
            {
                free(xs_cap);
                ft_lstclear(&xs_cap);
                xs_cap = NULL;
            }
            return (xs);
        }
        t0 =  (-b - sqrt(discriminant)) / (2 * a);
        t1 =  (-b + sqrt(discriminant)) / (2 * a);
        if (t0 > t1)
        {
            temp = t0;
            t1 = t0;
            t0 = temp;
        }
        y0 = ray.origin.y + t0 * ray.direction.y;
        if ((cyl.minimum < y0) && (y0 < cyl.maximum))
        {
            i1 = intersection(t0, cyl);
            xs = ft_lstnew(i1);
        }
        y1 = ray.origin.y + t1 * ray.direction.y;
        if ((cyl.minimum < y1) && (y1 < cyl.maximum))
        {
            if (ft_lstsize(xs) == 1)
            {
                i1 = intersection(t1, cyl);
                ii = ft_lstnew(i1);
                ft_lstadd_back(&xs, ii);
            }
            else
            {
                i1 = intersection(t1, cyl);
                xs = ft_lstnew(i1);
            }
        }
        xs_cap = intersect_caps(cyl,ray);
    }
    if (cc == 1)
    {
        if (xs != NULL)
        {
            ft_lstclear(&xs);
            xs = NULL;
        }
        return (xs_cap);
    }
    else if (ft_lstsize(xs_cap) == 0)
    {
        if (xs_cap != NULL)
        {
            ft_lstclear(&xs_cap);
            xs_cap = NULL;
        }
        return (xs);
    }
    else
    {
        ft_lstadd_back(&xs, xs_cap);
    }
    return(xs);
}

static  t_list *intersect_triangle(t_object triangle, t_ray ray)
{
    t_tuple dir_cross_e2;
    t_tuple p1_to_origin;
    t_tuple origin_cross_e1;
    t_list *xs;
    t_intersection i1;
    float   det;
    float   f;
    float   u;
    float   v;
    float   t;

    xs = NULL;
    dir_cross_e2 = cross(ray.direction, triangle.e2);
    det = dot(triangle.e1, dir_cross_e2);
    if (fabs(det) < EPSILON)
    {
        return(xs);
    }
    f = 1.0 / det;
    p1_to_origin = sub(ray.origin,triangle.p1);
    u = f * dot(p1_to_origin, dir_cross_e2);
    if (u < 0 || u > 1)
    {
        return(xs);
    }
    origin_cross_e1 = cross(p1_to_origin, triangle.e1);
    v = f * dot(ray.direction, origin_cross_e1);
    if (v < 0 || (u + v) > 1)
    {
        return(xs);
    }
    t = f * dot(triangle.e2, origin_cross_e1);
    i1 = intersection(t, triangle);
    xs = ft_lstnew(i1);
    return (xs);
}

t_list *intersect(t_object s, t_ray ray)
{
	t_list *xs;
	t_ray local_ray;
    t_matrix        A;

	xs = NULL;
	if (ft_memcmp("sphere",s.type,7) == 0)
    {
        xs  = intersect_sphere(s,ray);
    }
    else if (ft_memcmp("plan",s.type,5) == 0)
    {
        A = inverse(s.transform);
        local_ray = transform(ray,A);
        free_matrix(&A);
        xs = intersect_plan(s,local_ray);
	}
    else if (ft_memcmp("square",s.type,7) == 0)
    {
        A = inverse(s.transform);
        local_ray = transform(ray,A);
        free_matrix(&A);
        xs = intersect_square(s,local_ray);
	}
    else if (ft_memcmp("cylinder",s.type,9) == 0)
    {
        A = inverse(s.transform);
        local_ray = transform(ray,A);
        free_matrix(&A);
        xs = intersect_cylinder(s,local_ray);
	}
    else if (ft_memcmp("cube",s.type,5) == 0)
    {
        A = inverse(s.transform);
        local_ray = transform(ray,A);
        free_matrix(&A);
        xs  = intersect_cube(s,local_ray);
    }
    else if (ft_memcmp("triangle",s.type,9) == 0)
    {
        A = inverse(s.transform);
        local_ray = transform(ray,A);
        free_matrix(&A);
        xs = intersect_triangle(s,local_ray);
    }
	return (xs);
}
