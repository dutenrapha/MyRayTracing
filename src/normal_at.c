#include "../include/header.h"


t_tuple normal_at(t_object o,t_tuple v)
{
	t_tuple	object_point;
	t_tuple	object_normal;
	t_tuple	world_normal;
	t_matrix m1;
	t_matrix m2;

	if (o.id == 2)
		world_normal.w = 0;

	m1 = inverse(o.transform);
	object_point  = matrixMultiVec(m1,v);
	object_normal = local_normal_at(o,object_point);
	m2 = transpose(m1);
	world_normal = matrixMultiVec(m2,object_normal);
	world_normal.w = 0;
	free_matrix(&m1);
	free_matrix(&m2);
	return (normalize(world_normal));
}
