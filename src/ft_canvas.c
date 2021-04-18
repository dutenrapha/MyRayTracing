/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_canvas.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdutenke <rdutenke@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 00:32:18 by rdutenke          #+#    #+#             */
/*   Updated: 2021/04/19 00:18:51 by rdutenke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

void	ft_canvas(t_config *config, t_world w)
{
	t_canvas	c;
	t_cameras	*camera;

	if (config->c_cameras == NULL)
	{
		c = canvas(config->r_x, config->r_y);
		cv(&config->c_canvas, c);
	}
	else
	{
		camera = config->c_cameras;
		while (camera->next)
		{
			c = render(camera->content, w);
			cv(&config->c_canvas, c);
			camera = camera->next;
		}
		c = render(camera->content, w);
		cv(&config->c_canvas, c);
	}
}
