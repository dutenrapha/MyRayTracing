#include "../include/header.h"

t_material material()
{
	t_material m;

	m.color = color(1,1,1);
	m.ambient = 0.1;
	m.diffuse = 0.9;
	m.specular = 0.9;
	m.shininess = 200.0;	
	return (m);
}
