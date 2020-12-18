#include "../include/header.h"

void freeMatrix(t_matrix A)
{
	int i;

	i = 0;
	while (i < A.dim)
	{
		free(A.element[i]);
		i++;
        }	
	free(A.element);
}
