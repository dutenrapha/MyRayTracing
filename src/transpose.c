#include "../include/header.h"

t_matrix transpose(t_matrix A)
{
	t_matrix AT;
        int i;
        int j;
	
	AT = matrix(4);
        i = 0;
        while (i < A.dim)
        {
                j = 0;
                while (j < A.dim)
                {
			AT.element[j][i] = A.element[i][j];	
                        j++;
                }
                i++;
        }		
	return (AT);
}
