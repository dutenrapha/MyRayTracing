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
    t_list *ii;
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
        xs = ft_lstnew(i1);
        // ii = ft_lstnew(i1);
        // ft_lstadd_back(&xs, ii);
        // ft_lstclear(&ii);
    }
    t = (cyl.maximum - ray.origin.y) / ray.direction.y;
    if (check_cap(ray, t))
    {
        if (ft_lstsize(xs) == 1)
        {
            i1 = intersection(t, cyl);
            ii = ft_lstnew(i1);
            ft_lstadd_back(&xs, ii);
            ft_lstclear(&ii);
        }
        else
        {
            i1 = intersection(t, cyl);
            xs = ft_lstnew(i1);
        }
        
    }
    return (xs);
}