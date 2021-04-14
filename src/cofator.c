/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cofator.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdutenke <rdutenke@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 20:16:41 by rdutenke          #+#    #+#             */
/*   Updated: 2021/04/14 20:18:07 by rdutenke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

float	cofactor(t_matrix a, int i, int j)
{
	float	resp;

	resp = 0;
	resp = minor_op(a, i, j);
	if ((i + j) % 2 != 0)
	{
		resp = -1 * resp;
	}
	return (resp);
}
