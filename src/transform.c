#include "../include/header.h"

t_ray   transform(t_ray r,t_matrix m)
{
	t_ray resp;	
	
	resp.origin = matrixMultiVec(m,r.origin);
	resp.direction = matrixMultiVec(m,r.direction);	
	return resp;
}
