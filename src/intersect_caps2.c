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

t_list *intersect_caps2(t_object cyl, t_ray ray)
{
    t_intersection i1;
    t_list *xs;
    t_list *i;
    float           t;

    xs = NULL;
    i1.valid = false;
    if (cyl.closed == false || fabs(ray.direction.y) < EPSILON)
    {
        return (xs);
    }
    t = (cyl.minimum - ray.origin.y) / ray.direction.y;
    if (check_cap(ray, t))
    {
        i1 = intersection(t, cyl);
        i = ft_lstnew(i1);
        ft_lstadd_back(&xs, i);
        ft_lstclear(&i);
    }
    t = (cyl.maximum - ray.origin.y) / ray.direction.y;
    if (check_cap(ray, t))
    {
        i1 = intersection(t, cyl);
        i = ft_lstnew(i1);
        ft_lstadd_back(&xs, i);
        ft_lstclear(&i);
    }
    return (xs);
}