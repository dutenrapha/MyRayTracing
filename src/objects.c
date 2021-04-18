/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdutenke <rdutenke@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 01:26:29 by rdutenke          #+#    #+#             */
/*   Updated: 2021/04/18 01:26:52 by rdutenke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

void	objects(t_objects **l, t_object o)
{
	t_objects *temp;

	if (ft_lstsize_o(*l) == 0)
	{
		*l = ft_lstnew_o(o);
	}
	else
	{
		temp = *l;
		while (temp->next)
		{
			temp = temp->next;
		}
		temp->next = ft_lstnew_o(o);
	}
}
