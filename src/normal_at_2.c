#include "../include/header.h"

t_tuple normal_at_2(t_shape s, t_tuple p)
{
	t_matrix	A;
	t_tuple		local_point;
	t_tuple		local_normal;
	t_tuple		world_normal;

	A = inverse(s.transform);
	local_point = matrixMultiVec(A,p);
	freeMatrix(&A);
	//local_normal = local_normal_at(s,local_point);
	local_normal = sub(local_point,point(0,0,0));
	A = transpose(inverse(s.transform));
	world_normal = matrixMultiVec(A,local_normal);
	freeMatrix(&A);
	world_normal.w = 0;
	return normalize(world_normal);		
}
