#include "../include/header.h"

t_matrix matrix(int dim)
{
	t_matrix m;
	int i;

	m.dim = dim;	
	m.element = (float **)malloc(sizeof(float*)*dim);
	i = 0;
	while (i < dim)
	{
		m.element[i] = (float *)malloc(sizeof(float)*dim);
		i++;
	}	
	return (m);
}	
