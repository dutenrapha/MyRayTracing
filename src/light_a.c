/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdutenke <rdutenke@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 23:55:25 by rdutenke          #+#    #+#             */
/*   Updated: 2021/04/17 23:56:00 by rdutenke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

void	light_a(t_world *w, t_light light)
{
	t_lights	*temp;

	w->has_light = true;
	if (ft_lstsize_l(w->lights) == 0)
	{
		w->lights = ft_lstnew_l(light);
	}
	else
	{
		temp = w->lights;
		while (temp->next)
		{
			temp = temp->next;
		}
		temp->next = ft_lstnew_l(light);
	}
}
