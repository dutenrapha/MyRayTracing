/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cameras.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdutenke <rdutenke@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 20:08:19 by rdutenke          #+#    #+#             */
/*   Updated: 2021/04/14 20:09:10 by rdutenke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

void	cameras(t_cameras **l, t_camera c)
{
	t_cameras *temp;

	if (ft_lstsize_c(*l) == 0)
	{
		*l = ft_lstnew_c(c);
	}
	else
	{
		temp = *l;
		while (temp->next)
		{
			temp = temp->next;
		}
		temp->next = ft_lstnew_c(c);
	}
}
