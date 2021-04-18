/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdutenke <rdutenke@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 19:27:10 by rdutenke          #+#    #+#             */
/*   Updated: 2021/04/18 19:41:18 by rdutenke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

t_matrix	translation(float x, float y, float z)
{
	t_matrix a;

	a = matrix(4);
	write_matrix(&a, 0, 0, 1.0);
	write_matrix(&a, 0, 1, 0.0);
	write_matrix(&a, 0, 2, 0.0);
	write_matrix(&a, 0, 3, x);
	write_matrix(&a, 1, 0, 0.0);
	write_matrix(&a, 1, 1, 1.0);
	write_matrix(&a, 1, 2, 0.0);
	write_matrix(&a, 1, 3, y);
	write_matrix(&a, 2, 0, 0.0);
	write_matrix(&a, 2, 1, 0.0);
	write_matrix(&a, 2, 2, 1.0);
	write_matrix(&a, 2, 3, z);
	write_matrix(&a, 3, 0, 0.0);
	write_matrix(&a, 3, 1, 0.0);
	write_matrix(&a, 3, 2, 0.0);
	write_matrix(&a, 3, 3, 1.0);
	return (a);
}
