#include "../include/header.h"

t_matrix view_transform(t_tuple from,t_tuple to,t_tuple up)
{
	t_tuple	forward;
	t_tuple	upn;
	t_tuple left;
	t_tuple true_up;
	t_matrix orientation;
	t_matrix t;
	t_matrix resp;

	forward = normalize(sub(to,from));
	upn = normalize(up);
	left = cross(forward,upn);
 	true_up = cross(left,forward);

	orientation = matrix(4);	
	writeMatrix(&orientation,0,0,left.x);
	writeMatrix(&orientation,0,1,left.y);
	writeMatrix(&orientation,0,2,left.z);
	writeMatrix(&orientation,0,3,0.0);

	writeMatrix(&orientation,1,0,true_up.x);
	writeMatrix(&orientation,1,1,true_up.y);
	writeMatrix(&orientation,1,2,true_up.z);
	writeMatrix(&orientation,1,3,0.0);

	writeMatrix(&orientation,2,0,-forward.x);
	writeMatrix(&orientation,2,1,-forward.y);
	writeMatrix(&orientation,2,2,-forward.z);
	writeMatrix(&orientation,2,3,0.0);

	writeMatrix(&orientation,3,0,0.0);
	writeMatrix(&orientation,3,1,0.0);
	writeMatrix(&orientation,3,2,0.0);
	writeMatrix(&orientation,3,3,1.0);
	
	t = translation(-from.x, -from.y, -from.z);
	resp = matrixMulti(orientation,t);
	freeMatrix(&orientation);
	freeMatrix(&t);
	return (resp);
}
