#include "../include/header.h"

t_comps prepare_computations(t_intersection i, t_ray r)
{
	t_comps comps;

	comps.t = i.t;
	comps.object = i.object;
	comps.point = position(r, comps.t);
	comps.eyev = multi(r.direction,-1);
	comps.normalv = normal_at(comps.object, comps.point);	
	

	if (dot(comps.normalv,comps.eyev) < 0)
	{
		comps.inside = true;
		comps.normalv = multi(comps.normalv,-1);
	}
	else
	{
		comps.inside = false;
	}


	return (comps);
}
