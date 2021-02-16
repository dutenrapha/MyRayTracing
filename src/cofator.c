#include "../include/header.h"

float cofactor(t_matrix A, int i, int j)
{
	float resp;
	
	resp = 0;	
	resp = minor_op(A,i,j);
	if ((i + j) % 2 != 0)
	{
		resp = -1 * resp;
	}
	return (resp);
}
