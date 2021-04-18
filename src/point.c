/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdutenke <rdutenke@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 01:29:17 by rdutenke          #+#    #+#             */
/*   Updated: 2021/04/18 01:29:27 by rdutenke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

t_tuple	point(float x, float y, float z)
{
	t_tuple v;

	v.x = x;
	v.y = y;
	v.z = z;
	v.w = 1;
	return (v);
}
