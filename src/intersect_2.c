/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdutenke <rdutenke@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 18:34:59 by rdutenke          #+#    #+#             */
/*   Updated: 2021/04/17 18:35:06 by rdutenke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

void	intersect_2(t_shape *s, t_ray ray)
{
	t_ray local_ray;

	local_ray = transform(ray, inverse(s->transform));
	s->saved_ray = local_ray;
}
