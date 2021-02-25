#include "../include/header.h"

t_matrix inverse(t_matrix A)
{
	t_matrix B;
	int i;
	int j;
	float c;
	float d;
	
	d = det(A);
	c = 0;
	B = matrix(A.dim);
	if (!isInvertible(A))
	{
		ft_printf("Not invertible matrix");
		return (B);
	}
	else
	{
		i = 0;
		while (i < A.dim)
		{
			j = 0;
			while (j < A.dim)
			{
				c = cofactor(A,i,j);
				B.element[j][i] = c/d; 
				j++;
			}
			i++;
		}
		return (B);	
	}
}
