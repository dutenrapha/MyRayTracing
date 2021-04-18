/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lighting.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdutenke <rdutenke@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 23:57:48 by rdutenke          #+#    #+#             */
/*   Updated: 2021/04/18 20:48:49 by rdutenke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

static void	ft_int(t_par11 *q, t_par10 p, float *light_dot_normal)
{
	q->black = color(0, 0, 0);
	q->effective_color = multicolor_v(p.material.color, p.light.intensity);
	q->lightv = normalize(sub(p.light.position, p.position));
	q->ambient = multicolor_s(q->effective_color, p.material.ambient);
	q->ambient = addcolor(q->ambient, p.a);
	*light_dot_normal = dot(q->lightv, p.normalv);
}

static void	ft_aux(t_par11 *q, t_par10 *p, float *light_dot_normal, t_par12 *y)
{
	q->diffuse = multicolor_s(q->effective_color,
	p->material.diffuse *
	*light_dot_normal);
	q->reflectv = reflect(multi(q->lightv, -1), p->normalv);
	y->reflect_dot_eye = dot(q->reflectv, p->eyev);
	if (y->reflect_dot_eye <= 0)
	{
		q->specular = q->black;
	}
	else
	{
		y->factor = pow(y->reflect_dot_eye, p->material.shininess);
		q->specular = multicolor_s(p->light.intensity,
		p->material.specular * y->factor);
	}
}

t_color		lighting(t_par10 p)
{
	t_par11 q;
	float	light_dot_normal;
	t_par12 y;

	ft_int(&q, p, &light_dot_normal);
	if (light_dot_normal < 0)
	{
		q.diffuse = q.black;
		q.specular = q.black;
	}
	else
	{
		ft_aux(&q, &p, &light_dot_normal, &y);
	}
	if (p.in_shadow == true)
	{
		q.diffuse = q.black;
		q.specular = q.black;
	}
	return (addcolor(q.ambient, addcolor(q.diffuse, q.specular)));
}
