/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_num.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdutenke <rdutenke@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 23:20:25 by rdutenke          #+#    #+#             */
/*   Updated: 2021/04/17 23:21:14 by rdutenke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

bool	is_num(char *s)
{
	int i;

	if (!(s[0] == '-' || ft_isdigit(s[0])))
	{
		return (false);
	}
	i = 1;
	while (s[i] != '\0')
	{
		if (!ft_isdigit(s[i]))
		{
			if (!(s[i] == '.'))
			{
				return (false);
			}
		}
		i++;
	}
	return (true);
}
