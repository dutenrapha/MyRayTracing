#include "../include/header.h"

t_world default_world()
{
	t_world w;
	t_object s1;
	t_object s2;
	
	w.has_light = true;
	w.light =  point_light(point(-10,10,-10),color(1,1,1));	
	s1 = sphere(1);	
	s1.material.color = color(0.8, 1.0, 0.6);
	s1.material.diffuse = 0.7;
	s1.material.specular = 0.2;
	s2 = sphere(2);
	s2.transform = scaling(0.5,0.5,0.5);
	w.num_objects = 2;	
	w.objects = (t_object *)malloc(sizeof(t_object)*w.num_objects);
	w.objects[0] = s1;
	w.objects[1] = s2;
	return (w);	
}
