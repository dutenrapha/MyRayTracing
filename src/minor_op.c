/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minor_op.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdutenke <rdutenke@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 00:25:09 by rdutenke          #+#    #+#             */
/*   Updated: 2021/04/18 00:27:10 by rdutenke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

float	minor_op(t_matrix a, int i, int j)
{
	t_matrix	b;
	float		d;

	b = submatrix(a, i, j);
	d = det(b);
	free_matrix(&b);
	return (d);
}
