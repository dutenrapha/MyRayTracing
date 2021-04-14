#include "../include/header.h"

float minor_op(t_matrix A, int i, int j)
{
	t_matrix B;
	float d;

	B = submatrix(A,i,j);
	d = det(B);
	free_matrix(&B);
	return (d);
}
