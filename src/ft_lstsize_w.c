/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_w.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdutenke <rdutenke@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 01:07:51 by rdutenke          #+#    #+#             */
/*   Updated: 2021/04/17 01:08:00 by rdutenke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

int	ft_lstsize_w(t_objects *lst)
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
