/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_world.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdutenke <rdutenke@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 19:44:29 by rdutenke          #+#    #+#             */
/*   Updated: 2021/04/19 00:20:54 by rdutenke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

void	ft_init_world(t_world *w, t_config config)
{
	t_objects	*temp;
	t_lights	*temp_l;

	w->objects = NULL;
	w->lights = NULL;
	temp = config.o_objects;
	while (temp->next)
	{
		world(w, temp->content);
		temp = temp->next;
	}
	world(w, temp->content);
	temp_l = config.l_lights;
	if (temp_l != NULL)
	{
		while (temp_l->next)
		{
			light_a(w, temp_l->content);
			temp_l = temp_l->next;
		}
		light_a(w, temp_l->content);
	}
	w->ambient = config.a_color;
}
