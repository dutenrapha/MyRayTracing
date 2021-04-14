/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   det.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdutenke <rdutenke@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 20:41:52 by rdutenke          #+#    #+#             */
/*   Updated: 2021/04/14 20:44:08 by rdutenke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

float	det(t_matrix a)
{
	float	resp;
	int		i;

	resp = 0;
	if (a.dim == 2)
	{
		resp = a.element[0][0] * a.element[1][1]
		- a.element[0][1] * a.element[1][0];
	}
	else
	{
		i = 0;
		while (i < a.dim)
		{
			resp = resp + a.element[0][i] * cofactor(a, 0, i);
			i++;
		}
	}
	return (resp);
}
