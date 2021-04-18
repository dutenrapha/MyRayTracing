/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_z.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdutenke <rdutenke@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 02:18:28 by rdutenke          #+#    #+#             */
/*   Updated: 2021/04/18 19:39:34 by rdutenke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

t_matrix	rotation_z(float r)
{
	t_matrix a;

	a = matrix(4);
	write_matrix(&a, 0, 0, cos(r));
	write_matrix(&a, 0, 1, -sin(r));
	write_matrix(&a, 0, 2, 0.0);
	write_matrix(&a, 0, 3, 0.0);
	write_matrix(&a, 1, 0, sin(r));
	write_matrix(&a, 1, 1, cos(r));
	write_matrix(&a, 1, 2, 0.0);
	write_matrix(&a, 1, 3, 0.0);
	write_matrix(&a, 2, 0, 0.0);
	write_matrix(&a, 2, 1, 0.0);
	write_matrix(&a, 2, 2, 1.0);
	write_matrix(&a, 2, 3, 0.0);
	write_matrix(&a, 3, 0, 0.0);
	write_matrix(&a, 3, 1, 0.0);
	write_matrix(&a, 3, 2, 0.0);
	write_matrix(&a, 3, 3, 1.0);
	return (a);
}
