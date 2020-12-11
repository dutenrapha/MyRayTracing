#include "../include/header.h"

t_tuple vector(float x, float y, float z)
{
	t_tuple v;
	v.x = x;
	v.y = y;
	v.z = z;
	v.w = 0;
	return v;
}
