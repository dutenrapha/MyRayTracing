/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_assign_cy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdutenke <rdutenke@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 22:58:12 by rdutenke          #+#    #+#             */
/*   Updated: 2021/04/15 22:58:14 by rdutenke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

static	t_matrix	ft_posi(char *position, char *diameter)
{
	t_matrix	a;
	t_matrix	d;
	t_matrix	c;
	char		**temp;
	t_tuple		p;

	temp = ft_split(position, ',');
	p.x = ft_atof(temp[0]);
	p.y = ft_atof(temp[1]);
	p.z = ft_atof(temp[2]);
	a = translation(p.x, p.y, p.z);
	d = scaling(ft_atof(diameter) / 2, 1, ft_atof(diameter) / 2);
	c = matrixMulti(a, d);
	ft_split_free(&temp);
	free_matrix(&a);
	free_matrix(&d);
	return (c);
}

static	t_matrix	ft_cor_normal(t_object *o, char *cor, char *normal)
{
	char		**temp;
	t_color		cc;
	t_tuple		p;
	t_matrix	a;

	temp = ft_split(cor, ',');
	cc.red = (float)ft_atoi(temp[0]);
	cc.green = (float)ft_atoi(temp[1]);
	cc.blue = (float)ft_atoi(temp[2]);
	o->material = material();
	o->material.color = color(cc.red / 255, cc.green / 255, cc.blue / 255);
	o->material.specular = 0;
	ft_split_free(&temp);
	temp = ft_split(normal, ',');
	p.x = ft_atof(temp[0]);
	p.y = ft_atof(temp[1]);
	p.z = ft_atof(temp[2]);
	o->normal = vector(p.x, p.y, p.z);
	o->minimum = 0;
	ft_split_free(&temp);
	a = rotation(vector(p.x, p.y, p.z));
	return (a);
}

void				ft_assign_cy(t_config *config, t_par p)
{
	t_object	o;
	t_matrix	a;
	t_matrix	d;
	t_matrix	c;
	float		s;

	o = cylinder();
	c = ft_posi(p.position, p.diameter);
	a = ft_cor_normal(&o, p.cor, p.normal);
	d = matrixMulti(a, c);
	copy_matrix(&o.transform, d);
	free_matrix(&a);
	free_matrix(&c);
	free_matrix(&d);
	s = ft_atof(p.height);
	o.maximum = s;
	o.closed = true;
	objects(&config->o_objects, o);
}
