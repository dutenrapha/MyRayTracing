/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_shadowed.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdutenke <rdutenke@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 23:23:05 by rdutenke          #+#    #+#             */
/*   Updated: 2021/04/17 23:27:16 by rdutenke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

bool	is_shadowed(t_light light, t_world world, t_tuple point)
{
	t_tuple			v;
	t_par7			p;
	t_ray			r;
	t_list			*intersections;
	t_intersection	h;

	v = sub(light.position, point);
	p.distance = magnitude(v);
	p.direction = normalize(v);
	r = ray(point, p.direction);
	intersections = intersect_world(world, r);
	h = hit(intersections);
	if (intersections != NULL)
	{
		ft_lstclear(&intersections);
	}
	if (h.valid == true && h.t < p.distance)
	{
		return (true);
	}
	else
	{
		return (false);
	}
}
