#include "../include/header.h"

float magnitude(t_tuple v1)
{
	return  sqrt(v1.x*v1.x + v1.y*v1.y + v1.z*v1.z + v1.w*v1.w);
}
