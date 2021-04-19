/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_world.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdutenke <rdutenke@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 22:33:38 by rdutenke          #+#    #+#             */
/*   Updated: 2021/04/19 03:45:12 by rdutenke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

static void	ft_aux(t_list **xs, t_list *init)
{
	if (init != NULL)
	{
		if (*xs == NULL)
		{
			*xs = init;
		}
		else
			ft_lstadd_back(&*xs, init);
	}
}

t_list		*intersect_world(t_world w, t_ray r)
{
	t_list		*xs;
	t_list		*init;
	t_objects	*temp;

	xs = NULL;
	init = NULL;
	temp = w.objects;
	while (temp->next)
	{
		init = intersect(temp->content, r);
		if (init != NULL)
		{
			if (xs == NULL)
				xs = init;
			else
				ft_lstadd_back(&xs, init);
		}
		temp = temp->next;
	}
	init = intersect(temp->content, r);
	ft_aux(&xs, init);
	bubblesort(&xs);
	return (xs);
}
