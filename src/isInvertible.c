#include "../include/header.h"

bool isInvertible(t_matrix A)
{
	if (det(A) == 0)
		return (false);
	else
		return (true);	
}
