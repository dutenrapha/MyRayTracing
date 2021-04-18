/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdutenke <rdutenke@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 22:47:50 by rdutenke          #+#    #+#             */
/*   Updated: 2021/04/17 23:53:12 by rdutenke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

static void	ft_init(float *d, float *c, t_matrix *b, t_matrix a)
{
	*d = det(a);
	*c = 0;
	*b = matrix(a.dim);
}

t_matrix	inverse(t_matrix a)
{
	t_matrix	b;
	t_par6		p;
	float		c;
	float		d;

	ft_init(&d, &c, &b, a);
	if (!is_invertible(a))
	{
		ft_printf("Not invertible matrix");
		return (b);
	}
	else
	{
		p.i = -1;
		while (++(p.i) < a.dim)
		{
			p.j = -1;
			while (++(p.j) < a.dim)
			{
				c = cofactor(a, p.i, p.j);
				b.element[p.j][p.i] = c / d;
			}
		}
		return (b);
	}
}
