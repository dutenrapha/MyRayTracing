#include "../include/header.h"

void	ft_assign_cy(t_config *config, char *position, char *normal, char *diameter, char *height, char *cor, int tag)
{
    t_object o;
    t_matrix A;
    t_matrix D;
    t_matrix C;
    char **temp;
    char **temp2;
    float x;
    float y;
    float z;
    float R;
    float G;
    float B;
    float s;

    o = cylinder(tag);
    temp = ft_split(position, ',');
    x = ft_atof(temp[0]);
    y = ft_atof(temp[1]);
    z = ft_atof(temp[2]);

    s = ft_atof(diameter)/2;
	A = translation(x,y,z);
	D = scaling(s,1,s);
	C = matrixMulti(A,D);
	freeMatrix(&A);
	freeMatrix(&D);


    temp2 = ft_split(cor,',');
    R = (float)ft_atoi(temp2[0]);
    G = (float)ft_atoi(temp2[1]);
    B = (float)ft_atoi(temp2[2]);
	o.material = material();
	o.material.color = color(R/255, G/255, B/255);
	o.material.specular = 0;

    ft_split_free(&temp);
    temp = ft_split(normal, ',');
    x = ft_atof(temp[0]);
    y = ft_atof(temp[1]);
    z = ft_atof(temp[2]);

    A = rotation(vector(x,y,z));
	D = matrixMulti(A,C);
    copyMatrix(&o.transform,D);
    freeMatrix(&A);
    freeMatrix(&C);
    freeMatrix(&D);

    o.normal = vector(x,y,z);


    o.minimum = 0;
    s = ft_atof(height);
    o.maximum = s;
    o.closed = true;
    objects(&config->o_objects, o);
    ft_split_free(&temp);
    ft_split_free(&temp2);   
}