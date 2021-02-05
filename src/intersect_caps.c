#include "../include/header.h"

static  bool check_cap(t_ray ray, float t)
{
    bool    r;
    float   x;
    float   z;

    r = false;
    x = ray.origin.x + t * ray.direction.x;
    z = ray.origin.z + t * ray.direction.z;
    if (x*x + z*z -1 <= EPSILON)
    {
        r = true;
    }
    return (r);
}

t_intersection *intersect_caps(t_object cyl, t_ray ray, int *num)
{
    t_intersection i1;
    t_intersection i2;
    t_intersection *xs;
    float           t;
    int             a;
    int             b;

    a = 0;
    b = 0;
    xs = NULL;
    i1.valid = false;
    i2.valid = false;
    if (cyl.closed == false || fabs(ray.direction.y) < EPSILON)
    {
        *num = 0;
        return (xs);
    }
    t = (cyl.minimum - ray.origin.y) / ray.direction.y;
    if (check_cap(ray, t))
    {
        i1 = intersection(t, cyl);
        a = 1;
    }

    t = (cyl.maximum - ray.origin.y) / ray.direction.y;
    if (check_cap(ray, t))
    {
        i2 = intersection(t, cyl);
        b = 1;
    }

    if ((a == 1) && (b == 1))
    {
            xs = intersections(2, i1, i2);
            *num = 2;
    }
    else if (a == 1)
    {
            xs = intersections(1, i1);
            *num = 1;
    }
    else if (b == 1)
    {
            xs = intersections(1, i2);
            *num = 1;
    }
    else
    {
            xs = NULL;
            *num = 0;
    }
    return (xs);
}