/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_multi_vec.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdutenke <rdutenke@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 00:13:03 by rdutenke          #+#    #+#             */
/*   Updated: 2021/04/18 00:23:51 by rdutenke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

t_tuple	matrix_multi_vec(t_matrix a, t_tuple b)
{
	t_tuple ab;

	ab.x = a.element[0][0] * b.x + a.element[0][1] * b.y +
	a.element[0][2] * b.z + a.element[0][3] * b.w;
	ab.y = a.element[1][0] * b.x + a.element[1][1] * b.y +
	a.element[1][2] * b.z + a.element[1][3] * b.w;
	ab.z = a.element[2][0] * b.x + a.element[2][1] * b.y +
	a.element[2][2] * b.z + a.element[2][3] * b.w;
	ab.w = a.element[3][0] * b.x + a.element[3][1] * b.y +
	a.element[3][2] * b.z + a.element[3][3] * b.w;
	return (ab);
}
