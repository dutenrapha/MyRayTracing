/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdutenke <rdutenke@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 02:12:48 by rdutenke          #+#    #+#             */
/*   Updated: 2021/04/18 19:42:09 by rdutenke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

t_canvas	render(t_camera camera, t_world world)
{
	t_canvas	image;
	int			x;
	int			y;
	t_ray		ray;
	t_color		color;

	image = canvas(camera.hsize, camera.vsize);
	y = 0;
	while (y < camera.vsize - 1)
	{
		x = 0;
		while (x < camera.hsize - 1)
		{
			ray = ray_for_pixel(camera, x, y);
			color = color_at(world, ray);
			write_pixel(&image, x, y, color);
			x++;
		}
		y++;
	}
	return (image);
}
