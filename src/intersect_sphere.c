/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_sphere.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdutenke <rdutenke@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 21:52:00 by rdutenke          #+#    #+#             */
/*   Updated: 2021/04/18 22:05:09 by rdutenke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

static void	ft_aux(t_par15 *p, t_ray ray_t, t_object s)
{
	p->sphere_to_ray = sub(ray_t.origin, s.center);
	p->p.x = dot(ray_t.direction, ray_t.direction);
	p->p.y = 2 * dot(ray_t.direction, p->sphere_to_ray);
	p->p.z = dot(p->sphere_to_ray, p->sphere_to_ray) - 1;
	p->discriminant = p->p.y * p->p.y - 4 * p->p.x * p->p.z;
}

t_list		*intersect_sphere(t_object s, t_ray ray)
{
	t_list	*xs;
	t_list	*ii;
	t_ray	ray_t;
	t_par15	p;

	xs = NULL;
	p.inv = inverse(s.transform);
	ray_t = transform(ray, p.inv);
	free_matrix(&p.inv);
	ft_aux(&p, ray_t, s);
	if (p.discriminant > 0)
	{
		p.i1.t = (-p.p.y - sqrt(p.discriminant)) / (2 * p.p.x);
		p.i1.object = s;
		p.i2.t = (-p.p.y + sqrt(p.discriminant)) / (2 * p.p.x);
		p.i2.object = s;
		xs = ft_lstnew(p.i1);
		ii = ft_lstnew(p.i2);
		if (p.i1.t > 0 || p.i2.t > 0)
		{
			p.p.z = 1;
		}
		ft_lstadd_back(&xs, ii);
	}
	return (xs);
}
