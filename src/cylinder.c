/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdutenke <rdutenke@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 20:41:07 by rdutenke          #+#    #+#             */
/*   Updated: 2021/04/15 22:36:13 by rdutenke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

t_object	cylinder()
{
	t_object	p;

	p.id = 1;
	p.type = "cylinder";
	p.center = point(0, 0, 0);
	p.transform = identity();
	p.material.color = color(1, 1, 1);
	p.material.ambient = 0.1;
	p.material.diffuse = 0.9;
	p.material.specular = 0.9;
	p.material.shininess = 200;
	p.minimum = -INFINITY;
	p.maximum = INFINITY;
	p.closed = false;
	p.p1 = point(0, 0, 0);
	p.p2 = point(0, 0, 0);
	p.p3 = point(0, 0, 0);
	p.e1 = point(0, 0, 0);
	p.e2 = point(0, 0, 0);
	p.normal = point(0, 0, 0);
	return (p);
}
