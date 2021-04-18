/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_img.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdutenke <rdutenke@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 01:53:34 by rdutenke          #+#    #+#             */
/*   Updated: 2021/04/19 00:20:23 by rdutenke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

static void	ft_set(t_par5 p, t_canvas c, t_imgg **img, t_config *config)
{
	int		x;
	int		y;
	t_color	cc;
	t_color	cor;
	t_data	im;

	im.img = mlx_new_image(config->mlx, p.xx, p.yy);
	im.addr = mlx_get_data_addr(im.img, &im.bits_per_pixel, &im.line_length,
									&im.endian);
	y = 0;
	while (y < p.yy - 1)
	{
		x = 0;
		while (x < p.xx - 1)
		{
			cor = c.pixel[y][x];
			cc.red = ft_resize_color(cor.red);
			cc.green = ft_resize_color(cor.green);
			cc.blue = ft_resize_color(cor.blue);
			my_mlx_pixel_put(&im, x, y, create_rgb(cc.red, cc.green, cc.blue));
			x++;
		}
		y++;
	}
	n_img(img, im);
}

void		ft_set_img(t_config *config)
{
	t_cv	*temp;
	t_par5	p;

	p.xx = config->r_x;
	p.yy = config->r_y;
	temp = config->c_canvas;
	while (temp->next)
	{
		ft_set(p, temp->content, &config->img, config);
		temp = temp->next;
	}
	ft_set(p, temp->content, &config->img, config);
	config->img_init = config->img;
}
