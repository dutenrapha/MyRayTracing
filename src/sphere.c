#include "../include/header.h"

t_object sphere(int id)
{
	t_object s;
	
	s.id = id;
	s.type = "sphere";
	s.center = point(0,0,0);
	s.transform = identity();
	s.material.color = color(1,1,1);
	s.material.ambient = 0.1;
	s.material.diffuse = 0.9;
	s.material.specular = 0.9;
	s.material.shininess = 200;
	return s;
}
