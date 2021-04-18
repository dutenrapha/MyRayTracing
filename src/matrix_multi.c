/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_multi.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdutenke <rdutenke@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 00:03:31 by rdutenke          #+#    #+#             */
/*   Updated: 2021/04/18 00:11:31 by rdutenke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

t_matrix	matrix_multi(t_matrix a, t_matrix b)
{
	t_matrix	ab;
	int			i;
	int			j;

	ab.dim = 4;
	ab = matrix(4);
	i = 0;
	while (i < a.dim)
	{
		j = 0;
		while (j < a.dim)
		{
			ab.element[i][j] = a.element[i][0] * b.element[0][j] +
			a.element[i][1] * b.element[1][j] + a.element[i][2] *
			b.element[2][j] + a.element[i][3] * b.element[3][j];
			j++;
		}
		i++;
	}
	return (ab);
}
