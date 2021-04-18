/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   submatrix.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdutenke <rdutenke@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 19:19:04 by rdutenke          #+#    #+#             */
/*   Updated: 2021/04/18 19:24:45 by rdutenke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

t_matrix	submatrix(t_matrix a, int i, int j)
{
	t_matrix	b;
	int			l;
	int			m;
	int			ii;
	int			jj;

	b = matrix(a.dim - 1);
	l = -1;
	ii = 0;
	while (++l < a.dim)
	{
		m = -1;
		jj = 0;
		while (++m < a.dim)
		{
			if ((l != i) && (m != j))
			{
				b.element[ii][jj] = a.element[l][m];
				jj++;
			}
		}
		if ((l != i) && (m != j))
			ii++;
	}
	return (b);
}
