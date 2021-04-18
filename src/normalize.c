/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdutenke <rdutenke@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 01:24:14 by rdutenke          #+#    #+#             */
/*   Updated: 2021/04/18 01:25:04 by rdutenke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

t_tuple	normalize(t_tuple v1)
{
	float	m;
	t_tuple	v2;

	m = magnitude(v1);
	if (m > 0)
	{
		v2.x = v1.x / m;
		v2.y = v1.y / m;
		v2.z = v1.z / m;
		v2.w = v1.w / m;
	}
	else
	{
		v2.x = 0;
		v2.y = 0;
		v2.z = 0;
		v2.w = 0;
	}
	return (v2);
}
