/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_assign_sp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdutenke <rdutenke@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 17:26:48 by rdutenke          #+#    #+#             */
/*   Updated: 2021/04/19 04:27:24 by rdutenke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

static void		ft_cor(t_object *o, char *cor)
{
	char	**temp;
	t_color	cc;

	temp = ft_split(cor, ',');
	cc.red = (float)ft_atoi(temp[0]);
	cc.green = (float)ft_atoi(temp[1]);
	cc.blue = (float)ft_atoi(temp[2]);
	o->material = material();
	o->material.color = color(cc.red / 255, cc.green / 255, cc.blue / 255);
	o->material.specular = 0;
	ft_split_free(&temp);
}

static t_matrix	ft_posi(char *position, float r)
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
	ft_split_free(&temp);
	a = translation(p.x, p.y, p.z);
	d = scaling(r, r, r);
	c = matrix_multi(a, d);
	free_matrix(&a);
	free_matrix(&d);
	return (c);
}

void			ft_assign_sp(t_config *config, char *p, char *d, char *cor)
{
	t_object	o;
	t_matrix	c;
	float		r;

	o = sphere();
	r = ft_atof(d) / 2;
	c = ft_posi(p, r);
	copy_matrix(&o.transform,c);
	free_matrix(&c);
	ft_cor(&o, cor);
	objects(&config->o_objects, o);
}
