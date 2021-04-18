/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdutenke <rdutenke@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 01:29:55 by rdutenke          #+#    #+#             */
/*   Updated: 2021/04/18 01:30:20 by rdutenke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

t_tuple	position(t_ray ray, float t)
{
	t_tuple	p;

	p = add(ray.origin, multi(ray.direction, t));
	return (p);
}
