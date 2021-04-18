/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdutenke <rdutenke@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 02:22:18 by rdutenke          #+#    #+#             */
/*   Updated: 2021/04/18 19:39:20 by rdutenke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

static void	ft_init(float *v, float *v1, float *v2, t_tuple normal)
{
	float	angle;

	angle = acos(dot(normal, vector(0, 1, 0)));
	*v = cos(angle);
	*v1 = sin(angle);
	*v2 = 1.0 - *v;
}

t_matrix	rotation(t_tuple normal)
{
	t_matrix	a;
	float		vals[3];
	t_tuple		axis;

	a = matrix(4);
	axis = cross(normal, vector(0, 1, 0));
	ft_init(&vals[0], &vals[1], &vals[2], normal);
	write_matrix(&a, 0, 0, vals[0] + (pow(axis.x, 2) * vals[2]));
	write_matrix(&a, 0, 1, (axis.x * axis.y * vals[2]) - (axis.z * vals[1]));
	write_matrix(&a, 0, 2, (axis.x * axis.z * vals[2]) + (axis.y * vals[1]));
	write_matrix(&a, 0, 3, 0.0);
	write_matrix(&a, 1, 0, (axis.y * axis.z * vals[2]) + (axis.z * vals[1]));
	write_matrix(&a, 1, 1, vals[0] + (pow(axis.y, 2) * vals[2]));
	write_matrix(&a, 1, 2, (axis.y * axis.z * vals[2]) - (axis.x * vals[1]));
	write_matrix(&a, 1, 3, 0.0);
	write_matrix(&a, 2, 0, (axis.z * axis.x * vals[2]) - (axis.y * vals[1]));
	write_matrix(&a, 2, 1, (axis.z * axis.y * vals[2]) + (axis.x * vals[1]));
	write_matrix(&a, 2, 2, vals[0] + (pow(axis.z, 2) * vals[2]));
	write_matrix(&a, 2, 3, 0.0);
	write_matrix(&a, 3, 0, 0.0);
	write_matrix(&a, 3, 1, 0.0);
	write_matrix(&a, 3, 2, 0.0);
	write_matrix(&a, 3, 3, 1.0);
	return (a);
}
