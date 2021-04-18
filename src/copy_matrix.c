/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_matrix.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdutenke <rdutenke@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 20:26:13 by rdutenke          #+#    #+#             */
/*   Updated: 2021/04/18 19:40:42 by rdutenke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

void	copy_matrix(t_matrix *d, t_matrix o)
{
	int	i;
	int	j;

	i = 0;
	while (i < o.dim)
	{
		j = 0;
		while (j < o.dim)
		{
			write_matrix(d, i, j, o.element[i][j]);
			j++;
		}
		i++;
	}
}
