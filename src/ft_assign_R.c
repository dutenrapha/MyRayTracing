#include "../include/header.h"

void	ft_assign_R(t_config *config, char *R_x, char *R_y)
{
    config->R_x = ft_atoi(R_x);
    config->R_y = ft_atoi(R_y);
}