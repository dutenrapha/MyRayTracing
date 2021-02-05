#include "../include/header.h"

static t_intersection *intersect_sphere(t_object s, t_ray ray, int *num)
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
                *num = 2;
        }
	return (xs);
}

static t_intersection *intersect_plan(t_object p, t_ray ray,int *num)
{
	t_intersection *xs;
	t_intersection i;
	float		t;	

	if (fabs(ray.direction.y) < EPSILON)
	{
		xs = NULL;
                *num = 0;
		return (xs);
	}

	t = -ray.origin.y / ray.direction.y;
	i = intersection(t, p);	
	xs = intersections(1,i);
        *num = 1;
	return (xs);
}

static t_intersection *intersect_cube(t_object c, t_ray ray, int *num)
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
                *num = 0;
        }
        else
        {
                xs = intersections(2,intersection(tmin, c), intersection(tmax, c));
                *num = 1;              
        }
        return (xs);
}

static t_intersection *intersect_cylinder(t_object cyl, t_ray ray, int *num)
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
        t_intersection *xs;
        t_intersection *xs_cap;
        t_intersection *xs_ret;
        t_intersection i1;
        t_intersection i2;
        int             aa;
        int             bb;
        int             cc;
        int             n_cap;
        int             *p_n_cap;
        int             i;
        int             j;

        i = 0;
        j = 0;
        xs_ret = NULL;
        xs = NULL;
        xs_cap = NULL;
        n_cap = 0;
        p_n_cap = &n_cap;
        aa = 0;
        bb = 0;
        cc = 0;
        a = ray.direction.x*ray.direction.x + ray.direction.z*ray.direction.z;
        if (fabs(a) < EPSILON)
        {
                cc = 1;
                xs_cap = intersect_caps(cyl,ray,p_n_cap);
        }

        if (cc == 0)
        {
                b = 2 * ray.origin.x * ray.direction.x + 2 * ray.origin.z * ray.direction.z;
                c = ray.origin.x*ray.origin.x + ray.origin.z*ray.origin.z - 1;
                discriminant = b*b - 4 * a * c;
                if (discriminant < 0)
                {
                        xs = NULL;
                        *num = 0;
                        if (xs_ret != NULL)
                        {
                                free(xs_ret);
                                xs_ret = NULL;
                        }
                        if (xs_cap != NULL)
                        {
                                free(xs_cap);
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
                        aa = 1;
                }

                y1 = ray.origin.y + t1 * ray.direction.y;
                if ((cyl.minimum < y1) && (y1 < cyl.maximum))
                {
                        i2 = intersection(t1, cyl);
                        bb = 1;
                }

                if ((aa == 1) && (bb == 1))
                {
                        xs = intersections(2, i1, i2);
                        *num = 2;
                }
                else if (aa == 1)
                {
                        xs = intersections(1, i1);
                        *num = 1;
                }
                else if (bb == 1)
                {
                        xs = intersections(1, i2);
                        *num = 1;
                }
                else
                {
                        xs = NULL;
                        *num = 0;
                }
                xs_cap = intersect_caps(cyl,ray,p_n_cap);
        }

        if (cc == 1)
        {
                *num = n_cap;
                if (xs_ret != NULL)
                {
                        free(xs_ret);
                        xs_ret = NULL;
                }
                if (xs != NULL)
                {
                        free(xs);
                        xs = NULL;
                }
                return (xs_cap);
        }
        else if (n_cap == 0)
        {
                if (xs_ret != NULL)
                {
                        free(xs_ret);
                        xs_ret = NULL;
                }
                if (xs_cap != NULL)
                {
                        free(xs_cap);
                        xs_cap = NULL;
                }
                return (xs);  
        }
        else
        {
                xs_ret = (t_intersection *)malloc(sizeof(t_intersection)*(*num + n_cap));
                while (i < *num)
                {
                        xs_ret[i] = xs[i];
                        i++;
                }
                while (j < n_cap)
                {
                        xs_ret[i] = xs_cap[j];
                        i++;
                        j++;
                }
                *num = n_cap + *num;
        }
        if (xs != NULL)
        {
                free(xs);
                xs = NULL;
        }
        if (xs_cap != NULL)
        {
                free(xs_cap);
                xs_cap = NULL;
        }

        return(xs_ret);
}

t_intersection *intersect(t_object s, t_ray ray, int *num)
{
	t_intersection *xs;
	t_ray local_ray;
        t_matrix        A;

	
	if (ft_memcmp("sphere",s.type) == 0)
        {
		xs  = intersect_sphere(s,ray, num);
        }
        else if (ft_memcmp("plan",s.type) == 0)
        {
		xs = intersect_plan(s,ray, num);
	}
        else if (ft_memcmp("cylinder",s.type) == 0)
        {
                A = inverse(s.transform);
                local_ray = transform(ray,A);
                freeMatrix(&A);
		xs = intersect_cylinder(s,local_ray,num);
	}
        else if (ft_memcmp("cube",s.type) == 0)
        {
                A = inverse(s.transform);
                local_ray = transform(ray,A);
                freeMatrix(&A);
                xs  = intersect_cube(s,local_ray,num);
        }
        else
        {
		xs = NULL;
                *num = 0;
        }

	return (xs);
}
