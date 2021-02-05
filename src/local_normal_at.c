#include "../include/header.h"

static t_tuple cub_norm(t_tuple point)
{
	float	maxc;
	
	maxc = fmax(fabs(point.x), fabs(point.y));
	maxc = fmax(maxc, fabs(point.z));

	if (maxc == fabs(point.x))
	{
		return vector(point.x, 0, 0);
	}
	else if (maxc == fabs(point.y))
	{
		return vector(0, point.y, 0);
	}
	else
	{
		return vector(0, 0, point.z);
	}
}

static t_tuple cyl_norm(t_object cyl, t_tuple point)
{
	float	dist;

	dist =  point.x*point.x + point.z*point.z;
	
	if (dist < 1 && point.y >= cyl.maximum - EPSILON)
	{
		return vector(0, 1, 0);
	}
	else if (dist < 1 && point.y <= cyl.minimum + EPSILON)
	{
		return vector(0, -1, 0);
	}
	else
	{
		 return vector(point.x, 0, point.z);
	}
}

t_tuple local_normal_at(t_object o,t_tuple local_point)
{
	t_tuple		local_normal;

	if (ft_memcmp(o.type,"sphere") == 0)
	{
		local_normal = sub(local_point,point(0,0,0));
	}
	else if (ft_memcmp(o.type,"plan") == 0)
	{
		local_normal = vector(0,1,0);
	}
	else if (ft_memcmp(o.type,"cube") == 0)
	{
		local_normal = cub_norm(local_point);
	}
	else if (ft_memcmp(o.type,"cylinder") == 0)
	{
		local_normal = cyl_norm(o,local_point);
	}
	else if (ft_memcmp(o.type,"triangle") == 0)
	{
		local_normal = o.normal;
	}
	else
	{
		local_normal = vector(0,0,0);
	}
	return (local_normal);	
}
