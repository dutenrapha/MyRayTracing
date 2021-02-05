#include "../include/header.h"

t_object	triangle(int id, t_tuple p1,t_tuple p2,t_tuple p3)
{
        t_object p;

        p.id = id;
        p.type = "triangle";
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
        p.p1 = p1;
        p.p2 = p2;
        p.p3 = p3;
        p.e1 = sub(p2,p1);
        p.e2 = sub(p3,p1);
        p.normal = normalize(cross(p.e2,p.e1));
        return p;
}