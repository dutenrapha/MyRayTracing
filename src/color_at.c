/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_at.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdutenke <rdutenke@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 20:20:04 by rdutenke          #+#    #+#             */
/*   Updated: 2021/04/14 20:21:57 by rdutenke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

t_color	color_at(t_world world, t_ray ray)
{
	t_list			*inter_world;
	t_color			c;
	t_intersection	in;
	t_comps			comps;

	inter_world = intersect_world(world, ray);
	in = hit(inter_world);
	if (inter_world != NULL)
	{
		ft_lstclear(&inter_world);
	}
	if (in.valid == false)
	{
		c = color(0, 0, 0);
		return (c);
	}
	else
	{
		comps = prepare_computations(in, ray);
		c = shade_hit(world, comps);
		return (c);
	}
}
