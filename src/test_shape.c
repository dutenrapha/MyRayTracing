#include "../include/header.h"

t_shape test_shape()
{
	t_shape	s;

	s.transform = identity();
	s.material = material();
	s.saved_ray = ray(point(0,0,0),vector(0,0,0));
	return (s);	
}
