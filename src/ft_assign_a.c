/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_assign_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdutenke <rdutenke@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 21:40:14 by rdutenke          #+#    #+#             */
/*   Updated: 2021/04/15 21:44:25 by rdutenke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

void	ft_assign_a(t_config *config, char *a_ratio, char *a_color)
{
	char	**temp;
	float	r;
	float	g;
	float	b;
	float	ratio;

	ratio = ft_atof(a_ratio);
	temp = ft_split(a_color, ',');
	r = (float)ft_atoi(temp[0]);
	g = (float)ft_atoi(temp[1]);
	b = (float)ft_atoi(temp[2]);
	config->A_color =
	color((r / 255) * ratio, (g / 255) * ratio, (b / 255) * ratio);
	ft_split_free(&temp);
}
