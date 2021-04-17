/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_free.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdutenke <rdutenke@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 02:05:59 by rdutenke          #+#    #+#             */
/*   Updated: 2021/04/17 02:06:16 by rdutenke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

void	ft_split_free(char ***split)
{
	char	**temp;
	int		i;

	i = 0;
	temp = *split;
	while (temp[i] != NULL)
	{
		free(temp[i]);
		temp[i] = NULL;
		i++;
	}
	free(temp);
	temp = NULL;
}
