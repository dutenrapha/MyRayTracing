#include "../include/header.h"

t_object cylinder(int id)
{
        t_object p;

        p.id = id;
        p.type = "cylinder";
        p.center = point(0,0,0);
        p.transform = identity();
        p.material.color = color(1,1,1);
        p.material.ambient = 0.1;
        p.material.diffuse = 0.9;
        p.material.specular = 0.9;
        p.material.shininess = 200;
        p.minimum = -INFINITY;
        p.maximum = INFINITY;
        p.closed = false;
        return p;
}