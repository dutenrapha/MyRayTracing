#include "../include/header.h"

t_matrix matrixMulti(t_matrix A, t_matrix B)
{
	t_matrix AB;
	int i;
	int j;
	
	AB.dim = 4;
	AB = matrix(4);
	i = 0;
	while (i < A.dim)
	{
		   j = 0;
		while (j < A.dim)
		{
			AB.element[i][j] = A.element[i][0]*B.element[0][j] + A.element[i][1]*B.element[1][j] + A.element[i][2]*B.element[2][j] + A.element[i][3]*B.element[3][j] ; 
			j++;
		}
		i++;
	}
	return (AB);
}
