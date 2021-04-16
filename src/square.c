#include "../include/header.h"

t_object square()
{
	t_object p;

	p.id = 4;
	p.type = "square";
	p.center = point(0, 0, 0);
	p.transform = identity();
	p.material.color = color(1, 1 ,1);
	p.material.ambient = 0.1;
	p.material.diffuse = 0.9;
	p.material.specular = 0.9;
	p.material.shininess = 200;
	p.minimum = -INFINITY;
	p.maximum = INFINITY;
	p.closed = false;
	p.p1 = point(0, 0, 0);
	p.p2 = point(0, 0, 0);
	p.p3 = point(0, 0, 0);
	p.e1 = point(0, 0, 0);
	p.e2 = point(0, 0, 0);
	p.normal = point(0, 0, 0);
	return p;
}
