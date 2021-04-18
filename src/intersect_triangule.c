/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_triangule.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdutenke <rdutenke@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 22:15:23 by rdutenke          #+#    #+#             */
/*   Updated: 2021/04/18 22:19:35 by rdutenke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

t_list	*intersect_triangle(t_object triangle, t_ray ray)
{
	t_tuple		dir_cross_e2;
	t_tuple		p1_to_origin;
	t_tuple		origin_cross_e1;
	t_list		*xs;
	t_par16		p;

	xs = NULL;
	dir_cross_e2 = cross(ray.direction, triangle.e2);
	p.det = dot(triangle.e1, dir_cross_e2);
	if (fabs(p.det) < EPSILON)
		return (xs);
	p.f = 1.0 / p.det;
	p1_to_origin = sub(ray.origin, triangle.p1);
	p.u = p.f * dot(p1_to_origin, dir_cross_e2);
	if (p.u < 0 || p.u > 1)
		return (xs);
	origin_cross_e1 = cross(p1_to_origin, triangle.e1);
	p.v = p.f * dot(ray.direction, origin_cross_e1);
	if (p.v < 0 || (p.u + p.v) > 1)
		return (xs);
	p.t = p.f * dot(triangle.e2, origin_cross_e1);
	p.i1 = intersection(p.t, triangle);
	xs = ft_lstnew(p.i1);
	return (xs);
}
