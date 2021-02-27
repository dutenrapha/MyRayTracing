#include "../include/header.h"

void	ft_assign_c(t_config *config, char *position, char *normal, char *FOV)
{
    t_camera c;
    t_matrix C;
    char **temp;
    char **temp2;
    float x1;
    float y1;
    float z1;
    float x2;
    float y2;
    float z2;
    float degree;

    degree = ft_atof(FOV);
    c =  camera(config->R_x,config->R_y,degree * ( M_PI / 180.0 ));
    temp = ft_split(position, ',');
    x1 = ft_atof(temp[0]);
    y1 = ft_atof(temp[1]);
    z1 = ft_atof(temp[2]);
    temp2 = ft_split(normal, ',');
    x2 = ft_atof(temp2[0]);
    y2 = ft_atof(temp2[1]);
    z2 = ft_atof(temp2[2]);
    C = view_transform(point(x1,y1,z1),point(x2,y2,z2),vector(0,1,0));
	copyMatrix(&c.transform,C);
    cameras(&config->c_cameras,c);
	freeMatrix(&C);
    ft_split_free(&temp);
    ft_split_free(&temp2);
}