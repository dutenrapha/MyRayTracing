/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_config.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdutenke <rdutenke@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 00:38:38 by rdutenke          #+#    #+#             */
/*   Updated: 2021/04/17 01:03:20 by rdutenke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

static void	ft_aux(t_config *config, char *line)
{
	char	**line_t;
	t_par2	t;

	line_t = ft_split(line, ' ');
	if (ft_memcmp("R", line_t[0], 2) == 0)
		ft_assign_r(config, line_t[1], line_t[2]);
	if (ft_memcmp("A", line_t[0], 2) == 0)
		ft_assign_a(config, line_t[1], line_t[2]);
	if (ft_memcmp("c", line_t[0], 2) == 0)
		ft_assign_c(config, line_t[1], line_t[2], line_t[3]);
	if (ft_memcmp("l", line_t[0], 2) == 0)
		ft_assign_l(config, line_t[1], line_t[2], line_t[3]);
	if (ft_memcmp("pl", line_t[0], 3) == 0)
		ft_assign_pl(config, line_t[1], line_t[2], line_t[3]);
	if (ft_memcmp("sp", line_t[0], 3) == 0)
		ft_assign_sp(config, line_t[1], line_t[2], line_t[3]);
	if (ft_memcmp("sq", line_t[0], 3) == 0)
	{
		t.size = line_t[3];
		t.cor = line_t[4];
		ft_assign_sq(config, line_t[1], line_t[2], t);
	}
}

void		ft_conf(t_config **config, char *line)
{
	char	**line_t;
	t_par	p;
	t_par3	po;

	ft_aux(*config, line);
	line_t = ft_split(line, ' ');
	if (ft_memcmp("cy", line_t[0], 3) == 0)
	{
		p.position = line_t[1];
		p.normal = line_t[2];
		p.diameter = line_t[3];
		p.height = line_t[4];
		p.cor = line_t[5];
		ft_assign_cy(*config, p);
	}
	if (ft_memcmp("tr", line_t[0], 3) == 0)
	{
		po.p1 = line_t[1];
		po.p2 = line_t[2];
		po.p3 = line_t[3];
		ft_assign_tr(*config, po, line_t[4]);
	}
	ft_split_free(&line_t);
}
