#include "../include/header.h"

bool isMatrixEqual(t_matrix A, t_matrix B)
{
        int i;
        int j;

        i = 0;
        j = 0;

        while (i < A.dim)
        {
                while (j < A.dim)
                {
                        if (fabs(A.element[i][j] - B.element[i][j]) > EPSILON)
                        {
                                return (false);
                        }
                        j++;
                }
                i++;
        }
        return (true);
}
