#include "../include/header.h"

t_object sphere(int id)
{
	t_object s;
	
	s.id = id;
	s.type = "sphere";
	s.center = point(0,0,0);
	s.transform = identity();
	return s;
}
