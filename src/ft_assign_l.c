/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_assign_l.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdutenke <rdutenke@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 22:59:10 by rdutenke          #+#    #+#             */
/*   Updated: 2021/04/19 00:15:56 by rdutenke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

void	ft_assign_l(t_config *config, char *ps, char *bb, char *cor)
{
	char		**temp;
	char		**temp2;
	t_color		c;
	t_tuple		p;
	float		b;

	temp = ft_split(ps, ',');
	p.x = ft_atof(temp[0]);
	p.y = ft_atof(temp[1]);
	p.z = ft_atof(temp[2]);
	b = ft_atof(bb);
	temp2 = ft_split(cor, ',');
	c.red = (float)ft_atoi(temp2[0]);
	c.green = (float)ft_atoi(temp2[1]);
	c.blue = (float)ft_atoi(temp2[2]);
	light(&config->l_lights, point_light(point(p.x, p.y, p.z),
	color((c.red / 255) * b, (c.green / 255) * b, (c.blue / 255) * b)));
	ft_split_free(&temp);
	ft_split_free(&temp2);
}
