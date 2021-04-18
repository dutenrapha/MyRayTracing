/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdutenke <rdutenke@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 19:31:19 by rdutenke          #+#    #+#             */
/*   Updated: 2021/04/18 19:31:41 by rdutenke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

t_tuple	vector(float x, float y, float z)
{
	t_tuple	v;

	v.x = x;
	v.y = y;
	v.z = z;
	v.w = 0;
	return (v);
}
