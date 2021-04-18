/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_normal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdutenke <rdutenke@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 23:18:33 by rdutenke          #+#    #+#             */
/*   Updated: 2021/04/17 23:19:35 by rdutenke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

static bool	is_unit(float x, float y, float z)
{
	if (fabs(sqrt(x * x + y * y + z * z) - 1) < EPSILON)
	{
		return (true);
	}
	return (false);
}

bool		is_normal(char *s)
{
	char	**temp;
	t_tuple	t;

	temp = ft_split(s, ',');
	if (ft_str_dlen(temp) != 3)
	{
		ft_split_free(&temp);
		return (false);
	}
	if (!(is_num(temp[0]) || is_num(temp[1]) || is_num(temp[2])))
	{
		ft_split_free(&temp);
		return (false);
	}
	t.x = ft_atof(temp[0]);
	t.y = ft_atof(temp[1]);
	t.z = ft_atof(temp[2]);
	if (!is_unit(t.x, t.y, t.z))
	{
		ft_split_free(&temp);
		return (false);
	}
	ft_split_free(&temp);
	return (true);
}
