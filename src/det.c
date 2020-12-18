#include "../include/header.h"

float det(t_matrix A)
{
	float resp;
	int i;

	resp = 0;
	if (A.dim == 2)
	{
		 resp = A.element[0][0]*A.element[1][1] - A.element[0][1]*A.element[1][0];
	}	
	else
	{
		i  = 0;
		while (i < A.dim)
		{
			resp = resp + A.element[0][i]*cofactor(A,0,i);
			i++;
		}
	}
	return (resp);
}
