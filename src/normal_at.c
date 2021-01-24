#include "../include/header.h"

t_tuple normal_at(t_object o,t_tuple v)
{
	t_tuple	object_point;
	t_tuple	object_normal;
	t_tuple	world_normal;
	t_matrix m1;
	t_matrix m2;
	
	m1 = inverse(o.transform);
	object_point  = matrixMultiVec(m1,v);
	object_normal = sub(object_point,point(0,0,0));
	m2 = transpose(m1);
	world_normal = matrixMultiVec(m2,object_normal);
	world_normal.w = 0;
	freeMatrix(&m1);
	freeMatrix(&m2);
	return (normalize(world_normal));	
}
