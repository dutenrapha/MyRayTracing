/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_rt_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdutenke <rdutenke@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 23:21:27 by rdutenke          #+#    #+#             */
/*   Updated: 2021/04/17 23:22:02 by rdutenke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

bool	is_rt_file(char *file)
{
	char	*temp;
	bool	resp;

	resp = false;
	temp = ft_strchr(file, '.');
	if (ft_memcmp(".rt", temp, 4) == 0)
	{
		resp = true;
	}
	return (resp);
}
