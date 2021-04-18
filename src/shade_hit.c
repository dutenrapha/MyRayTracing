/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shade_hit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdutenke <rdutenke@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 19:09:08 by rdutenke          #+#    #+#             */
/*   Updated: 2021/04/18 21:22:24 by rdutenke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

static void		ft_init(t_par10 *i, t_world world, t_comps comps, t_light c)
{
	i->a = world.ambient;
	i->material = comps.object.material;
	i->light = c;
	i->position = comps.over_point;
	i->eyev = comps.eyev;
	i->normalv = comps.normalv;
}

static void		ft_init2(t_par10 *i, bool shadowed)
{
	i->in_shadow = shadowed;
}

static t_color	ft_aux(t_light l, t_par10 *i, t_color c2, t_par13 p)
{
	t_color		c1;

	p.shadowed = is_shadowed(l, p.world, p.comps.over_point);
	ft_init(i, p.world, p.comps, l);
	ft_init2(i, p.shadowed);
	c1 = lighting(*i);
	c2 = addcolor(c1, c2);
	return (c2);
}

static void		ft_init3(t_par13 *p, t_world world, t_comps comps)
{
	p->world = world;
	p->comps = comps;
}

t_color			shade_hit(t_world world, t_comps comps)
{
	t_lights	*temp;
	t_par13		p;
	t_par10		i;
	t_par14		c;

	c.c1 = color(0, 0, 0);
	c.c2 = color(0, 0, 0);
	temp = world.lights;
	if (world.has_light)
	{
		while (temp->next)
		{
			p.shadowed = is_shadowed(temp->content, world, comps.over_point);
			ft_init(&i, world, comps, temp->content);
			ft_init2(&i, p.shadowed);
			c.c1 = lighting(i);
			c.c2 = addcolor(c.c1, c.c2);
			temp = temp->next;
		}
		ft_init3(&p, world, comps);
		c.c2 = ft_aux(temp->content, &i, c.c2, p);
		return (c.c2);
	}
	else
		return (world.ambient);
}
