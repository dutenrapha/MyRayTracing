#include "../include/header.h"

void	ft_assign_pl(t_config *config, char *position, char *normal, char *cor,int tag)
{
    t_object o;
    t_matrix C;
    t_matrix A;
    t_matrix D;
    char **temp;
    char **temp2;
    float x;
    float y;
    float z;
    float R;
    float G;
    float B;

    o = plan(tag);
    temp = ft_split(position, ',');
    x = ft_atof(temp[0]);
    y = ft_atof(temp[1]);
    z = ft_atof(temp[2]);
    ft_split_free(&temp);

    temp2 = ft_split(cor, ',');
    R = (float)ft_atoi(temp2[0]);
    G = (float)ft_atoi(temp2[1]);
    B = (float)ft_atoi(temp2[2]);

   	C = translation(x,y,z);

    ft_split_free(&temp2);
	o.material = material();
	o.material.color = color(R/255, G/255, B/255);
	o.material.specular = 0;
    temp2 = ft_split(normal, ',');
    x = ft_atof(temp2[0]);
    y = ft_atof(temp2[1]);
    z = ft_atof(temp2[2]);
    ft_split_free(&temp2);
    A = rotation(vector(x,y,z));
    D = matrixMulti(A,C);
    copy_matrix(&o.transform,D);
    free_matrix(&A);
    free_matrix(&C);
    free_matrix(&D);

    objects(&config->o_objects, o);
}
