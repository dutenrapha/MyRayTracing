#include "../include/header.h"

t_matrix submatrix(t_matrix A, int i, int j)
{
	t_matrix B;
	int l;
	int m;	
	int ii;
	int jj;	

	B = matrix(A.dim - 1);
	l = 0;
	ii = 0;
	while (l < A.dim)
        {
		m = 0;
		jj = 0;
		while (m < A.dim)
		{
			if ((l != i) && (m != j))
			{
				B.element[ii][jj] = A.element[l][m];
				jj++;
			}
			m++;
		}
	        if ((l != i) && (m != j))
			ii++;
		l++;
	}		
	return (B);
}
