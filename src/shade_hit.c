/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shade_hit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdutenke <rdutenke@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 19:09:08 by rdutenke          #+#    #+#             */
/*   Updated: 2021/04/18 19:12:14 by rdutenke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

t_color	shade_hit(t_world world, t_comps comps)
{
	t_color		c1;
	t_color		c2;
	t_lights	*temp;
	bool		shadowed;

	c1 = color(0, 0, 0);
	c2 = color(0, 0, 0);
	temp = world.lights;
	if (world.has_light)
	{
		while (temp->next)
		{
			shadowed = is_shadowed(temp->content, world, comps.over_point);
			c1 = lighting(world.ambient, comps.object.material, temp->content, comps.over_point, comps.eyev, comps.normalv, shadowed);
			c2 = addcolor(c1, c2);
			temp = temp->next;
		}
		shadowed = is_shadowed(temp->content, world, comps.over_point);
		c1 = lighting(world.ambient, comps.object.material, temp->content, comps.over_point, comps.eyev, comps.normalv, shadowed);
		c2 = addcolor(c1, c2);
		return (c2);
	}
	else
		return (world.ambient);
}
