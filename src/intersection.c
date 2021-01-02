#include "../include/header.h"

t_intersection intersection(float t, t_object o)
{
	t_intersection i;
	
	i.t = t;
	i.object = o;
	i.valid = true;
	return i;
}
