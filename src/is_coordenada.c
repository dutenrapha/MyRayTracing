/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_coordenada.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdutenke <rdutenke@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 23:16:44 by rdutenke          #+#    #+#             */
/*   Updated: 2021/04/17 23:17:14 by rdutenke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

bool	is_coordenada(char *s)
{
	char	**temp;

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
	ft_split_free(&temp);
	return (true);
}
