/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdutenke <rdutenke@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 19:33:43 by rdutenke          #+#    #+#             */
/*   Updated: 2021/04/18 19:34:15 by rdutenke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

void	world(t_world *w, t_object content)
{
	t_objects	*temp;

	w->has_light = false;
	w->lights = NULL;
	if (ft_lstsize_w(w->objects) == 0)
	{
		w->objects = ft_lstnew_w(content);
	}
	else
	{
		temp = w->objects;
		while (temp->next)
		{
			temp = temp->next;
		}
		temp->next = ft_lstnew_w(content);
	}
	w->num_objects = ft_lstsize_w(w->objects);
}
