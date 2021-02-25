#include "../include/header.h"

t_matrix rotation(t_tuple normal)
{
	t_matrix A;
    float   angle;
    float   vals[3];
    t_tuple axis;

	
	A = matrix(4);
	
    angle = acos(dot(normal,vector(0, 1, 0)));
    axis = cross(normal,vector(0, 1, 0));
    vals[0] = cos(angle);
    vals[1] = sin(angle);
    vals[2] = 1.0 - vals[0]; 
    
    writeMatrix(&A,0,0,vals[0] + (pow(axis.x, 2) * vals[2]));
    writeMatrix(&A,0,1,(axis.x * axis.y * vals[2]) - (axis.z * vals[1]));
    writeMatrix(&A,0,2,(axis.x * axis.z * vals[2]) + (axis.y * vals[1]));
    writeMatrix(&A,0,3,0.0);

    writeMatrix(&A,1,0,(axis.y * axis.z * vals[2]) + (axis.z * vals[1]));
    writeMatrix(&A,1,1,vals[0] + (pow(axis.y, 2) * vals[2]));
    writeMatrix(&A,1,2,(axis.y * axis.z * vals[2]) - (axis.x * vals[1]));
    writeMatrix(&A,1,3,0.0);

    writeMatrix(&A,2,0,(axis.z * axis.x * vals[2]) - (axis.y * vals[1]));
	writeMatrix(&A,2,1,(axis.z * axis.y * vals[2]) + (axis.x * vals[1]));
    writeMatrix(&A,2,2,vals[0] + (pow(axis.z, 2) * vals[2]));
    writeMatrix(&A,2,3,0.0);

    writeMatrix(&A,3,0,0.0);
    writeMatrix(&A,3,1,0.0);
    writeMatrix(&A,3,2,0.0);
    writeMatrix(&A,3,3,1.0);

	return (A);
}
