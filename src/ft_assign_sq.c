/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_assign_sq.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdutenke <rdutenke@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 18:07:40 by rdutenke          #+#    #+#             */
/*   Updated: 2021/04/18 00:07:20 by rdutenke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

static t_matrix	ft_posi(t_object *o, char *position, char *cor, char *size)
{
	char		**temp;
	t_tuple		p;
	t_color		c;
	t_matrix	d;

	temp = ft_split(position, ',');
	p.x = ft_atof(temp[0]);
	p.y = ft_atof(temp[1]);
	p.z = ft_atof(temp[2]);
	o->center = point(p.x, p.y, p.z);
	o->side = ft_atof(size);
	ft_split_free(&temp);
	temp = ft_split(cor, ',');
	c.red = (float)ft_atoi(temp[0]);
	c.green = (float)ft_atoi(temp[1]);
	c.blue = (float)ft_atoi(temp[2]);
	ft_split_free(&temp);
	o->material = material();
	o->material.color = color(c.red / 255, c.green / 255, c.blue / 255);
	o->material.specular = 0;
	d = translation(p.x, p.y, p.z);
	return (d);
}

static t_tuple	ft_normal(t_object *o, char *normal)
{
	char	**temp;
	t_tuple	p;

	temp = ft_split(normal, ',');
	p.x = ft_atof(temp[0]);
	p.y = ft_atof(temp[1]);
	p.z = ft_atof(temp[2]);
	o->normal = vector(p.x, p.y, p.z);
	ft_split_free(&temp);
	return (p);
}

void			ft_assign_sq(t_config *config, char *ps, char *n, t_par2 p)
{
	t_object	o;
	t_matrix	c;
	t_matrix	a;
	t_matrix	d;
	t_tuple		po;

	o = square();
	c = ft_posi(&o, ps, p.cor, p.size);
	po = ft_normal(&o, n);
	a = rotation(vector(po.x, po.y, po.z));
	d = matrix_multi(a, c);
	copy_matrix(&o.transform, d);
	free_matrix(&a);
	free_matrix(&c);
	free_matrix(&d);
	objects(&config->o_objects, o);
}
