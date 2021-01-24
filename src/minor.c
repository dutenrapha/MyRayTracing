#include "../include/header.h"

float minor(t_matrix A, int i, int j)
{
	t_matrix B;
	float d;

	B = submatrix(A,i,j);
	d = det(B);
	freeMatrix(&B);
	return (d);	
}
