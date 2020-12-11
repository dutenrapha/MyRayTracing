#include "../include/header.h"

t_tuple point(float x, float y, float z)
{
	t_tuple v;
	v.x = x;
	v.y = y;
	v.z = z;
	v.w = 1;
	return v;
}
