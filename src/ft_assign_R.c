#include "../include/header.h"

void	ft_assign_R(t_config *config, char *R_x, char *R_y)
{
    int sizex;
    int sizey;
    int x;
    int y;
    void *mlx;

    mlx = mlx_init();
    mlx_get_screen_size(mlx,&sizex,&sizey);
    x = ft_atoi(R_x);
    y = ft_atoi(R_y);
    if (x > sizex)
    {
        config->R_x = sizex;
    }
    else
    {
        config->R_x = x;
    }
    if (y > sizey)
    {
        config->R_y = sizey;
    }
    else
    {
        config->R_y = y;
    }
}