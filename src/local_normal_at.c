/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   local_normal_at.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdutenke <rdutenke@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 21:24:58 by rdutenke          #+#    #+#             */
/*   Updated: 2021/04/18 21:28:41 by rdutenke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

static t_tuple	cyl_norm(t_object cyl, t_tuple point)
{
	float	dist;

	dist = point.x * point.x + point.z * point.z;
	if (dist < 1 && point.y >= cyl.maximum - EPSILON)
	{
		return (vector(0, 1, 0));
	}
	else if (dist < 1 && point.y <= cyl.minimum + EPSILON)
	{
		return (vector(0, -1, 0));
	}
	else
	{
		return (vector(point.x, 0, point.z));
	}
}

t_tuple			local_normal_at(t_object o, t_tuple local_point)
{
	t_tuple		local_normal;

	if (ft_memcmp(o.type, "sphere", 7) == 0)
	{
		local_normal = sub(local_point, point(0, 0, 0));
	}
	else if (ft_memcmp(o.type, "plan", 5) == 0
	|| ft_memcmp(o.type, "square", 7) == 0)
	{
		local_normal = vector(0, 1, 0);
	}
	else if (ft_memcmp(o.type, "cylinder", 9) == 0)
	{
		local_normal = cyl_norm(o, local_point);
	}
	else if (ft_memcmp(o.type, "triangle", 9) == 0)
	{
		local_normal = o.normal;
	}
	else
	{
		local_normal = vector(0, 0, 0);
	}
	return (local_normal);
}
