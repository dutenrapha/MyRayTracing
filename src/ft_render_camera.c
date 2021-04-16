/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render_camera.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdutenke <rdutenke@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 01:20:53 by rdutenke          #+#    #+#             */
/*   Updated: 2021/04/17 01:22:53 by rdutenke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

static int		closew(int keycode, t_config *config)
{
	if (keycode == 0xFF1B)
	{
		mlx_destroy_window(config->mlx, config->win);
		exit(0);
	}
	return (0);
}

static int		next_cam(int keycode, t_config *config)
{
	if (keycode == 0xFF1B)
		exit(0);
	if (keycode != 0x20)
		return (0);
	if (config->img->next)
	{
		config->img = config->img->next;
		mlx_put_image_to_window(
				config->mlx, config->win, config->img->content.img, 0, 0);
	}
	else
	{
		config->img = config->img_init;
		mlx_put_image_to_window(
				config->mlx, config->win, config->img->content.img, 0, 0);
	}
	return (1);
}

static int		expose_hook(t_config *config)
{
	return (mlx_put_image_to_window(config->mlx,
									config->win,
									config->img->content.img,
									0, 0));
}

void			ft_render_camera(t_config config, bool save)
{
	config.mlx = mlx_init();
	config.win = mlx_new_window(config.mlx, config.R_x, config.R_y, "miniRT");
	if (config.c_cameras == NULL)
	{
		ft_printf("Voce nao definiou nenhuma camera!\n");
	}
	if (config.o_objects == NULL)
	{
		ft_printf("Voce nao definiou nenhum objeto!\n");
	}
	ft_setImg(&config);
	if (save)
	{
		ft_save(config);
	}
	else
	{
		mlx_hook(config.win, 33, 1L << 17, closew, &config);
		mlx_hook(config.win, 2, 1, next_cam, &config);
		mlx_expose_hook(config.win, expose_hook, &config);
		mlx_loop(config.mlx);
	}
}
