/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transpose.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdutenke <rdutenke@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 19:29:15 by rdutenke          #+#    #+#             */
/*   Updated: 2021/04/18 19:30:27 by rdutenke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

t_matrix	transpose(t_matrix a)
{
	t_matrix	at;
	int			i;
	int			j;

	at = matrix(4);
	i = 0;
	while (i < a.dim)
	{
		j = 0;
		while (j < a.dim)
		{
			at.element[j][i] = a.element[i][j];
			j++;
		}
		i++;
	}
	return (at);
}
