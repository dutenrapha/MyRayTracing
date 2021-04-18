/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_matrix_equal.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdutenke <rdutenke@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 23:50:15 by rdutenke          #+#    #+#             */
/*   Updated: 2021/04/18 19:46:08 by rdutenke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

bool	is_matrix_equal(t_matrix a, t_matrix b)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < a.dim)
	{
		while (j < a.dim)
		{
			if (fabs(a.element[i][j] - b.element[i][j]) > EPSILON)
			{
				return (false);
			}
			j++;
		}
		i++;
	}
	return (true);
}
