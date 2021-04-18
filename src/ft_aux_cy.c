/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aux_cy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdutenke <rdutenke@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 23:21:58 by rdutenke          #+#    #+#             */
/*   Updated: 2021/04/18 23:34:20 by rdutenke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

static void	ft_aux1(t_par17 p, t_par18 *c, t_object cyl)
{
	t_list	*ii;

	if ((cyl.minimum < p.y1) && (p.y1 < cyl.maximum))
	{
		if (ft_lstsize(c->xs) == 1)
		{
			p.i1 = intersection(p.t1, cyl);
			ii = ft_lstnew(p.i1);
			ft_lstadd_back(&c->xs, ii);
		}
		else
		{
			p.i1 = intersection(p.t1, cyl);
			c->xs = ft_lstnew(p.i1);
		}
	}
}

static void	ft_aux(t_par17 p, t_ray ray, t_par18 *c, t_object cyl)
{
	if (p.t0 > p.t1)
	{
		p.temp = p.t0;
		p.t1 = p.t0;
		p.t0 = p.temp;
	}
	p.y0 = ray.origin.y + p.t0 * ray.direction.y;
	if ((cyl.minimum < p.y0) && (p.y0 < cyl.maximum))
	{
		p.i1 = intersection(p.t0, cyl);
		c->xs = ft_lstnew(p.i1);
	}
	p.y1 = ray.origin.y + p.t1 * ray.direction.y;
	ft_aux1(p, c, cyl);
}

t_list		*ft_aux_cy(t_par17 p, t_ray ray, t_par18 *c, t_object cyl)
{
	t_list	*ret;

	ret = NULL;
	p.b = 2 * ray.origin.x * ray.direction.x
	+ 2 * ray.origin.z * ray.direction.z;
	p.c = ray.origin.x * ray.origin.x + ray.origin.z * ray.origin.z - 1;
	p.discriminant = p.b * p.b - 4 * p.a * p.c;
	if (p.discriminant < 0)
	{
		c->xs = NULL;
		if (c->xs_cap != NULL)
		{
			free(c->xs_cap);
			ft_lstclear(&c->xs_cap);
			c->xs_cap = NULL;
		}
		return (c->xs);
	}
	p.t0 = (-p.b - sqrt(p.discriminant)) / (2 * p.a);
	p.t1 = (-p.b + sqrt(p.discriminant)) / (2 * p.a);
	ft_aux(p, ray, c, cyl);
	c->xs_cap = intersect_caps(cyl, ray);
	return (ret);
}
