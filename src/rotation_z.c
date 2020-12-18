#include "../include/header.h"

t_matrix rotation_z(float r)
{
	t_matrix A;
	
	A = matrix(4);
	writeMatrix(&A,0,0,cos(r));
        writeMatrix(&A,0,1,-sin(r));
        writeMatrix(&A,0,2,0.0);
        writeMatrix(&A,0,3,0.0);

        writeMatrix(&A,1,0,sin(r));
        writeMatrix(&A,1,1,cos(r));
        writeMatrix(&A,1,2,0.0);
        writeMatrix(&A,1,3,0.0);

        writeMatrix(&A,2,0,0.0);
	writeMatrix(&A,2,1,0.0);
        writeMatrix(&A,2,2,1.0);
        writeMatrix(&A,2,3,0.0);

        writeMatrix(&A,3,0,0.0);
        writeMatrix(&A,3,1,0.0);
        writeMatrix(&A,3,2,0.0);
        writeMatrix(&A,3,3,1.0);

	return (A);
}
