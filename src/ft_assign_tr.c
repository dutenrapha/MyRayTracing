/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_assign_tr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdutenke <rdutenke@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 19:26:21 by rdutenke          #+#    #+#             */
/*   Updated: 2021/04/16 19:43:13 by rdutenke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

static t_object	ft_points(char *p1, char *p2, char *p3)
{
	char		**temp;
	t_tuple		x1;
	t_tuple		x2;
	t_tuple		x3;
	t_object	o;

	temp = ft_split(p1, ',');
	x1.x = ft_atof(temp[0]);
	x1.y = ft_atof(temp[1]);
	x1.z = ft_atof(temp[2]);
	ft_split_free(&temp);
	temp = ft_split(p2, ',');
	x2.x = ft_atof(temp[0]);
	x2.y = ft_atof(temp[1]);
	x2.z = ft_atof(temp[2]);
	ft_split_free(&temp);
	temp = ft_split(p3, ',');
	x3.x = ft_atof(temp[0]);
	x3.y = ft_atof(temp[1]);
	x3.z = ft_atof(temp[2]);
	ft_split_free(&temp);
	o = triangle(5, point(x1.x, x1.y, x1.z),
	point(x2.x, x2.y, x2.z),
	point(x3.x, x3.y, x3.z));
	return (o);
}

void			ft_assign_tr(t_config *config, t_par3 po, char *cor)
{
	t_object	o;
	t_color		cc;
	char		**temp;

	o = ft_points(po.p1, po.p2, po.p3);
	temp = ft_split(cor, ',');
	cc.red = (float)ft_atoi(temp[0]);
	cc.green = (float)ft_atoi(temp[1]);
	cc.blue = (float)ft_atoi(temp[2]);
	o.material = material();
	o.material.color = color(cc.red / 255, cc.green / 255, cc.blue / 255);
	o.material.specular = 0;
	objects(&config->o_objects, o);
	ft_split_free(&temp);
}
