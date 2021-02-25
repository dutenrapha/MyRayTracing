#include "../include/header.h"

void	ft_assign_A(t_config *config, char *A_ratio, char *A_color)
{
    char **temp;
    float R;
    float G;
    float B;
    float ratio;

    ratio = ft_atof(A_ratio);
    temp = ft_split(A_color,',');
    R = (float)ft_atoi(temp[0]);
    G = (float)ft_atoi(temp[1]);
    B = (float)ft_atoi(temp[2]);
    config->A_color = color((R/255)*ratio,(G/255)*ratio,(B/255)*ratio);
    ft_split_free(&temp);
}