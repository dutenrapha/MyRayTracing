/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdutenke <rdutenke@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 00:49:43 by rdutenke          #+#    #+#             */
/*   Updated: 2021/04/19 00:49:55 by rdutenke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/header.h"

int	main(int argc, char *argv[])
{
	t_config	config;
	t_world		w;

	if (ft_prevalidation(argc, argv))
	{
		return (0);
	}
	config.save = ft_checksave(argc);
	if (!ft_readfile(&config, argv))
	{
		return (0);
	}
	if (config.o_objects != NULL)
	{
		ft_init_world(&w, config);
	}
	ft_canvas(&config, w);
	ft_render_camera(config, config.save);
	return (0);
}
