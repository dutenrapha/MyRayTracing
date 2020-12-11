#include "../include/header.h"

t_tuple cross(t_tuple v1, t_tuple v2)
{
	t_tuple v3;

	v3.x = v1.y*v2.z - v1.z*v2.y;
	v3.y = v1.z*v2.x - v1.x*v2.z;
	v3.z = v1.x*v2.y - v1.y*v2.x;
	v3.w = 0;
	return v3;
}
