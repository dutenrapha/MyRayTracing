#include "../include/header.h"

t_tuple matrixMultiVec(t_matrix A, t_tuple b)
{
	t_tuple Ab;

	Ab.x = A.element[0][0] * b.x + A.element[0][1] * b.y + A.element[0][2] * b.z + A.element[0][3] * b.w;
	Ab.y = A.element[1][0] * b.x + A.element[1][1] * b.y + A.element[1][2] * b.z + A.element[1][3] * b.w;
	Ab.z = A.element[2][0] * b.x + A.element[2][1] * b.y + A.element[2][2] * b.z + A.element[2][3] * b.w;
	Ab.w = A.element[3][0] * b.x + A.element[3][1] * b.y + A.element[3][2] * b.z + A.element[3][3] * b.w;
	return (Ab);
}
