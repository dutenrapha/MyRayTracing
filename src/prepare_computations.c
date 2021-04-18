/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_computations.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdutenke <rdutenke@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 01:31:13 by rdutenke          #+#    #+#             */
/*   Updated: 2021/04/18 02:06:57 by rdutenke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

t_comps	prepare_computations(t_intersection i, t_ray r)
{
	t_comps	comps;

	comps.t = i.t;
	comps.object = i.object;
	comps.point = position(r, comps.t);
	comps.eyev = multi(r.direction, -1);
	if (ft_memcmp("triangle", i.object.type, 9) != 0)
	{
		comps.normalv = normal_at(comps.object, comps.point);
	}
	else
	{
		comps.normalv = i.object.normal;
	}
	comps.over_point = add(comps.point, multi(comps.normalv, 0.01));
	if (dot(comps.normalv, comps.eyev) < 0)
	{
		comps.inside = true;
		comps.normalv = multi(comps.normalv, -1);
	}
	else
	{
		comps.inside = false;
	}
	return (comps);
}
