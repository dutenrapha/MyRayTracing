#include "../include/header.h"

void	ft_assign_l(t_config *config, char *position, char *brightness, char *cor)
{
    char **temp;
    char **temp2;
    float R;
    float G;
    float B;
    float x;
    float y;
    float z;
    float b;
 
    temp = ft_split(position, ',');
    x = ft_atof(temp[0]);
    y = ft_atof(temp[1]);
    z = ft_atof(temp[2]);
    b = ft_atof(brightness);
    temp2 = ft_split(cor, ',');
    R = (float)ft_atoi(temp2[0]);
    G = (float)ft_atoi(temp2[1]);
    B = (float)ft_atoi(temp2[2]);
    light(&config->l_lights,point_light(point(x, y, z), color((R/255)*b,(G/255)*b,(B/255)*b)));
    ft_split_free(&temp);
    ft_split_free(&temp2);
}