#include "../include/header.h"

void copyMatrix(t_matrix *d, t_matrix o)
{
	int i;
    int j;
    
    i = 0;
    while (i < o.dim)
    {
        j = 0;
        while (j < o.dim)
        {
            writeMatrix(d,i,j,o.element[i][j]);
            j++;
        } 
        i++;
    } 
}
