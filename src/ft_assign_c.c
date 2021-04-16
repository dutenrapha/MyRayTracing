/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_assign_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdutenke <rdutenke@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 21:55:27 by rdutenke          #+#    #+#             */
/*   Updated: 2021/04/15 21:55:59 by rdutenke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

void	ft_assign_c(t_config *config, char *position, char *normal, char *fov)
{
	t_camera	c;
	t_matrix	cc;
	char		**temp;
	t_tuple		p1;
	t_tuple		p2;

	c = camera(config->R_x, config->R_y, ft_atof(fov) * (M_PI / 180.0));
	temp = ft_split(position, ',');
	p1.x = ft_atof(temp[0]);
	p1.y = ft_atof(temp[1]);
	p1.z = ft_atof(temp[2]);
	ft_split_free(&temp);
	temp = ft_split(normal, ',');
	p2.x = ft_atof(temp[0]);
	p2.y = ft_atof(temp[1]);
	p2.z = ft_atof(temp[2]);
	ft_split_free(&temp);
	cc = view_transform(point(p1.x, p1.y, p1.z),
	point(p2.x, p2.y, p2.z),
	vector(0, 1, 0));
	copy_matrix(&c.transform, cc);
	cameras(&config->c_cameras, c);
	free_matrix(&cc);
}
