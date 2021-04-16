/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_assign_r.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdutenke <rdutenke@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 23:58:06 by rdutenke          #+#    #+#             */
/*   Updated: 2021/04/16 00:01:24 by rdutenke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

void	ft_assign_r(t_config *config, char *r_x, char *r_y)
{
	int		sizex;
	int		sizey;
	int		x;
	int		y;
	void	*mlx;

	mlx = mlx_init();
	mlx_get_screen_size(mlx, &sizex, &sizey);
	x = ft_atoi(r_x);
	y = ft_atoi(r_y);
	if (x > sizex)
		config->R_x = sizex;
	else
		config->R_x = x;
	if (y > sizey)
		config->R_y = sizey;
	else
		config->R_y = y;
}
