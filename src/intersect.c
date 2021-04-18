/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdutenke <rdutenke@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 21:38:23 by rdutenke          #+#    #+#             */
/*   Updated: 2021/04/18 22:36:15 by rdutenke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

static t_list	*intersect_plan(t_object p, t_ray ray)
{
	t_list			*xs;
	t_intersection	i1;
	float			t;

	xs = NULL;
	if (fabs(ray.direction.y) < EPSILON)
	{
		return (xs);
	}
	t = -ray.origin.y / ray.direction.y;
	i1 = intersection(t, p);
	xs = ft_lstnew(i1);
	return (xs);
}

static t_list	*intersect_square(t_object p, t_ray ray)
{
	t_list			*xs;
	t_intersection	i1;
	float			t;
	t_tuple			point;
	float			border;

	xs = NULL;
	if (fabs(ray.direction.y) < EPSILON)
	{
		return (xs);
	}
	t = -ray.origin.y / ray.direction.y;
	if (t > 0)
	{
		point = sub(add(ray.origin, multi(ray.direction, t)), p.center);
		border = p.side * 0.5;
		if ((fabs(point.x) <= border) && (fabs(point.y)
		<= border) && (fabs(point.z) <= border))
		{
			i1 = intersection(t, p);
			xs = ft_lstnew(i1);
		}
	}
	return (xs);
}

static t_list	*ft_aux(t_object s, t_ray ray)
{
	t_ray		local_ray;
	t_list		*xs;
	t_matrix	a;

	if (ft_memcmp("plan", s.type, 5) == 0)
	{
		a = inverse(s.transform);
		local_ray = transform(ray, a);
		free_matrix(&a);
		xs = intersect_plan(s, local_ray);
	}
	else if (ft_memcmp("square", s.type, 7) == 0)
	{
		a = inverse(s.transform);
		local_ray = transform(ray, a);
		free_matrix(&a);
		xs = intersect_square(s, local_ray);
	}
	return (xs);
}

t_list			*intersect(t_object s, t_ray ray)
{
	t_list		*xs;
	t_ray		local_ray;
	t_matrix	a;

	xs = NULL;
	if (ft_memcmp("sphere", s.type, 7) == 0)
		xs = intersect_sphere(s, ray);
	else if (ft_memcmp("cylinder", s.type, 9) == 0)
	{
		a = inverse(s.transform);
		local_ray = transform(ray, a);
		free_matrix(&a);
		xs = intersect_cylinder(s, local_ray);
	}
	else if (ft_memcmp("triangle", s.type, 9) == 0)
	{
		a = inverse(s.transform);
		local_ray = transform(ray, a);
		free_matrix(&a);
		xs = intersect_triangle(s, local_ray);
	}
	else
		xs = ft_aux(s, ray);
	return (xs);
}
