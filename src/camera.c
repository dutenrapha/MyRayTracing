/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdutenke <rdutenke@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 20:00:32 by rdutenke          #+#    #+#             */
/*   Updated: 2021/04/14 20:55:15 by rdutenke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

static void	init_camera(t_camera *c, int hsize, int vsize, float field_of_view)
{
	c->hsize = hsize;
	c->vsize = vsize;
	c->field_of_view = field_of_view;
}

t_camera	camera(int hsize, int vsize, float field_of_view)
{
	t_camera	c;
	float		half_view;
	float		aspect;
	t_matrix	i;

	init_camera(&c, hsize, vsize, field_of_view);
	c.transform = matrix(4);
	i = identity();
	copy_matrix(&c.transform, i);
	free_matrix(&i);
	half_view = tan(c.field_of_view / 2);
	aspect = (float)c.hsize / (float)c.vsize;
	if (aspect >= 1)
	{
		c.half_width = half_view;
		c.half_height = half_view / aspect;
	}
	else
	{
		c.half_width = half_view * aspect;
		c.half_height = half_view;
	}
	c.pixel_size = (c.half_width * 2) / c.hsize;
	return (c);
}
