/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdutenke <rdutenke@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 02:15:10 by rdutenke          #+#    #+#             */
/*   Updated: 2021/04/18 19:39:51 by rdutenke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

t_matrix	rotation_x(float r)
{
	t_matrix a;

	a = matrix(4);
	write_matrix(&a, 0, 0, 1.0);
	write_matrix(&a, 0, 1, 0.0);
	write_matrix(&a, 0, 2, 0.0);
	write_matrix(&a, 0, 3, 0.0);
	write_matrix(&a, 1, 0, 0.0);
	write_matrix(&a, 1, 1, cos(r));
	write_matrix(&a, 1, 2, -sin(r));
	write_matrix(&a, 1, 3, 0.0);
	write_matrix(&a, 2, 0, 0.0);
	write_matrix(&a, 2, 1, sin(r));
	write_matrix(&a, 2, 2, cos(r));
	write_matrix(&a, 2, 3, 0.0);
	write_matrix(&a, 3, 0, 0.0);
	write_matrix(&a, 3, 1, 0.0);
	write_matrix(&a, 3, 2, 0.0);
	write_matrix(&a, 3, 3, 1.0);
	return (a);
}
