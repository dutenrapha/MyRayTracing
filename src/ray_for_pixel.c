/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_for_pixel.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdutenke <rdutenke@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 02:07:08 by rdutenke          #+#    #+#             */
/*   Updated: 2021/04/18 02:11:25 by rdutenke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

t_ray	ray_for_pixel(t_camera camera, float px, float py)
{
	t_par8		p;
	t_matrix	a;
	t_tuple		pixel;
	t_tuple		origin;
	t_tuple		direction;

	p.xoffset = (px + 0.5) * camera.pixel_size;
	p.yoffset = (py + 0.5) * camera.pixel_size;
	p.world_x = camera.half_width - p.xoffset;
	p.world_y = camera.half_height - p.yoffset;
	a = inverse(camera.transform);
	pixel = matrix_multi_vec(a, point(p.world_x, p.world_y, -1));
	origin = matrix_multi_vec(a, point(0, 0, 0));
	free_matrix(&a);
	direction = normalize(sub(pixel, origin));
	p.r = ray(origin, direction);
	return (p.r);
}
