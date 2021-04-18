/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdutenke <rdutenke@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 23:13:10 by rdutenke          #+#    #+#             */
/*   Updated: 2021/04/17 23:16:12 by rdutenke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

bool	is_color(char *s)
{
	char	**temp;
	t_color	cc;

	temp = ft_split(s, ',');
	if (ft_str_dlen(temp) != 3)
	{
		ft_split_free(&temp);
		return (false);
	}
	if (!is_num(temp[0]) || !is_num(temp[1]) || !is_num(temp[2]))
	{
		ft_split_free(&temp);
		return (false);
	}
	cc.red = (float)ft_atoi(temp[0]);
	cc.green = (float)ft_atoi(temp[1]);
	cc.blue = (float)ft_atoi(temp[2]);
	if (cc.red < 0 || cc.red > 255 || cc.green < 0 || cc.green > 255
	|| cc.blue < 0 || cc.blue > 255)
	{
		ft_split_free(&temp);
		return (false);
	}
	ft_split_free(&temp);
	return (true);
}
