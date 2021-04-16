/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_o.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdutenke <rdutenke@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 01:07:36 by rdutenke          #+#    #+#             */
/*   Updated: 2021/04/17 01:08:04 by rdutenke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

int	ft_lstsize_o(t_objects *lst)
{
	int			i;
	t_objects	*temp;

	if (lst)
	{
		i = 1;
		temp = lst;
		while (temp->next)
		{
			temp = temp->next;
			i++;
		}
		return (i);
	}
	else
		return (0);
}
