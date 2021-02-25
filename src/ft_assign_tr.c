#include "../include/header.h"

void	ft_assign_tr(t_config *config, char *p1, char *p2, char *p3, char *cor)
{
    t_object o;
    char **temp;
    float x1;
    float y1;
    float z1;
    float x2;
    float y2;
    float z2;
    float x3;
    float y3;
    float z3;
    float R;
    float G;
    float B;

    temp = ft_split(p1, ',');
    x1 = ft_atof(temp[0]);
    y1 = ft_atof(temp[1]);
    z1 = ft_atof(temp[2]);
    ft_split_free(&temp);

    temp = ft_split(p2, ',');
    x2 = ft_atof(temp[0]);
    y2 = ft_atof(temp[1]);
    z2 = ft_atof(temp[2]);
    ft_split_free(&temp);
        
    temp = ft_split(p3, ',');
    x3 = ft_atof(temp[0]);
    y3 = ft_atof(temp[1]);
    z3 = ft_atof(temp[2]);
    ft_split_free(&temp);

    o = triangle(5,point(x1,y1,z1),point(x2,y2,z2),point(x3,y3,z3));
    
    temp = ft_split(cor,',');
    R = (float)ft_atoi(temp[0]);
    G = (float)ft_atoi(temp[1]);
    B = (float)ft_atoi(temp[2]);
	o.material = material();
	o.material.color = color(R/255, G/255, B/255);
	o.material.specular = 0;
    objects(&config->o_objects, o);
    ft_split_free(&temp);
}