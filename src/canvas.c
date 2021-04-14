/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canvas.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdutenke <rdutenke@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 20:09:32 by rdutenke          #+#    #+#             */
/*   Updated: 2021/04/14 20:13:00 by rdutenke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

t_canvas	canvas(int w, int h)
{
	t_canvas	c;
	t_color		black;
	int			i;
	int			j;

	i = -1;
	black = color(0, 0, 0);
	c.width = w;
	c.height = h;
	c.pixel = (t_color**)malloc(sizeof(t_color*) * h);
	while (++i < h)
	{
		c.pixel[i] = (t_color *)malloc(sizeof(t_color) * w);
	}
	i = -1;
	while (++i < h)
	{
		j = -1;
		while (++j < w)
		{
			c.pixel[i][j] = black;
		}
	}
	return (c);
}
