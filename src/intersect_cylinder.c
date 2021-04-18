/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_cylinder.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdutenke <rdutenke@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 22:21:57 by rdutenke          #+#    #+#             */
/*   Updated: 2021/04/18 23:23:35 by rdutenke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

static t_list	*ft_aux1(t_par17 p, t_par18 *c, t_object cyl, t_ray ray)
{
	t_list	*ret;

	ret = NULL;
	if (fabs(p.a) < EPSILON)
	{
		p.cc = 1;
		c->xs_cap = intersect_caps(cyl, ray);
	}
	if (p.cc == 0)
	{
		if (ft_aux_cy(p, ray, c, cyl) != NULL)
			return (c->xs);
	}
	return (ret);
}

static t_list	*ft_aux2(t_par18 *c)
{
	if (c->xs != NULL)
	{
		ft_lstclear(&c->xs);
		c->xs = NULL;
	}
	return (c->xs_cap);
}

t_list			*intersect_cylinder(t_object cyl, t_ray ray)
{
	t_par17	p;
	t_par18	c;

	c.xs = NULL;
	c.xs_cap = NULL;
	p.cc = 0;
	p.a = ray.direction.x * ray.direction.x + ray.direction.z * ray.direction.z;
	if (ft_aux1(p, &c, cyl, ray) != NULL)
		return (c.xs);
	if (p.cc == 1)
	{
		ft_aux2(&c);
	}
	else if (ft_lstsize(c.xs_cap) == 0)
	{
		if (c.xs_cap != NULL)
		{
			ft_lstclear(&c.xs_cap);
			c.xs_cap = NULL;
		}
		return (c.xs);
	}
	else
		ft_lstadd_back(&c.xs, c.xs_cap);
	return (c.xs);
}
