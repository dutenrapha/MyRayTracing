/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_assign_pl.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdutenke <rdutenke@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 23:25:30 by rdutenke          #+#    #+#             */
/*   Updated: 2021/04/16 00:01:05 by rdutenke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

static t_matrix	ft_posi(t_object *o, char *ps, char *cor)
{
	char		**temp;
	t_tuple		p;
	t_matrix	c;
	t_color		cc;

	temp = ft_split(ps, ',');
	p.x = ft_atof(temp[0]);
	p.y = ft_atof(temp[1]);
	p.z = ft_atof(temp[2]);
	ft_split_free(&temp);
	temp = ft_split(cor, ',');
	cc.red = (float)ft_atoi(temp[0]);
	cc.green = (float)ft_atoi(temp[1]);
	cc.blue = (float)ft_atoi(temp[2]);
	c = translation(p.x, p.y, p.z);
	o->material = material();
	o->material.color = color(cc.red / 255, cc.green / 255, cc.blue / 255);
	o->material.specular = 0;
	return (c);
}

static t_matrix	ft_normal(char *normal)
{
	char		**temp2;
	t_tuple		p;
	t_matrix	a;

	temp2 = ft_split(normal, ',');
	p.x = ft_atof(temp2[0]);
	p.y = ft_atof(temp2[1]);
	p.z = ft_atof(temp2[2]);
	ft_split_free(&temp2);
	a = rotation(vector(p.x, p.y, p.z));
	return (a);
}

void			ft_assign_pl(t_config *config, char *ps, char *n, char *cor)
{
	t_object	o;
	t_matrix	a;
	t_matrix	c;
	t_matrix	d;

	o = plan();
	c = ft_posi(&o, ps, cor);
	a = ft_normal(n);
	d = matrixMulti(a, c);
	copy_matrix(&o.transform, d);
	free_matrix(&a);
	free_matrix(&c);
	free_matrix(&d);
	objects(&config->o_objects, o);
}
