#include "../include/header.h"

t_tuple normalize(t_tuple v1)
{
	float m;
	t_tuple v2;

	m = magnitude(v1);
	
	v2.x = v1.x/m;
        v2.y = v1.y/m;
        v2.z = v1.z/m;
        v2.w = v1.w/m;	
	
	return v2;
}
