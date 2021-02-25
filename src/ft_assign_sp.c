#include "../include/header.h"

void	ft_assign_sp(t_config *config, char *position, char *diameter, char *cor, int tag)
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
    float d;

    o = sphere(tag);
    temp = ft_split(position, ',');
    x = ft_atof(temp[0]);
    y = ft_atof(temp[1]);
    z = ft_atof(temp[2]);
    
    temp2 = ft_split(cor, ',');
    R = (float)ft_atoi(temp2[0]);
    G = (float)ft_atoi(temp2[1]);
    B = (float)ft_atoi(temp2[2]);

    d = ft_atof(diameter)/2;
	A = translation(x,y,z);
	D = scaling(d,d,d);
	C = matrixMulti(A,D);
	copyMatrix(&o.transform,C);
	freeMatrix(&A);
	freeMatrix(&D);
	freeMatrix(&C);


	o.material = material();
	o.material.color = color(R/255, G/255, B/255);
	o.material.specular = 0;

    objects(&config->o_objects, o);
    ft_split_free(&temp);
    ft_split_free(&temp2);
}